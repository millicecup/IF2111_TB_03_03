#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../../ADT/boolean.h"
#include "../../../ADT/Mesin_Kata/mesinkata.h"
#include "../../../ADT/User_Barang/user.h"

#include "../../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "tebakangka.h"

// Inisialisasi dummy UserList untuk pengujian
void initUserList(UserList *userList) {
    userList->currentUserIndex = 0; // Pilih pengguna pertama sebagai aktif
    userList->count = 1; // Jumlah pengguna
    User user = {
        .money = 500, // Uang awal pengguna
        .name = "TestUser"
    };
    userList->users[0] = user;
}

int main() {
    // Inisialisasi UserList
    UserList userList;
    initUserList(&userList);

    // Informasi awal
    printf("Selamat datang, %s!\n", userList.users[userList.currentUserIndex].name);
    printf("Uang Anda saat ini: %d.\n", userList.users[userList.currentUserIndex].money);

    // Memulai permainan Tebak Angka
    tebakangka(&userList);

    // Informasi akhir
    printf("Terima kasih telah bermain, %s!\n", userList.users[userList.currentUserIndex].name);
    printf("Uang Anda tersisa: %d.\n", userList.users[userList.currentUserIndex].money);

    return 0;
}

/*
gcc tebakangka.c driver.c ../../../ADT/Mesin_Karakter/mesinkarakter.c ../../../ADT/Mesin_Kata/mesinkata.c ../../../ADT/Mesin_Baris/mesinbaris.c -o tebakangka

*/