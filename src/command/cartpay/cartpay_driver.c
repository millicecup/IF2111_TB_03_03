#include <stdio.h>
#include <string.h>
#include "../boolean.h"
#include "../ADT/User_Barang/barang.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/SetMap/setmap.h"
#include "../command/cartshow/cartshow.h"

void cartShow(Keranjang k) {
    printf("Kamu akan membeli barang-barang berikut.\n");
    DisplayBasket(k);
    int totalCost = calculateTotalBasketCost(k);
    printf("Total biaya yang harus dikeluarkan adalah %d\n", totalCost);
}

int main() {
    // Inisialisasi
    Keranjang keranjang;
    CreateEmptyBasket(&keranjang);

    Barang barang1 = {"AK47", 10};
    Barang barang2 = {"Lalabu", 10};

    int userMoney;

    // Contoh pembayaran yang berhasil (Pengguna memasukkan "Ya")
    printf("\nTestcase 1: Pembayaran berhasil\n");
    AddBasket(&keranjang, barang1, 2); // 2 x 10 = 20
    AddBasket(&keranjang, barang2, 1); // 1 x 10 = 10
    userMoney = 50; // Uang cukup
    cartPay(&keranjang, &userMoney);

    // Contoh pembayaran yang gagal (Pengguna tidak memiliki uang yang cukup)
    printf("\nTestcase 2: Uang tidak cukup\n");
    CreateEmptyBasket(&keranjang);
    AddBasket(&keranjang, barang1, 2); // 2 x 10 = 20
    AddBasket(&keranjang, barang2, 2); // 2 x 10 = 20
    userMoney = 15; // Uang tidak cukup
    cartPay(&keranjang, &userMoney);

    // Contoh pembayaran yang gagal (Pengguna memasukkan "Tidak")
    printf("\nTestcase 3: Pengguna membatalkan pembayaran\n");
    CreateEmptyBasket(&keranjang);
    AddBasket(&keranjang, barang1, 2); // 2 x 10 = 20
    AddBasket(&keranjang, barang2, 1); // 1 x 10 = 10
    userMoney = 50;
    cartPay(&keranjang, &userMoney);

    // Contoh pembayaran yang gagal (Pengguna memasukkan input aneh)
    printf("\nTestcase 4: Input tidak valid\n");
    CreateEmptyBasket(&keranjang);
    AddBasket(&keranjang, barang1, 2); // 2 x 10 = 20
    AddBasket(&keranjang, barang2, 1); // 1 x 10 = 10
    userMoney = 50;
    cartPay(&keranjang, &userMoney);

    // Contoh pembayaran yang gagal (Keranjang kosong)
    printf("\nTestcase 5: Keranjang kosong\n");
    CreateEmptyBasket(&keranjang);
    userMoney = 50;
    cartPay(&keranjang, &userMoney);

    return 0;
}
