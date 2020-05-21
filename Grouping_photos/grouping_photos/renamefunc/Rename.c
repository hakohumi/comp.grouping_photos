#include "Rename.h"

#include <io.h>
#include <time.h>

void GetFileCreatedTime(FileName i_filePath, char *o_fileName) {
    struct _finddata_t l_fData;
    struct tm l_createTime;
    // char l_yearChar[5];
    // char l_monthChar[3];
    // char l_dayChar[3];
    int error = 0;

    // 20200520_001
    char l_formatedName[13];
    int l_num = 0;

    int fh;

    int l_result = 1;

    fh = _findfirst(i_filePath, &l_fData);
    if (fh == -1) {
        l_result = 0;
    }
    // printf("作成    : %s", asctime(localtime(&l_fData.time_create)));
    // printf("time = %s\n", ctime(&l_fData.time_create));
    if (l_result == 1) {
        error = localtime_s(&l_createTime, &l_fData.time_create);

        printf("error = %d\n", error);

        printf("create_day = %d\n", l_createTime.tm_mday);
        printf("create_month = %d\n", l_createTime.tm_mon + 1);
        printf("create_year = %d\n", l_createTime.tm_year + 1900);
        // _itoa_s(l_createTime->tm_mday, l_monthChar, 3, 10);
        // printf("time string = %s\n", l_monthChar);

        // _itoa_s((l_createTime->tm_year + 1900), l_yearChar, 5, 10);
        // _itoa_s(l_createTime->tm_mon + 1, l_monthChar, 3, 10);
        // printf("l_monthChar = %s\n", l_monthChar);
        // _itoa_s(l_createTime->tm_mday, l_dayChar, 3, 10);

        // sprintf_s(l_formatedName, 13, "%s%s%s_%03d", l_yearChar, l_monthChar,
        //           l_dayChar, l_num);
        sprintf_s(l_formatedName, 13, "%04d%02d%02d_%03d",
                  l_createTime.tm_year + 1900, l_createTime.tm_mon + 1,
                  l_createTime.tm_mday, l_num);
        printf("l_formatedName = %s\n", l_formatedName);

        // strncpy_s(o_fileName, 13, l_formatedName, 13);
        strcpy_s(o_fileName, 13, l_formatedName);
        _findclose(fh);
    }
}