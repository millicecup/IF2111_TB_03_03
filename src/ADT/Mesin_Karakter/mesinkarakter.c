/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkarakter.h"
#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START(FILE *input) {
       pita = input;
       ADV();
}

void ADV() {
       /* Pita dimajukan satu karakter.
          I.S. : Karakter pada jendela =
                 currentChar, currentChar != MARK
          F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
                 currentChar mungkin = MARK.
                       Jika  currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       retval = fscanf(pita, "%c", &currentChar);
       //printf("Advancing ke karakter: %c\n", currentChar);
}

void ADVFILE() {
       retval = fscanf(pita, "%c", &currentChar);
       if (feof(pita)){
              fclose(pita);
       }
}