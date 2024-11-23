#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "mesinbaris.h"

int main() {
    // Inisialisasi random number generator
    srand(time(NULL));
    int target = rand() % 100 + 1; // Angka random antara 1-100
    int tebakan;
    int kesempatan = 10;

    printf("Selamat datang di permainan tebak angka!\n");

    while (kesempatan > 0) {
        printf("\nTebak angka: ");
        STARTWORD(stdin); // Membaca input menggunakan mesin kata
        tebakan = WordtoNum(currentWord); // Konversi kata ke integer

        if (tebakan < target) {
            printf("Tebakanmu lebih kecil!\n");
        } else if (tebakan > target) {
            printf("Tebakanmu lebih besar!\n");
        } else {
            printf("Tebakanmu benar! Selamat!\n");
            break;
        }

        kesempatan--;
        if (kesempatan > 0) {
            printf("Kesempatan tersisa: %d\n", kesempatan);
        }
    }

    if (kesempatan == 0) {
        printf("Kesempatanmu sudah habis! Angka yang benar adalah %d\n", target);
    }

    return 0;
}
