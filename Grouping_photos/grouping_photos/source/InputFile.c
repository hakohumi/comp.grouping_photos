﻿#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>
#include <errno.h>
#define DEBUG

#include "GetFileSize.h"

//* -------------------------------------------------- */
extern int errno;

void InputFile() {
    char* fileName = "in_test.txt";
#ifdef DEBUG
    printf("\nInputFile() in\n");
#endif

    printf("filename = %s\n", fileName);
    printf("GetFileSize() = %d\n", GetFileSize(fileName));

#ifdef DEBUG
    printf("\nInputFile() out\n");
#endif
}
