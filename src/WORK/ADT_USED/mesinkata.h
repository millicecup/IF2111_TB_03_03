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

//// Deklarasi Fungsi dan Prosedur
void IgnoreBlanks(void);
void STARTKATA(void);
void ADVKATA(void);
void SalinKata(void);
boolean IsKataSama(Kata K1, Kata K2);

#endif
