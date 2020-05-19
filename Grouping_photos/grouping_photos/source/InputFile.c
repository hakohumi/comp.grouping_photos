#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>
#include <errno.h>
#define DEBUG

#include "GetFileInfo.h"

//* -------------------------------------------------- */

void InputFile()
{
    const char *i_fileName = "grouping_photos/resource/in_test.txt";

    printf("\nInputFile() in\n");

    printf("入力ディレクトリ：%s\n", i_fileName);
    printf("GetFileSize() = %d\n", GetFileSize(i_fileName));

    // ファイル名変更テスト
    //rename(i_fileName, "grouping_photos/resource/test2.txt");

#ifdef DEBUG
    printf("\nInputFile() out\n");
#endif
}
