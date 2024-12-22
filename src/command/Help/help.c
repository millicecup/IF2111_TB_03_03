#include <stdio.h>
#include "help.h" 
#include "../../ADT/boolean.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"

//fungsi untuk menampilkan HELP sesuai menu aktif
void printHelp(MenuState *current_menu) {
    boolean exitHelp = false;
    if (*current_menu == menuforwelcome) {
        printf("=====[ Welcome Menu Help PURRMART ]=====\n");
        printf("Ketik 'back' untuk keluar dari menu help\n");
        printf("PURRY MART HADIR UNTUK SELURUH WARGA\n");
        printf("1. START -> Untuk masuk sesi baru\n");
        printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
        printf("3. HELP -> Daftar command yang dapat dilakukan pada menu ini\n");
        printf("4. QUIT -> Untuk keluar dari program\n");
    } else if (*current_menu == menuforlogin) {
        printf("=====[ Login Menu Help PURRMART ]=====\n");
        printf("Ketik 'back' untuk keluar dari menu help\n");
        printf("PURRY MART HADIR UNTUK SELURUH WARGA\n");
        printf("1. LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
        printf("2. REGISTER -> Untuk melakukan pendaftaran akun baru\n");
        printf("3. HELP -> Daftar command yang dapat dilakukan pada menu ini\n");
        printf("4. MAIN MENU -> Untuk kembali ke menu awal\n");
        printf("5. QUIT -> Untuk keluar dari program\n");
    } else if (*current_menu == menuutama) {
        printf("=====[ Menu Help PURRMART ]=====\n");
        printf("Ketik 'back' untuk keluar dari menu help\n");
        printf("1. STORE -> Untuk berbelanja\n");
        printf("2. WORK -> Untuk pekerjaan biasa\n");
        printf("3. WORK CHALLENGE -> Untuk pekerjaan spesial\n");
        printf("4. CART -> Untuk masuk ke menu yang berhubungan dengan cart\n");
        printf("5. WISHLIST -> Untuk masuk ke menu yang berhubungan dengan wishlist\n");
        printf("6. PROFILE -> Untuk melihat info akun pengguna\n");
        printf("7. HISTORY <N> -> Untuk melihat riwayat pembelian terakhir pengguna sejumlah N\n");
        printf("8. HELP -> Daftar command yang dapat dilakukan pada menu ini\n");
        printf("9. SAVE -> Untuk menyimpan state ke dalam file\n");
        printf("10. LOGOUT -> Untuk keluar dari sesi\n");
    } else if (*current_menu == menustore) {
        printf("=====[ Menu Help PURRMART ]=====\n");
        printf("Ketik 'back;' untuk keluar dari menu help\n");
        printf("1. STORE LIST -> Untuk melihat barang-barang di toko\n");
        printf("2. STORE REQUEST -> Untuk meminta penambahan barang\n");
        printf("3. STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
        printf("4. STORE REMOVE -> Untuk menghapus barang\n");
        printf("5. HELP -> Daftar command yang dapat dilakukan pada menu ini\n");
        printf("6. MENU -> Untuk kembali ke menu sebelumnya\n");
    } else if (*current_menu == menuworkchallenge) {
        printf("=====[ Menu Help PURRMART ]=====\n");
        printf("Ketik 'back' untuk keluar dari menu help\n");
        printf("1. TEBAK ANGKA ->  Tebak kata dengan biaya bermain 200 dan kesempatan memenangkan 350\n");
        printf("2. WORDL3 -> Tebak kata dengan biaya bermain 500 dan kesempatan memenangkan 1500\n");
        printf("3. HELP -> Daftar command yang dapat dilakukan pada menu ini\n");
        printf("4. MENU -> Untuk kembali ke menu sebelumnya\n");
    } else if (*current_menu == menucart) {
        printf("=====[ Menu Help PURRMART ]=====\n");
        printf("Ketik 'back' untuk keluar dari menu help\n");
        printf("1. CART ADD <nama> <n> ->  Untuk menambahkan barang <nama> sejumlah <n> ke keranjang\n");
        printf("2. CART REMOVE <nama> <n> -> Untuk menghapus barang <nama> sejumlah <n> dari keranjang\n");
        printf("3. CART SHOW ->  Untuk menunjukkan barang yang ada di keranjang\n");
        printf("4. CART PAY -> Untuk membeli barang - barang yang sudah dimasukkan ke keranjang\n");
        printf("5. HELP -> Daftar command yang dapat dilakukan pada menu ini\n");
        printf("6. MENU -> Untuk kembali ke menu sebelumnya\n");
    } else if (*current_menu == menuwishlist) {
        printf("=====[ Menu Help PURRMART ]=====\n");
        printf("Ketik 'back' untuk keluar dari menu help\n");
        printf("1. WISHLIST ADD ->  Untuk menambahkan barang ke wishlist\n");
        printf("2. WISHLIST SWAP <i> <j> -> Untuk menukar barang posisi ke <i> dengan barang posisi ke <j> pada wishlist\n");
        printf("3. WISHLIST REMOVE <i> ->  Untuk menghapus barang posisi ke <i> pada wishlist\n");
        printf("4. WISHLIST REMOVE -> Untuk menghapus barang dari wishlist\n");
        printf("5. WISHLIST CLEAR ->  Untuk menghapus semua barang dari wishlist\n");
        printf("6. WISHLIST SHOW -> Untuk menunjukkan barang - barang yang sudah dimasukkan ke wishlist\n");
        printf("7. HELP -> Daftar command yang dapat dilakukan pada menu ini\n");
        printf("8. MENU -> Untuk kembali ke menu sebelumnya\n");
    }
}

void help(MenuState *current_menu)
{
    boolean exitHelp = false;

    printHelp(current_menu);
    while(!exitHelp)
    {
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