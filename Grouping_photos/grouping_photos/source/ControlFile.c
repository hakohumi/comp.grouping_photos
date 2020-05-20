#include "ControlFIle.h"

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "DEBUG.h"

#define DEBUG

//* -------------------------------------------------- */

void InputFile(FileName i_fileName) {
    printf("\nInputFile() in\n");

    printf("入力ディレクトリ：%s\n", i_fileName);
    printf("GetFileSize() = %d\n", GetFileSize(i_fileName));

    // ファイル名変更テスト
    // rename(i_fileName, "grouping_photos/resource/test2.txt");

#ifdef DEBUG
    printf("\nInputFile() out\n");
#endif
}

void CopyFile(FileName i_fileName, FileName o_fileName) { return; }

// ファイルのサイズを取得する関数
// 引数：ファイルポインタ
// 戻り値：ファイルサイズ(int)
int GetFileSize(FileName i_fileName) {
    struct stat l_stBuf;
    int l_fSize = 0;
    FILE* fp;
    // errno_t fError;
    int fError;

#ifdef DEBUG
    printf("GetFileSize start\n");
    printf("FileName = %s\n", i_fileName);
#endif

    fError = fopen_s(&fp, i_fileName, "r");
    // fp = fopen(i_fileName, "r");

    if (fp == NULL) {
        printf("fp NULL\n");
        printf("fError = %d\n", fError);
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
// int RenameFileName(FileName i_oldFileName, FileName i_)