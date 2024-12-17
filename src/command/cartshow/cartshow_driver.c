#include <stdio.h>
#include "../ADT/SetMap/setmap.h"
#include "cartshow.h"

int main() {
    Keranjang keranjang;
    CreateEmptyBasket(&keranjang);

    // Contoh kasus Keranjang kosong
    cartShow(keranjang);

    // Tambahkan barang ke keranjang
    Barang barang1 = {"AK47", 10};
    Barang barang2 = {"Lalabu", 10};
    AddBasket(&keranjang, barang1, 2);
    AddBasket(&keranjang, barang2, 1);

    // Contoh Keranjang ada berisi
    cartShow(keranjang);

    return 0;
}
