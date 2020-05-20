#include <stdio.h>
#include <stdlib.h>

#include "ControlFile.h"

// https://programming.pc-note.net/c/file7.html

int main() {
    FileName i_fileName = "grouping_photos/resource/in_test.txt";
    FileName o_fileName = "grouping_photos/resource/in_test2.txt";
    printf("group_photo start\n");

    // 1つの写真ファイルの入力
    InputFile(i_fileName);

    // 出力ディレクトリへ写真ファイルのコピー
    MyCopyFile(i_fileName, o_fileName);

    // ファイルのリネーム

    // ファイルパスの構造化

    return 0;
}