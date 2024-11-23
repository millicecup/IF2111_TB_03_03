#ifndef MESINKATA_H
#define MESINKATA_H

#include "boolean.h"
#include "mesinkar.h"

#define NMax 50

typedef struct {
    char TabKata[NMax];
    int Length;
} Kata;

extern Kata CKata;

void MULAIKATA();
void ADVKATA();

#endif
