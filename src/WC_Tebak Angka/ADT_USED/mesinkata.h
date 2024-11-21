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

// Deklarasi Fungsi dan Prosedur
void TAIgnoreBlanks(void);
void TASTARTKATA(void);
void TAADVKATA(void);
void TASalinKata(void);
boolean TAIsKataSama(Kata K1, Kata K2);

#endif
