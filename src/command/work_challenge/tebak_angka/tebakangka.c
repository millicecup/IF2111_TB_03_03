#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../../ADT/boolean.h"
#include "../../../ADT/Mesin_Kata/mesinkata.h"
#include "../../../ADT/Mesin_Karakter/mesinkarakter.h"
// #include "../../../ADT/work/mesinkar.h"
// #include "../../../ADT/work/mesinword.h"

void tebakangka() {
    // Inisialisasi random number generator
    srand(time(NULL));
    int target = rand() % 100 + 1; // Angka random antara 1-100
    int tebakan;
    int kesempatan = 10;

    while (kesempatan > 0) {
        printf("Tebak angka: ");
        STARTINPUT(stdin);
        tebakan = atoi(currentInput.TabWord);
        
        if (tebakan < target) {
            printf("Tebakanmu lebih kecil!\n");
        } else if (tebakan > target) {
            printf("Tebakanmu lebih besar!\n");
        } else {
            printf("Tebakanmu benar! Selamat!\n");
            break; 
        }

        kesempatan--;
    }

    if (kesempatan == 0) {
        printf("Kesempatanmu sudah habis! Angka yang benar adalah %d\n", target);
    }

}

int main(){
    tebakangka();
    return 0;
}

/*
 gcc tebakangka.c ../../../ADT/Mesin_Karakter/mesinkarakter.c ../../../ADT/Mesin_Kata/mesinkata.c ../../../ADT/Mesin_Baris/mesinbaris.c -o tebakangka
 */
