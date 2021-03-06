﻿#include <io.h>
#include <stdio.h>
#include <string.h>

#define DEBUG
#define FILE_NAME_MAX 260

#define EXT_NUM 5
#define EXT_LEN 5

int isCorrectExt(const char* i_ext);

static char ext[EXT_NUM][EXT_LEN] = {".png", ".jpg", ".txt", ".PNG", ".JPG"};

// 引数1：ディレクトリパス
// 引数2: カウント回数
// 引数3：ファイルパスを格納する変数ポインタ
int ScanFile(char* i_dir, int i_countFile, char* i_fileName) {
    struct _finddata_t l_fData;
    int fh;
    int l_countFile = 0;
    char l_path[FILE_NAME_MAX];

    if ((i_fileName == NULL) && (i_countFile != NULL)) {
        return 0;
    }

    sprintf_s(l_path, FILE_NAME_MAX, "%s/*.*", i_dir);
    if ((fh = _findfirst(l_path, &l_fData)) == -1) return;
    do {
        sprintf_s(l_path, FILE_NAME_MAX, "%s/%s", i_dir, l_fData.name);
        if (l_fData.attrib & _A_SUBDIR) {  // ディレクトリ
            if (strcmp(l_fData.name, ".") != 0 && strcmp(l_fData.name, "..") != 0) {
                l_countFile += ScanFile(l_path, i_countFile, i_fileName);
            }     // カレントディレクトリと親ディレクトリは除外する
        } else {  // ファイル
            //もし、対象の拡張子を持ったファイルを見つけたら
            if (isCorrectExt(strrchr(l_fData.name, '.')) != 0) {
                l_countFile++;

                if (i_countFile != NULL) {
                    // 指定回数分検索し終えたら、
                    if (l_countFile == i_countFile) {
                        sprintf_s(i_fileName, FILE_NAME_MAX, "%s/%s", i_dir, l_fData.name);
                        printf("見つけた！\n");
                        return l_countFile;
                    }
                }
            }
#ifdef DEBUG
            printf("filepath = %s%s\n", i_dir, l_fData.name);
#endif
        }
    } while ((_findnext(fh, &l_fData) == 0));
    _findclose(fh);

    return l_countFile;
}

// int ScanNumFile(char* i_dir) {
//     struct _finddata_t l_fData;
//     int fh;
//     int l_count;
//     char l_path[FILE_NAME_MAX];

//     l_count = 0;

//     sprintf_s(l_path, FILE_NAME_MAX, "%s/*.*", i_dir);
//     if ((fh = _findfirst(l_path, &l_fData)) == -1) return -1;
//     do {
//         sprintf_s(l_path, FILE_NAME_MAX, "%s/%s", i_dir, l_fData.name);
//         if (l_fData.attrib & _A_SUBDIR) {  // ディレクトリ
//             if (strcmp(l_fData.name, ".") != 0 &&
//                 strcmp(l_fData.name, "..") != 0) {
//                 l_count += ScanNumFile(l_path);
//             }  // カレントディレクトリと親ディレクトリは除外する
//         } else {  // ファイル
//             //もし、対象の拡張子を持ったファイルを見つけたら
//             if (isCorrectExt(strrchr(l_fData.name, '.')) != 0) {
//                 l_count++;
//             }
//         }
//     } while (_findnext(fh, &l_fData) == 0);
//     _findclose(fh);

//     return l_count;
// }

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