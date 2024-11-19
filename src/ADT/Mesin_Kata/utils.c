#include <stdio.h>
#include "utils.h"
#include "mesinkata.h"
#include "mesinkarakterv2.h"


// Compare two strings
int str_compare(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) return 0;
        str1++;
        str2++;
    }
    return *str1 == '\0' && *str2 == '\0';
}

// Copy a string
void str_copy(char *dest, const char *src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

// Get the length of a string
int str_length(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}


static FILE *tape;

void STARTFILE(FILE *file) {
    tape = file;
    ADV();
}
