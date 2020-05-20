#include <stdio.h>
#include <stdlib.h>

#include "ControlFile.h"

// https://programming.pc-note.net/c/file7.html

#define N 260
#define CONV_NUM 100

int main() {
    int l_countLoop = 0;
    int l_countLoopBlock = 0;
    FileName i_fileName = "grouping_photos/resource/in_test.txt";
    FileName i_filePath = "grouping_photos/resource/";
    FileName o_fileName = "grouping_photos/resource/in_test2.txt";
    FileName o_filePath = "grouping_photos/resource/";
    char l_fileName[13];
    char l_input[N];

    // memset(l_fileName, 0, N);

    printf("group_photo start\n");

    scanf_s("%s", &l_input, N);

    while (strncmp(l_input, "end", 3) != 0) {
        printf("%s\n", i_fileName);
        // 1つの写真ファイルの入力
        InputFile(i_fileName);

        // 出力ディレクトリへ写真ファイルのコピー
        MyCopyFile(i_fileName, o_fileName);

        // ファイルのリネーム
        getFileCreateTime(i_fileName, &l_fileName);

        printf("%s \n", l_fileName);
        memset(l_input, 0, N);
        scanf_s("%s", &l_input, N);
    }

    // ファイルパスの構造化

    return 0;
}