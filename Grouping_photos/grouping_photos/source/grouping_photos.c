#include <stdio.h>
#include <stdlib.h>

#include "InputFile.h"

// https://programming.pc-note.net/c/file7.html

int main()
{
    printf("group_photo start\n");

    // 写真ファイルの入ったフォルダの入力
    InputFile();

    // 出力ディレクトリへ写真ファイルのコピー

    system("dir");

    // ファイルのリネーム

    // ファイルパスの構造化

    return 0;
}