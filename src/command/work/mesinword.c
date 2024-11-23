#include <stdio.h>
#include "mesinword.h"

Kata CKata;

void TAIgnoreBlanks(void) {
    while (TAIsWhitespace() && !TAIsEOP()) {
        TAADV();
    }
}

void TASTARTKATA(void) {
    TASTART();
    TAIgnoreBlanks();
    TASalinKata();
}

void TAADVKATA(void) {
    TAIgnoreBlanks();
    TASalinKata();
}

void TASalinKata(void) {
    int i = 0;
    while (!TAIsWhitespace() && !TAIsEOP() && i < NMax - 1) {
        CKata.TabKata[i] = TAGetCC();
        TAADV();
        i++;
    }
    CKata.TabKata[i] = '\0'; 
    CKata.Length = i;
}

boolean TAIsKataSama(Kata K1, Kata K2) {
    if (K1.Length != K2.Length) {
        return false;
    }
    for (int i = 0; i < K1.Length; i++) {
        if (K1.TabKata[i] != K2.TabKata[i]) {
            return false;
        }
    }
    return true;
}