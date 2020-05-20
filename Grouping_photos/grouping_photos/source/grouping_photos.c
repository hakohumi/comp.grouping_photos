#include <stdio.h>
#include <stdlib.h>

#include "ControlFile.h"

// https://programming.pc-note.net/c/file7.html

int main()
{
    const char* i_fileName = "grouping_photos/resource/in_test.txt";
    printf("group_photo start\n");

    // 1つの写真ファイルの入力
    InputFile(i_fileName);

    // 出力ディレクトリへ写真ファイルのコピー
    //CopyFile();

    // ファイルのリネーム

    // ファイルパスの構造化

    return 0;
}