#include <stdio.h>
#include "wishlistswap.h"

void WishlistSwap(Wishlist *wishlist) {
    if (IsEmptyWishlist(*wishlist)) {
        printf("Wishlist kosong! Tidak ada yang dapat ditukar.\n");
        return;
    }

    STARTINPUT(stdin);

    if (!IsWordEq(currentInput, toKata("WISHLIST"))) {
        printf("Perintah tidak valid!\n");
        return;
    }

    ADVWORD();
    if (!IsWordEq(currentInput, toKata("SWAP"))) {
        printf("Perintah tidak valid!\n");
        return;
    }

    ADVWORD();
    boolean isValidInput = true;
    int i = 0, j = 0;

    for (int k = 0; k < currentInput.Length; k++) {
        if (currentInput.TabWord[k] < '0' || currentInput.TabWord[k] > '9') {
            isValidInput = false;
            break;
        }
        i = i * 10 + (currentInput.TabWord[k] - '0');
    }

    if (!isValidInput) {
        printf("Perintah tidak valid, indeks pertama bukan angka!\n");
        return;
    }

    ADVWORD();
    isValidInput = true;
    for (int k = 0; k < currentInput.Length; k++) {
        if (currentInput.TabWord[k] < '0' || currentInput.TabWord[k] > '9') {
            isValidInput = false;
            break;
        }
        j = j * 10 + (currentInput.TabWord[k] - '0');
    }

    if (!isValidInput) {
        printf("Perintah tidak valid, indeks kedua bukan angka!\n");
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
    int idx;

    for (idx = 1; idx < i; idx++) {
        p1 = Next(p1);
    }

    for (idx = 1; idx < j; idx++) {
        p2 = Next(p2);
    }

    infoBarang temp = Info(p1);
    Info(p1) = Info(p2);
    Info(p2) = temp;

    printf("Berhasil menukar posisi %s dengan %s pada wishlist!\n", Item(p1), Item(p2));
}
