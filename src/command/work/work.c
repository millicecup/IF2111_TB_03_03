#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "list.h"
#include "mesinkata.h"
#include "mesinkarakter.h"

// Struktur untuk menyimpan informasi pekerjaan
typedef struct {
    char nama[50];
    int pendapatan;
    int durasi;
} Pekerjaan;

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
int bacaInput() {
    STARTKATA();
    int pilihan = 0;
    for (int i = 0; i < CKata.Length; i++) {
        pilihan = pilihan * 10 + (CKata.TabKata[i] - '0');
    }
    return pilihan;
}

int main() {
    // Inisialisasi daftar pekerjaan
    Pekerjaan pekerjaan[] = {
        {"Evil Lab Assistant", 100, 14},
        {"QWZA Hiring Manager", 4200, 24},
        {"Cikapundunginator Caretaker", 7000, 30},
        {"Mewing Specialist", 10000, 22},
        {"Inator Connoisseur", 997, 15}
    };
    int jumlahPekerjaan = 5;

    // Inisialisasi list untuk menyimpan pekerjaan
    List daftarPekerjaan;
    CreateList(&daftarPekerjaan);
    
    // Tampilkan daftar pekerjaan
    tampilkanPekerjaan(&daftarPekerjaan, pekerjaan, jumlahPekerjaan);

    // Minta input pengguna
    printf("\nMasukkan pekerjaan yang dipilih: ");
    int pilihan = bacaInput();

    // Validasi pilihan
    if (pilihan >= 1 && pilihan <= jumlahPekerjaan) {
        Pekerjaan pekerjaanDipilih = pekerjaan[pilihan - 1];
        
        printf("\nAnda sedang bekerja sebagai %s... harap tunggu.\n", pekerjaanDipilih.nama);
        
        // Tunggu sesuai durasi pekerjaan
        tunggu(pekerjaanDipilih.durasi);
        
        printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", 
               pekerjaanDipilih.pendapatan);
    } else {
        printf("Pilihan pekerjaan tidak valid!\n");
    }

    return 0;
}
