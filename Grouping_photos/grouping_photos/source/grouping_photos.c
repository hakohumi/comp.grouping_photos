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
    int l_result = 1;  // 処理正常フラグ 正常：1 エラー：0
    char l_convFileName[13];
    char i_filePath[N];
    char i_fileName[N];
    char o_directoryPath[N];
    char o_filePath[N];
    char o_fileName[N];

    memset(l_convFileName, 0, 13);
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

        // ファイルが存在するかどうか

        // 入力ファイルのファイル名取得

        if (GetFileName(i_filePath) == NULL) {
            printf("入力されたファイルパスがおかしいです。\n");
            l_result = 0;
        }

        if (l_result != 0) {
            strcpy(i_fileName, GetFileName(i_filePath));
            // strcpy(i_fileName, InputDebugFunc(i_filePath));

            /* -------------------------------------------------- */
            // ファイルのリネーム
            /* -------------------------------------------------- */

            GetFileCreatedTime(i_filePath, &l_convFileName);

            printf("変換後のファイル名 = %s\n", l_convFileName);
            printf("変換後のファイル拡張子 = %s\n", strrchr(i_fileName, '.'));

            // 出力ファイルパス 結合
            strcat(o_filePath, l_convFileName);
            sprintf_s(o_filePath, N, "%s\\%s%s", o_directoryPath,
                      l_convFileName, strrchr(i_fileName, '.'));

            printf("o_filePath = %s\n", o_filePath);

            // 出力先に同じ名前のファイルがないかどうか

            /* -------------------------------------------------- */
            // 出力ディレクトリへ写真ファイルのコピー
            /* -------------------------------------------------- */

            if (l_result == 1) {
                char *l_numChar;
                char l_wkChar[4];
                int l_numInt = 0;
                for (;;) {
                    if (existFile(o_filePath)) {
                        printf("かぶり\n");
                        l_numChar = strrchr(o_filePath, '_');
                        printf("l_num = %s\n", l_numChar);
                        l_numInt = atoi(l_numChar + 1);
                        printf("l_numInt = %d\n", l_numInt);

                        l_numInt++;
                        sprintf_s(l_wkChar, 4, "%03d", l_numInt);

                        *(l_numChar + 1) = *(l_wkChar);
                        *(l_numChar + 2) = *(l_wkChar+1);
                        *(l_numChar + 3) = *(l_wkChar+2);
                        
                        // strcpy_s((l_numChar + 1), 4, l_wkChar);
                    } else {
                        printf("かぶり なし\n");
                        break;
                    }
                }

                MyCopyFile(i_filePath, o_filePath);
            }
        }

        /* -------------------------------------------------- */
        // ループ開始 準備処理
        /* -------------------------------------------------- */

        memset(i_filePath, 0, N);

        l_result = 1;
        printf("\n入力するファイルパスを入力してください\n");
        scanf_s("%s", &i_filePath, N);

        /* -------------------------------------------------- */
    }

    // ファイルパスの構造化

    return 0;
}