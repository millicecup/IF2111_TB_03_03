#include <stdio.h>
#include "Wishlist_Swap.h"

void WishlistSwap(UserList *userlist, int i, int j){
    User *currentUser = &userlist->users[userlist->currentUserIndex];
    if (IsEmptyWishlist(currentUser->wishlist)) {
        printf("Wishlist kosong! Tidak ada yang dapat ditukar.\n");
        return;
    }

    int n = NbWishlist(currentUser->wishlist);
    if (i < 1 || j < 1 || i > n || j > n) {
        printf("Indeks tidak valid! Wishlist hanya memiliki %d barang.\n", n);
        return;
    }

    if (i == j) {
        printf("Tidak ada yang ditukar karena indeks sama.\n");
        return;
    }

    address p1 = First(currentUser->wishlist);
    address p2 = First(currentUser->wishlist);
    int idx;

    // Cari elemen ke-i
    for (idx = 1; idx < i; idx++) {
        p1 = Next(p1);
    }

    // Cari elemen ke-j
    for (idx = 1; idx < j; idx++) {
        p2 = Next(p2);
    }

    // Tukar elemen
    infoBarang temp = Info(p1);
    Info(p1) = Info(p2);
    Info(p2) = temp;

    printf("Berhasil menukar posisi %s dengan %s pada currentUser->wishlist!\n", Item(p1), Item(p2));
}
