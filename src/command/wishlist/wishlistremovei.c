#include <stdio.h>
#include <stdlib.h>
#include "wishlistremovei.h"

void WishlistRemoveI(Wishlist *wishlist) {
    if (IsEmptyWishlist(*wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    printf("Masukkan posisi barang yang ingin dihapus: ");
    STARTINPUT(stdin);

    boolean isValidInput = true;
    int position = 0;

    for (int i = 0; i < currentInput.Length; i++) {
        if (currentInput.TabWord[i] < '0' || currentInput.TabWord[i] > '9') {
            isValidInput = false;
            break;
        }
        position = position * 10 + (currentInput.TabWord[i] - '0');
    }

    if (!isValidInput) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, command tidak valid!\n");
        return;
    }

    int totalItems = NbWishlist(*wishlist);

    if (position < 1 || position > totalItems) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", position);
        return;
    }

    address prev = Nill;
    address curr = First(*wishlist);
    int count = 1;

    while (count < position) {
        prev = curr;
        curr = Next(curr);
        count++;
    }

    if (prev == Nill) {
        DelFirst(wishlist, &curr);
    } else {
        DelAfter(wishlist, &curr, prev);
    }

    printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", position);
    Dealokasi(&curr);
}
