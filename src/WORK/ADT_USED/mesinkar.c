#include <stdio.h>
#include "mesinkar.h"

char CC;
boolean EOP;

static FILE *pita;
static int retval;

void START(void) {
    pita = stdin;
    ADV();
}

void ADV(void) {
    retval = fscanf(pita, "%c", &CC);
    EOP = (retval == EOF);
    if (EOP) {
        fclose(pita);
    }
}

char GetCC(void) {
    return CC;
}

boolean IsEOP(void) {
    return EOP;
}

boolean IsWhitespace(void) {
    return (CC == ' ') || (CC == '\t') || (CC == '\n') || (CC == '\r');
}
