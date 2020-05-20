#include <io.h>
#include <stdio.h>
#include <string.h>

void ScanFile(char* dir) {
#define N 260
    struct _finddata_t fdata;
    int fh;
    char path[N];

    sprintf_s(path, N, "%s/*.*", dir);
    if ((fh = _findfirst(path, &fdata)) == -1) return;
    do {
        sprintf_s(path, N, "%s/%s", dir, fdata.name);
        if (fdata.attrib & _A_SUBDIR) {  // ディレクトリ
            if (strcmp(fdata.name, ".") != 0 && strcmp(fdata.name, "..") != 0) {
                ScanFile(path);
            }  // カレントディレクトリと親ディレクトリは除外する
        } else {  // ファイル
            printf("filename = %s\n", fdata.name);
        }
    } while (_findnext(fh, &fdata) == 0);
    _findclose(fh);
}
