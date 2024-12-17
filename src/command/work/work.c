#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/boolean.h"
#include "../../ADT/List/list.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Baris/mesinbaris.h"
#include "../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../ADT/User_Barang/user.h"
#include "work.h"

// Fungsi untuk menunggu selama durasi tertentu
void tunggu(int durasi) {
    clock_t start = clock();
    while ((clock() - start) / CLOCKS_PER_SEC < durasi);
}

// Fungsi untuk menampilkan daftar pekerjaan
void tampilkanPekerjaan(List *daftarPekerjaan, Pekerjaan *pekerjaan, int jumlahPekerjaan) {
    printf("\nDaftar pekerjaan:\n");
    for (int i = 0; i < jumlahPekerjaan; i++) {
        printf("%d. %s (pendapatan=%d, durasi=%ds)\n", 
               i + 1, 
               pekerjaan[i].nama, 
               pekerjaan[i].pendapatan, 
               pekerjaan[i].durasi);
    }
}

// Fungsi untuk membaca input pengguna
// int bacaInput() {
//     STARTINPUT(stdin);
//     WordToInt(&currentInput);
//     int pilihan = 0;
//     for (int i = 0; i < currentWord.Length; i++) {
//         pilihan = pilihan * 10 + (currentWord.TabWord[i] - '0');
//     }
//     return pilihan;
// }

void work(UserList *userList) {
    // Inisialisasi daftar pekerjaan
    Pekerjaan pekerjaan[] = {
        {"Evil Lab Assistant", 100, 14},
        {"QWZA Hiring Manager", 4200, 24},
        {"Cikapundunginator Caretaker", 7000, 30},
        {"Mewing Specialist", 10000, 22},
        {"Inator Connoisseur", 997, 15}
    };
    int jumlahPekerjaan = 5;
    User *currentUser = &userList->users[userList->currentUserIndex];
    // Inisialisasi list untuk menyimpan pekerjaan
    List daftarPekerjaan;
    MakeList(&daftarPekerjaan);
    
    // Tampilkan daftar pekerjaan
    tampilkanPekerjaan(&daftarPekerjaan, pekerjaan, jumlahPekerjaan);

    // Minta input pengguna
    printf("\nMasukkan pekerjaan yang dipilih: ");
    STARTINPUT(stdin);
    int pilihan = WordToInt(&currentInput);

    // Validasi pilihan
    if (pilihan >= 1 && pilihan <= jumlahPekerjaan) {
        Pekerjaan pekerjaanDipilih = pekerjaan[pilihan - 1];
        
        printf("\nAnda sedang bekerja sebagai %s... harap tunggu.\n", pekerjaanDipilih.nama);
        
        // Tunggu sesuai durasi pekerjaan
        tunggu(pekerjaanDipilih.durasi);
        currentUser->money += pekerjaanDipilih.pendapatan;
        
        printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", pekerjaanDipilih.pendapatan);
        printf("Jumlah uang anda sekarang adalah %d.\n", currentUser->money);
    } else {
        printf("Pilihan pekerjaan tidak valid!\n");
    }
}
