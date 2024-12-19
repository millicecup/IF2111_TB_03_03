#include <stdio.h>
#include "cart_show.h"

void cartShow(Keranjang k) {
    // Cek apakah keranjang kosong
    if (IsEmptyBasket(k)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    // Menampilkan isi keranjang
    printf("Berikut adalah isi keranjangmu.\n");
    DisplayBasket(k);

    // Menghitung total cost
    int totalCost = 0;
    for (int i = 0; i < TotalBasket(k); i++) {
        totalCost += k.quantity[i] * k.item[i].price;
    }
    printf("Total biaya yang harus dikeluarkan adalah %d.\n", totalCost);
}