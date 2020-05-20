#include "ControlFIle.h"

#include <Windows.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "DEBUG.h"

#define DEBUG

//* -------------------------------------------------- */

void InputFile(FileName i_fileName) {
#ifdef DEBUG
    printf("\nInputFile() in\n\n");
#endif
    printf("入力ディレクトリ：%s\n", i_fileName);
    printf("GetFileSize() = %d\n", myGetFileSize(i_fileName));

    // ファイル名変更テスト
    // rename(i_fileName, "grouping_photos/resource/test2.txt");

#ifdef DEBUG
    printf("\nInputFile() out\n");
#endif
}

void MyCopyFile(FileName i_fileName, FileName o_fileName) {
    bool l_endFlag = FALSE;

#ifdef DEBUG
    printf("\nControlFile.CopyFile() start\n\n");
    printf("i_fileName = %s\n", i_fileName);
    printf("o_fileName = %s\n", o_fileName);
#endif

    // l_endFlag = CopyFile((LPCTSTR)i_fileName, (LPCTSTR)o_fileName, TRUE);
    l_endFlag = copyFilefopen(i_fileName, o_fileName);

    // エラーだったら
    if (l_endFlag == FALSE) {
        printf("CopyFile() Copy error\n");
    }

#ifdef DEBUG
    printf("\nControlFile.CopyFile() end\n");
#endif
    return;
}

// 戻り値：1 成功, 0 失敗
static int copyFilefopen(FileName i_fileName, FileName o_fileName) {
    FILE *l_src = NULL;
    FILE *l_dest = NULL;
    int l_errSrc = 0;
    int l_errDest = 0;
    int result = 0;

#ifdef DEBUG
    printf("\nControlFile.copyFilefopen() start\n\n");
#endif

    if (strcmp(i_fileName, o_fileName) == 0) {
        printf("入力と出力のファイルパスが一緒です。");
        return 0;
    }

    result = 1;

    l_errSrc = fopen_s(&l_src, i_fileName, "rb");
    // 今回は、コピー先のファイルはないものとする
    l_errDest = fopen_s(&l_dest, o_fileName, "wb");

    if ((l_errSrc != 0) || (l_errDest != 0)) {
        printf("読み込みエラー\n");
        result = 0;
    }

    if (result != 0) {
        for (;;) {
            char c;

            // 1バイト読み込む
            // もしfread()がエラーの場合
            if (fread(&c, sizeof(c), 1, l_src) < 1) {
                // 終端の場合
                if (feof(l_src)) {
                    break;
                    // 終端以外でエラーの場合
                } else {
                    result = 0;
                    break;
                }
            }

            if (fwrite(&c, sizeof(c), 1, l_dest) < 1) {
                result = 0;
                break;
            }
        }
    }

    if (l_dest != NULL) {
        if (fclose(l_dest) == EOF) {
            result = 0;
        }
    }

    if (l_src != NULL) {
        if (fclose(l_src) == EOF) {
            result = 0;
        }
    }

    return result;

#ifdef DEBUG
    printf("\nControlFile.copyFilefopen() end\n\n");
#endif
}

// ファイルのサイズを取得する関数
// 引数：ファイルポインタ
// 戻り値：ファイルサイズ(int)
static int myGetFileSize(FileName i_fileName) {
    struct stat l_stBuf;
    int l_fSize = 0;
    FILE *fp;
    // errno_t fError;
    int fError;

#ifdef DEBUG
    printf("\nGetFileSize() start\n");
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
    printf("\nGetFileSize end\n\n");
#endif

    return l_fSize;
}

// ファイルの名前を変更する
// int RenameFileName(FileName i_oldFileName, FileName i_)