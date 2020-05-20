#include <io.h>
#include <stdio.h>
#include <string.h>

void ScanFile(char* i_dir) {
#define N 260
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

            printf("filename = %s\n", l_fData.name);
            printf("file_ext = %s\n", strrchr(l_fData.name, '.'));
            printf("filepath = %s%s\n", i_dir, l_fData.name);
        }
    } while (_findnext(fh, &l_fData) == 0);
    _findclose(fh);
}
