﻿#include <stdio.h>
#include <stdlib.h>

#include "ControlFile.h"
#include "Directory.h"

// https://programming.pc-note.net/c/file7.html

#define FILE_NAME_MAX 260
#define CONV_NUM 100

int main() {
    int l_countLoop = 0;
    int l_countLoopBlock = 0;
    FileName i_fileName = "grouping_photos/resource/in_test.txt";
    FileName o_fileName = "grouping_photos/resource/in_test2.txt";
    char l_fileName[FILE_NAME_MAX];
    char *l_filePath[CONV_NUM];

    memset(l_fileName, 0, FILE_NAME_MAX);
    memset(l_filePath, 0, sizeof(l_filePath));

    printf("group_photo start\n");

    // 入力ディレクトリの検索、対象写真ファイル数取得
    // l_countLoop = ScanNumFile("C:/Users/fuminori.hakoishi/Desktop");
    l_countLoop = ScanFile("C:/Users/fuminori.hakoishi/Desktop", NULL, NULL);
    printf("num = %d\n", l_countLoop);

    // テスト
    printf("ScanFile() = %d\n", ScanFile("C:/Users/fuminori.hakoishi/Desktop", 2, &l_fileName));
    printf("scan filepath = %s i = %d\n", l_fileName, l_countLoop);

    // ファイル100個単位で何ブロック分あるか
    if (l_countLoop > 100) {
        l_countLoopBlock = (int)(l_countLoop / 100);
        l_countLoop %= 100;
    }

    do {
        for (; l_countLoop > 0; l_countLoop--) {
            // 各写真ファイルパス取得、コピー実行
            // printf("scanfilename = %s i =
            // %d\n",ScanFile("C:/Users/fuminori.hakoishi/Desktop", l_countLoop,
            // &l_fileName),l_countLoop);

#ifdef DEBUG
            printf("l_countLoop = %d\n", l_countLoop);
#endif
        }
#ifdef DEBUG
        printf("l_countLoopBlock = %d\n", l_countLoopBlock);
#endif

        l_countLoop = 100;
        l_countLoopBlock--;
    } while (l_countLoopBlock > 0);

    // 1つの写真ファイルの入力
    // InputFile(i_fileName);

    // 出力ディレクトリへ写真ファイルのコピー
    // MyCopyFile(i_fileName, o_fileName);

    // ファイルのリネーム

    // ファイルパスの構造化

    return 0;
}