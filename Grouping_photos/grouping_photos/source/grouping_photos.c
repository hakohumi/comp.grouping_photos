﻿#include <stdio.h>
#include <stdlib.h>

#include "ControlFile.h"
#include "Rename.h"

// https://programming.pc-note.net/c/file7.html

#define N 260
#define CONV_NUM 100

int main() {
    int l_countLoop = 0;
    int l_countLoopBlock = 0;
    char l_convFileName[13];
    char i_filePath[N];
    char i_fileName[N];
    char o_directoryPath[N];
    char o_filePath[N];
    char o_fileName[N];

    memset(l_convFileName, 0, 13);
    memset(i_filePath, 0, N);
    memset(i_fileName, 0, N);
    memset(o_directoryPath, 0, N);
    memset(o_filePath, 0, N);
    memset(o_fileName, 0, N);

    printf("group_photo start\n");

    printf("出力するディレクトリパスを入力してください\n");
    scanf_s("%s", &o_directoryPath, N);

    printf("\n入力するファイルパスを入力してください\n");
    scanf_s("%s", &i_filePath, N);

    while (strncmp(i_filePath, "end", 3) != 0) {
        printf("\n入力ファイルパス = %s\n", i_filePath);

        // 入力パス

        // 1つの写真ファイルの入力
        // 入力ファイルのファイル名取得
        strcpy(i_fileName, InputFile(i_filePath));

        /* -------------------------------------------------- */
        // ファイルのリネーム
        /* -------------------------------------------------- */

        getFileCreateTime(i_filePath, &l_convFileName);

        printf("変換後のファイル名 = %s\n", l_convFileName);
        printf("変換後のファイル拡張子 = %s\n", strrchr(i_fileName, '.'));

        // 出力ファイルパス 結合
        strcat(o_filePath, l_convFileName);
        sprintf_s(o_filePath, N, "%s\\%s%s", o_directoryPath, l_convFileName,
                  strrchr(i_fileName, '.'));

        printf("o_filePath = %s\n", o_filePath);

        /* -------------------------------------------------- */
        // 出力ディレクトリへ写真ファイルのコピー
        /* -------------------------------------------------- */

        MyCopyFile(i_filePath, o_filePath);

        /* -------------------------------------------------- */

        memset(i_filePath, 0, N);

        printf("\n入力するファイルパスを入力してください\n");
        scanf_s("%s", &i_filePath, N);
    }

    // ファイルパスの構造化

    return 0;
}