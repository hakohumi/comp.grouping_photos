﻿#include <stdio.h>
#include <stdlib.h>

#include "ControlFile.h"
#include "Directory.h"

// https://programming.pc-note.net/c/file7.html

#define N 260

int main() {
    int l_countLoop = 0;
    int l_countLoopBlock = 0;
    FileName i_fileName = "grouping_photos/resource/in_test.txt";
    FileName o_fileName = "grouping_photos/resource/in_test2.txt";
    char l_fileName[N];

    printf("group_photo start\n");

    // 入力ディレクトリの検索、対象写真ファイル数取得
    // l_countLoop = ScanNumFile("C:/Users/fuminori.hakoishi/Desktop");
    l_countLoop = ScanFile("C:/Users/fuminori.hakoishi/Desktop", NULL,NULL);

    printf("num = %d\n", l_countLoop);

    if (l_countLoop > 100) {
        // ファイル100個単位で何ブロック分あるか
        l_countLoopBlock = (int)(l_countLoop / 100);
        l_countLoop %= 100;
    }

    do {
        for (; l_countLoop > 0; l_countLoop--) {
            // 各写真ファイルパス取得、コピー実行
            // ScanFile("C:/Users/fuminori.hakoishi/Desktop", , &l_fileName);

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