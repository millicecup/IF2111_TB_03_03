#include <stdio.h>
#include "../boolean.h"
#include "mesinkarakter.h"
/*
gcc mesinkarakter.c driver.c
*/
int main() {
    START(stdin);
    while (!IsEOP()) {
        printf("%c", GetCC());
        ADV();
        if (IsWhitespace()) {
            printf("\n");
            EOP = true;
        }
    }
    return 0;
}
