#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;
static FILE *pita;
static int retval;

void START(FILE *input) {
    /* Mesin siap dioperasikan. Pita disiapkan ... */
    /* Algoritma */
    pita = input;
    ADV();
}

void ADV() {
    /* Pita dimajukan satu karakter. ... */
    /* Algoritma */
    retval = fscanf(pita, "%c", &currentChar);

}

char GetCC() {
    /* Mengirimkan currentChar */
    /* Algoritma */
    return currentChar;
}

boolean IsEOP() {
    /* Mengirimkan true jika currentChar = MARK */
    /* Algoritma */
    return EOP;
}

boolean IsWhitespace() {
    return (currentChar == ' ') || (currentChar == '\t') || (currentChar == '\n') || (currentChar == '\r');
}