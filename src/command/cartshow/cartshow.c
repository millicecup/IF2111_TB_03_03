#include <stdio.h>
#include "cartshow.h"

void cartShow(Keranjang k) {
    // Check if the cart is empty
    if (IsEmptyBasket(k)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    // Menampilkan isi keranjang
    printf("Berikut adalah isi keranjangmu.\n");

    // Predikat untuk menampilkan isi keranjang
    DisplayBasket(k);

    // Calculate and display total cost
    int totalCost = 0;
    for (int i = 0; i < TotalBasket(k); i++) {
        totalCost += k.quantity[i] * k.item[i].price;
    }
    printf("Total biaya yang harus dikeluarkan adalah %d.\n", totalCost);
}