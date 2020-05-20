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
    char o_fileName[N];

    memset(l_fileName, 0, 13);
    memset(i_filePath, 0, N);
    memset(i_fileName, 0, N);
    memset(o_directoryPath, 0, N);
    memset(o_fileName, 0, N);

    printf("group_photo start\n");

    printf("出力するディレクトリパスを入力してください\n");
    scanf_s("%s", &o_directoryPath, N);
    scanf_s("%s", &o_directoryPath, N);

    printf("入力するファイルパスを入力してください\n");
    scanf_s("%s", &i_filePath, N);

    while (strncmp(i_filePath, "end", 3) != 0) {
        printf("%s\n", i_filePath);

        // 入力パス

        // 1つの写真ファイルの入力
        InputFile(i_filePath);

        // 出力ディレクトリへ写真ファイルのコピー
        MyCopyFile(i_filePath, o_fileName);

        // ファイルのリネーム
        getFileCreateTime(o_fileName, &l_fileName);

        printf("%s \n", l_fileName);

        memset(i_filePath, 0, N);

        printf("入力するファイルパスを入力してください\n");
        scanf_s("%s", &i_filePath, N);
    }

    // ファイルパスの構造化

    return 0;
}