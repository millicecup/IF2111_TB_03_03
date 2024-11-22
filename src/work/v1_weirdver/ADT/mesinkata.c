#include "mesinkata.h"
#include <stdio.h>
#include <string.h>

void ReadInput(char *input) {
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = '\0';
}
