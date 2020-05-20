#include <stdio.h>
#include <stdlib.h>

#include "ControlFile.h"
#include "Rename.h"

// https://programming.pc-note.net/c/file7.html

#define N 260
#define CONV_NUM 100

int main() {
    int l_countLoop = 0;
    int l_countLoopBlock = 0;
    char l_fileName[13];
    char i_filePath[N];
    char i_fileName[N];
    char o_directoryPath[N];
    char o_filePath[N];
    char o_fileName[N];

    memset(l_fileName, 0, 13);
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

        // 出力先パスとファイル名を結合
        strcpy(o_filePath, o_directoryPath);
        strcat(o_filePath, i_fileName);

        printf("o_filePath = %s\n", o_filePath);

        /* -------------------------------------------------- */
        // ファイルのリネーム
        /* -------------------------------------------------- */

        getFileCreateTime(o_filePath, &l_fileName);

        printf("変換後の名前%s\n", l_fileName);

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