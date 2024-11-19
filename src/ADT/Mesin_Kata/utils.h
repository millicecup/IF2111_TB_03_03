#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>

int str_length(const char *str);
/* mengembalikan panjang string
   I.S. : str terdefinisi
   F.S. : mengembalikan panjang str */
void str_copy(char *dest, const char *src);
/* mengcopy string src ke dest
   I.S. : src terdefinisi
   F.S. : dest berisi src */
int str_compare(const char *str1, const char *str2);
/* mengembalikan -1 jika str1 < str2, 0 jika str1 = str2, 1 jika str1 > str2
   I.S. : str1 dan str2 terdefinisi
   F.S. : mengembalikan -1 jika str1 < str2, 0 jika str1 = str2, 1 jika str1 > str2 */
static FILE *tape;

void STARTFILE(FILE *file) ;


#endif