#include <stdio.h>
#define DEBUG

void InputFile() {
#ifdef DEBUG
    printf("\nInputFile() in\n");
#endif


#ifdef DEBUG
    printf("\nInputFile() out\n");
#endif
}