#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#include "DEBUG.h"

// ファイルのサイズを取得する関数
// 引数：ファイルポインタ
// 戻り値：ファイルサイズ(int)
int GetFileSize(char *i_fileName) {
    struct stat l_stBuf;
    int l_fSize = 0;
    FILE *fp;

#ifdef DEBUG
    printf("GetFileSize start\n");
    printf("FileName = %s\n", i_fileName);
#endif

    // fError = fopen_s(&fp, i_fileName, "r");
    fp = fopen(i_fileName, "r");

    if (fp == NULL) {
        printf("fp NULL\n");
    }

    /* ファイルサイズを調査 */
    if (stat(i_fileName, &l_stBuf) == -1) {
        printf(" stat() == -1\n");
        return -1;
    }

    l_fSize = l_stBuf.st_size;

    fclose(fp);

#ifdef DEBUG
    printf("GetFileSize end\n\n");
#endif

    return l_fSize;
}


// ファイルの名前を変更する
//int RenameFileName(const char* i_oldFileName, const char* i_)