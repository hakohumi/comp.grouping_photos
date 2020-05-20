#include <io.h>
#include <stdio.h>
#include <string.h>

#define N 260

#define EXT_NUM 3
#define EXT_LEN 4

int isCorrectExt(const char* i_ext);

static char ext[EXT_NUM][EXT_LEN] = {
    ".png",
    ".jpg",
    ".txt"
};



void ScanFile(char* i_dir) {
    struct _finddata_t l_fData;
    int fh;
    char l_path[N];

    sprintf_s(l_path, N, "%s/*.*", i_dir);
    if ((fh = _findfirst(l_path, &l_fData)) == -1) return;
    do {
        sprintf_s(l_path, N, "%s/%s", i_dir, l_fData.name);
        if (l_fData.attrib & _A_SUBDIR) {  // ディレクトリ
            if (strcmp(l_fData.name, ".") != 0 &&
                strcmp(l_fData.name, "..") != 0) {
                ScanFile(l_path);
            }  // カレントディレクトリと親ディレクトリは除外する
        } else {  // ファイル

            //if (ext ==) printf("filename = %s\n", l_fData.name);
            printf("file_ext = %s\n", strrchr(l_fData.name, '.'));
            printf("filepath = %s%s\n", i_dir, l_fData.name);
        }
    } while (_findnext(fh, &l_fData) == 0);
    _findclose(fh);
}

int ScanNumFile(char* i_dir) {
    struct _finddata_t l_fData;
    int fh;
    int l_count;
    char l_path[N];

    l_count = 0;

    sprintf_s(l_path, N, "%s/*.*", i_dir);
    if ((fh = _findfirst(l_path, &l_fData)) == -1) return -1;
    do {
        sprintf_s(l_path, N, "%s/%s", i_dir, l_fData.name);
        if (l_fData.attrib & _A_SUBDIR) {  // ディレクトリ
            if (strcmp(l_fData.name, ".") != 0 &&
                strcmp(l_fData.name, "..") != 0) {
                l_count += ScanNumFile(l_path);
            }  // カレントディレクトリと親ディレクトリは除外する
        } else {  // ファイル
            //もし、対象の拡張子を持ったファイルを見つけたら
            if (isCorrectExt(strrchr(l_fData.name, '.')) != 0) {
                l_count++;
            }
        }
    } while (_findnext(fh, &l_fData) == 0);
    _findclose(fh);

    return l_count;
}

// 拡張子が検索対象に含まれているか
int isCorrectExt(const char* i_ext) {
    int i;
    int result = 0;

    if (i_ext == NULL) {
        return 0;
    }

    for (i = 0; i < EXT_NUM; i++) {
        if (strncmp(ext[i], i_ext, EXT_LEN) == 0) {
            result = 1;
            break;
        }
    }

    return result;
}