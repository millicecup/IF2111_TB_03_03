
#include <stdio.h>

#include <stdlib.h>
#include "../../ADT/user/user.h"  // ADT User
#include "../../ADT/barang/barang.h"  // ADT Barang
#include "../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Baris/mesinbaris.h"

static FILE *pita;

int start() {
    pita = fopen("../../../save/config.txt", "r");

    if (pita == NULL) {
        printf("Gagal membuka file\n");
        //return 1;
    }

    // Inisialisasi UserList dan BarangList
    ArrayUser userList;
    CreateUserList(&userList);

    Arraybarang barangList;
    CreateBarangList(&barangList, 2); // Kapasitas awal 2 untuk Barang

    // Memulai mesin karakter
    STARTFILE(pita);
    //printf("Isi baris pertama: %s\n", currentLine.kalimat);  // Debugging untuk melihat isi baris pertama

    int num_items = atoi(currentLine.kalimat);
    printf("Jumlah barang: %d\n", num_items);

    for (int i = 0; i < num_items; i++) {
        ADVWORD();
        int price = WordtoNum(currentWord);
        ADVSENTENCE();
        AddBarang(&barangList, currentLine.kalimat, price);
        //printf("Barang %d - Harga: %d\n", i + 1, price);
    }

    ADVSENTENCE();
    int num_users = atoi(currentLine.kalimat);
    printf("Jumlah pengguna: %d\n", num_users);

    for (int i = 0; i < num_users; i++) {
        // Ambil uang pengguna
        ADVWORD();
        int money = WordtoNum(currentWord); 

        // Salin username secara manual
        ADVWORD();
        char username[MAX_LEN];
        for (int j = 0; j < currentWord.Length && j < MAX_LEN - 1; j++) {
            username[j] = currentWord.TabWord[j];
        }
        username[currentWord.Length] = '\0'; // Tambahkan null terminator

        // Salin password secara manual
        ADVWORD();
        char password[MAX_LEN];
        for (int j = 0; j < currentWord.Length && j < MAX_LEN - 1; j++) {
            password[j] = currentWord.TabWord[j];
        }
        password[currentWord.Length] = '\0'; // Tambahkan null terminator

        // Tambahkan user ke UserList
        AddUser(&userList, username, password, money);
    }

    fclose(pita);

    // Print daftar barang
    printf("\nDaftar Barang:\n");
    PrintBarang(&barangList);

    // Print daftar pengguna
    printf("\nDaftar Pengguna:\n");
    PrintUsers(&userList);

    // Bebaskan memori untuk BarangList (dinamis)
    FreeBarangList(&barangList);

    printf("\nFile File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");

    return 0;
}

// gcc start.c ../../ADT/User_Barang/user.c ../../ADT/User_Barang/barang.c ../../ADT/Mesin_Karakter/mesinkarakter.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Baris/mesinbaris.c -o program