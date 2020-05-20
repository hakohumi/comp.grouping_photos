#define _CRT_SECURE_NO_WARNINGS
#include "ControlFile.h"

#include <Windows.h>
#include <assert.h>
#include <errno.h>
#include <io.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#include "DEBUG.h"

#define DEBUG

/* -------------------------------------------------- */
// static関数用プロトタイプ宣言
/* -------------------------------------------------- */

static int copyFilefopen(FileName i_filePath, FileName o_filePath);

static char *getFileName(FileName i_filePath);

//* -------------------------------------------------- */

char *InputFile(FileName i_filePath) {
#ifdef DEBUG
    printf("\nInputFile() in\n\n");
#endif
    printf("入力ディレクトリ：%s\n", i_filePath);
    printf("myGetFileSize() = %d\n", myGetFileSize(i_filePath));
    printf("fileName = %s\n", getFileName(i_filePath));

    // ファイル名変更テスト
    // rename(i_filePath, "grouping_photos/resource/test2.txt");

#ifdef DEBUG
    printf("\nInputFile() out\n");
#endif

    return getFileName(i_filePath);
}

void MyCopyFile(FileName i_filePath, FileName o_filePath) {
    bool l_endFlag = FALSE;

#ifdef DEBUG
    printf("\nControlFile.CopyFile() start\n\n");
    printf("i_filePath = %s\n", i_filePath);
    printf("o_filePath = %s\n", o_filePath);
#endif

    l_endFlag = copyFilefopen(i_filePath, o_filePath);

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
static int copyFilefopen(FileName i_filePath, FileName o_filePath) {
    FILE *l_src = NULL;
    FILE *l_dest = NULL;
    int l_errSrc = 0;
    int l_errDest = 0;
    int result = 0;

#ifdef DEBUG
    printf("\nControlFile.copyFilefopen() start\n\n");
#endif

    if (strcmp(i_filePath, o_filePath) == 0) {
        printf("入力と出力のファイルパスが一緒です。");
        return 0;
    }

    result = 1;

    l_errSrc = fopen_s(&l_src, i_filePath, "rb");
    // 今回は、コピー先のファイルはないものとする
    l_errDest = fopen_s(&l_dest, o_filePath, "wb");

    if (l_dest == NULL) {
        printf("l_dest = null\n");
    }

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
        } else {
            printf("l_dest close\n");
        }
    }

    if (l_src != NULL) {
        if (fclose(l_src) == EOF) {
            result = 0;
        } else {
            printf("l_src close\n");
        }
    }

#ifdef DEBUG
    printf("\nControlFile.copyFilefopen() end\n\n");
#endif

    return result;
}

// ファイルのサイズを取得する関数
// 引数：ファイルポインタ
// 戻り値：ファイルサイズ(int)
static int myGetFileSize(FileName i_filePath) {
    struct stat l_stBuf;
    int l_fSize = 0;
    FILE *fp;
    // errno_t fError;
    int fError;

#ifdef DEBUG
    printf("\nGetFileSize() start\n");
    printf("FileName = %s\n", i_filePath);
#endif

    fError = fopen_s(&fp, i_filePath, "rb");
    // fp = fopen(i_filePath, "r");

    if (fp == NULL) {
        printf("fp NULL\n");
        printf("fError = %d\n", fError);
    }

    /* ファイルサイズを調査 */
    if (stat(i_filePath, &l_stBuf) == -1) {
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

void structured_path(FileName i_filePath) {}

char *getFileName(FileName i_filePath) {
    // 入力されたフルファイルパスから、
    // 後ろからスラッシュまでの文字列を取得する
    return strrchr(i_filePath, '\\');
}