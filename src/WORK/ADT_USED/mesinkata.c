#include <stdio.h>
#include "mesinkata.h"

Kata CKata;

void IgnoreBlanks() {
    while (IsWhitespace() && !IsEOP()) {
        ADV();
    }
}

void STARTKATA(void) {
    START();
    IgnoreBlanks();
    SalinKata();
}

void ADVKATA(void) {
    IgnoreBlanks();
    SalinKata();
}

void SalinKata(void) {
    int i = 0;
    while (!IsWhitespace() && !IsEOP() && i < NMax - 1) {
        CKata.TabKata[i] = GetCC();
        ADV();
        i++;
    }
    CKata.TabKata[i] = '\0'; 
    CKata.Length = i;
}

boolean IsKataSama(Kata K1, Kata K2) {
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
