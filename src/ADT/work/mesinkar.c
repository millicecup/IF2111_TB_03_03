#include <stdio.h>
#include "mesinkar.h"

char CC;
boolean EOP;

static FILE *pita;
static int retval;

void TASTART(void) {
    pita = stdin;
    TAADV();
}

void TAADV(void) {
    retval = fscanf(pita, "%c", &CC);
    EOP = (retval == EOF);
    if (EOP) {
        fclose(pita);
    }
}

char TAGetCC(void) {
    return CC;
}

boolean TAIsEOP(void) {
    return EOP;
}

boolean TAIsWhitespace(void) {
    return (CC == ' ') || (CC == '\t') || (CC == '\n') || (CC == '\r');
}