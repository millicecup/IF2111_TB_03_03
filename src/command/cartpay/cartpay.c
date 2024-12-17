#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../ADT/User_Barang/barang.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/SetMap/setmap.h"
#include "../command/cartshow/cartshow.h"

// Fungsi untuk menghitung total biaya keranjang
int calculateTotalBasketCost(Keranjang k) {
    int totalCost = 0;
    for (int i = 0; i < TotalBasket(k); i++) {
        totalCost += k.quantity[i] * k.item[i].price;
    }
    return totalCost;
}

// Fungsi untuk melakukan pembayaran
void cartPay(Keranjang *k, int *userMoney) {
    // Cek apakah keranjang kosong
    if (IsEmptyBasket(*k)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    // Gunakan fungsi cartShow untuk menampilkan keranjang
    cartShow(*k);

    // Minta konfirmasi pembayaran
    printf("Apakah jadi dibeli? (Ya/Tidak): ");

    // Input konfirmasi pembayaran
    ResetInput();
    GetInput();

    // Konversi input ke word "Ya"
    Word yaWord = toKata("ya");

    // Validasi input
    if (isWordEqualToString(&currentInput, "ya") || isWordEqualToString(&currentInput, "Ya")) {
        // Hitung total biaya
        int totalCost = calculateTotalBasketCost(*k);

        // Cek kecukupan uang
        if (*userMoney >= totalCost) {
            // Lakukan pembayaran
            *userMoney -= totalCost;
            printf("Selamat kamu telah membeli barang-barang tersebut!\n");
            
            // Kosongkan keranjang setelah pembayaran
            CreateEmptyBasket(k);
        } else {
            // Uang tidak cukup
            printf("Uang kamu hanya %d, tidak cukup untuk membeli barang yang ada di keranjang!\n", *userMoney);
        }
    } else if (isWordEqualToString(&currentInput, "tidak") || isWordEqualToString(&currentInput, "Tidak")) {
        // Batalkan pembayaran
        printf("Pembayaran dibatalkan.\n");
    } else {
        // Input tidak valid
        printf("Input tidak valid. Pembayaran dibatalkan.\n");
    }
}