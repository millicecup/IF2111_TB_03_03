#ifndef WORK_H
#define WORK_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/boolean.h"
#include "../../ADT/List/list.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../ADT/User_Barang/user.h"

// Struktur untuk menyimpan informasi pekerjaan
typedef struct {
    char nama[50];
    int pendapatan;
    int durasi;
} Pekerjaan;

void tunggu(int durasi);

// Fungsi untuk menampilkan daftar pekerjaan
void tampilkanPekerjaan(List *daftarPekerjaan, Pekerjaan *pekerjaan, int jumlahPekerjaan);


void work(UserList *userList);

#endif