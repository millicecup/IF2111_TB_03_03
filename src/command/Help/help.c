#include <stdio.h>
#include "help.h" 
#include "../../ADT/boolean.h"
#include "../../ADT/mesin_kata/mesinkata.h"

//fungsi untuk menampilkan HELP sesuai menu aktif
void help(MenuState *current_menu) {
    boolean exitHelp = false;
    while(!exitHelp)
    {
        if (*current_menu == menuforwelcome) {
            printf("=====[ Welcome Menu Help PURRMART ]=====\n");
            printf("Ketik 'back' untuk keluar dari menu help\n");
            printf("PURRY MART HADIR UNTUK SELURUH WARGA\n");
            printf("1. START -> Untuk masuk sesi baru\n");
            printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
            printf("3. QUIT -> Untuk keluar dari program\n");
        } else if (*current_menu == menuforlogin) {
            printf("=====[ Login Menu Help PURRMART ]=====\n");
            printf("Ketik 'back' untuk keluar dari menu help\n");
            printf("PURRY MART HADIR UNTUK SELURUH WARGA\n");
            printf("1. REGISTER -> Untuk melakukan pendaftaran akun baru\n");
            printf("2. LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
            printf("3. QUIT -> Untuk keluar dari program\n");
            printf("4. MENU -> Untuk kembali ke menu awal\n");
        } else if (*current_menu == menuutama) {
            printf("=====[ Menu Help PURRMART ]=====\n");
            printf("Ketik 'back' untuk keluar dari menu help\n");
            printf("1. WORK -> Untuk pekerjaan biasa\n");
            printf("2. WORK CHALLENGE -> Untuk pekerjaan spesial\n");
            printf("3. STORE -> Untuk berbelanja\n");
            printf("4. LOGOUT -> Untuk keluar dari sesi\n");
            printf("5. SAVE -> Untuk menyimpan state ke dalam file\n");
        } else if (*current_menu == menustore) {
            printf("=====[ Menu Help PURRMART ]=====\n");
            printf("Ketik 'back;' untuk keluar dari menu help\n");
            printf("1. STORE LIST -> Untuk melihat barang-barang di toko\n");
            printf("2. STORE REQUEST -> Untuk meminta penambahan barang\n");
            printf("3. STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
            printf("4. STORE REMOVE -> Untuk menghapus barang\n");
            printf("5. MENU -> Untuk kembali ke menu sebelumnya\n");
        } else if (*current_menu == menuworkchallenge) {
            printf("=====[ Menu Help PURRMART ]=====\n");
            printf("Ketik 'back' untuk keluar dari menu help\n");
            printf("1. TEBAK ANGKA ->  Tebak kata dengan biaya bermain 200 dan kesempatan memenangkan 350\n");
            printf("2. WORDL3 -> Tebak kata dengan biaya bermain 500 dan kesempatan memenangkan 1500\n");
            printf("3. MENU -> Untuk kembali ke menu sebelumnya\n");
        } 
        GetInput();
        Word currentWord;
        chartoWord(&currentWord, currentInput.TabWord);

        if (isWordEqualToString(&currentWord, "back"))
        {
            exitHelp = true;
        }
        else
        {
            printf("Perintah tidak valid! Ketik 'back' untuk keluar.\n");
        }
    }
}

//fungsi ganti menu
void update_menu(MenuState *current_menu, MenuState menu_updated) {
    *current_menu = menu_updated;
}