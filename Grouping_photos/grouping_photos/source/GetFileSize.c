

#include <stdio.h>
#include <sys/stat.h>

#include "DEBUG.h"

// ファイルのサイズを取得する関数
// 引数：ファイルポインタ
// 戻り値：ファイルサイズ(int)
int GetFileSize(char *FileName) {
    struct stat stbuf;
    int fsize = 0;
    int fError = 0;

    FILE *fp;

#ifdef DEBUG
    printf("GetFileSize start\n");
#endif

    fError = fopen_s(&fp, &FileName, "r");

    printf("fError = %d\n", fError);

    /* ファイルサイズを調査 */
    if (stat(FileName, &stbuf) == -1) {
        return -1;
    }

    fsize = stbuf.st_size;

    fclose(fp);

#ifdef DEBUG
    printf("GetFileSize end\n\n");
#endif

    return fsize;
}