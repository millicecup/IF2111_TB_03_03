#include <stdio.h>
#include "wishlistswap.h"

void WishlistSwap(Wishlist *wishlist, int i, int j) {
    if (IsEmptyWishlist(*wishlist)) {
        printf("Gagal menukar posisi! Wishlist kosong.\n");
        return;
    }

    int n = NbWishlist(*wishlist);
    if (i < 1 || j < 1 || i > n || j > n) {
        printf("Indeks tidak valid! Wishlist hanya memiliki %d barang.\n", n);
        return;
    }

    if (i == j) {
        printf("Tidak ada yang ditukar karena indeks sama.\n");
        return;
    }

    address p1 = First(*wishlist);
    address p2 = First(*wishlist);

    for (int idx = 1; idx < i; idx++) {
        p1 = Next(p1);
    }

    for (int idx = 1; idx < j; idx++) {
        p2 = Next(p2);
    }

    if (p1 == NULL || p2 == NULL) {
        printf("Gagal menukar posisi! Elemen tidak ditemukan.\n");
        return;
    }

    infoBarang temp = Info(p1);
    Info(p1) = Info(p2);
    Info(p2) = temp;

    printf("Berhasil menukar posisi %s dengan %s pada wishlist!\n", Item(p1), Item(p2));
}
