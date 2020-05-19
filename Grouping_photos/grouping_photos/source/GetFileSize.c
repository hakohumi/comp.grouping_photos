#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#include "DEBUG.h"

// ファイルのサイズを取得する関数
// 引数：ファイルポインタ
// 戻り値：ファイルサイズ(int)
int GetFileSize(char *FileName) {
    struct stat stbuf;
    int fsize = 0;
    FILE *fp;

#ifdef DEBUG
    printf("GetFileSize start\n");
    printf("FileName = %s\n", FileName);
#endif

    // fError = fopen_s(&fp, FileName, "r");
    fp = fopen(FileName, "r");

    if (fp == NULL) {
        printf("fp NULL\n");
    }

    /* ファイルサイズを調査 */
    if (stat(FileName, &stbuf) == -1) {
        printf(" stat() == -1\n");
        return -1;
    }

    fsize = stbuf.st_size;

    fclose(fp);

#ifdef DEBUG
    printf("GetFileSize end\n\n");
#endif

    return fsize;
}