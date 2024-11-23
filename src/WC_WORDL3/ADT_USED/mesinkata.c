#include "mesinkata.h"

Kata CKata;

void MULAIKATA() {
    START();
    CKata.Length = 0;

    while (CC != MARK && CKata.Length < NMax) {
        CKata.TabKata[CKata.Length] = CC;
        CKata.Length++;
        ADV();
    }
}

void ADVKATA() {
    CKata.Length = 0;

    while (CC != MARK && CKata.Length < NMax) {
        CKata.TabKata[CKata.Length] = CC;
        CKata.Length++;
        ADV();
    }
}
