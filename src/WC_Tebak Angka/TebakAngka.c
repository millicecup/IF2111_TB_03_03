#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mesinkar.h"
#include "mesinkata.h"

int main() {
    // Inisialisasi random number generator
    srand(time(NULL));
    int target = rand() % 100 + 1; // Angka random antara 1-100
    int tebakan;
    int kesempatan = 10;

    while (kesempatan > 0) {
        printf("Tebak angka: ");
        TASTARTKATA();
        tebakan = atoi(CKata.TabKata);

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

    return 0;
}
