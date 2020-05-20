#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "DEBUG.h"
#include "ControlFIle.h"

#define DEBUG

//* -------------------------------------------------- */

void InputFile(const char *i_fileName) {

    printf("\nInputFile() in\n");

    printf("入力ディレクトリ：%s\n", i_fileName);
    printf("GetFileSize() = %d\n", GetFileSize(i_fileName));

    // ファイル名変更テスト
    // rename(i_fileName, "grouping_photos/resource/test2.txt");

#ifdef DEBUG
    printf("\nInputFile() out\n");
#endif
}

void CopyFile(const char *i_fileName, const char *o_fileName) { return; }

// ファイルのサイズを取得する関数
// 引数：ファイルポインタ
// 戻り値：ファイルサイズ(int)
int GetFileSize(const char *i_fileName) {
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
// int RenameFileName(const char* i_oldFileName, const char* i_)