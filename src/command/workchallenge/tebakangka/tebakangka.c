#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../../ADT/boolean.h"
#include "../../../ADT/Mesin_Kata/mesinkata.h"
#include "../../../ADT/User_Barang/user.h"

#include "../../../ADT/Mesin_Karakter/mesinkarakter.h"
// #include "../../../ADT/work/mesinkar.h"
// #include "../../../ADT/work/mesinword.h"

void tebakangka(UserList *userList) {
    User *currentUser = &userList->users[userList->currentUserIndex];
    // Deduct coins to play the game
    if (currentUser->money < 200) {
        printf("Uang Anda tidak cukup untuk memainkan permainan ini.\n");
        return;
    }
    currentUser->money -= 200;
    printf("200 koin telah dikurangi. Sisa uang Anda: %d.\n", currentUser->money);
    printf("Selamat datang di permainan Tebak Angka!\n");
    printf("ATTENTION! : \n");
    printf("Anda memiliki 10 kesempatan untuk menebak.\n");
    printf("Apabila angka yang ditebak lebih kecil akan ada pemberitahuan.\n");
    printf("Apabila angka yang ditebak lebih besar akan ada pemberitahuan.\n");
    printf("Apabila angka yang ditebak benar akan ada pemberitahuan dan otomatis keluar dari permainan.\n");

    // Inisialisasi random number generator
    srand(time(NULL));
    int target = rand() % 100 + 1; // Angka random antara 1-100
    int tebakan;
    int kesempatan = 10;

    while (kesempatan > 0) {
        printf("Tebak angka: ");
        STARTINPUT(stdin);
        int tebakan = WordToInt(&currentInput);
        if (tebakan > 0)
        {
            if (tebakan < target) {
                printf("Tebakanmu lebih kecil!\n");
            } else if (tebakan > target) {
                printf("Tebakanmu lebih besar!\n");
            } else {
                printf("Tebakanmu benar! Selamat!\n");
                int hadiah = 50;
                hadiah *= kesempatan;
                printf("Anda mendapatkan %d koin!\n", hadiah);
                currentUser->money += hadiah;
                printf("Uang Anda saat ini: %d.\n", currentUser->money);
                break; 
            }

            kesempatan--;
        }
        else
        {
            printf("Input tidak valid!.\n");
        }
    }

    if (kesempatan == 0) {
        printf("Kesempatanmu sudah habis! Angka yang benar adalah %d\n", target);
        printf("Uang Anda saat ini: %d.\n", currentUser->money);
    }

}
