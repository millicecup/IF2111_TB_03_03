#include <stdio.h>
#include "Wishlist_Remove.h"

void WishlistRemove(Wishlist *wishlist) {
    Barang item;
    address P;

    printf("Masukkan nama barang yang akan dihapus: ");
    STARTINPUT(stdin);

    assignString(item.name, currentInput.TabWord);

    P = Search(*wishlist, item);

    if (P == Nill) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", item.name);
    } else {
        address Prec = Nill, Curr = First(*wishlist);
        while (Curr != P) {
            Prec = Curr;
            Curr = Next(Curr);
        }

        if (Prec == Nill) {
            DelFirst(wishlist, &P);
        } else {
            DelAfter(wishlist, &P, Prec);
        }
        Dealokasi(&P);
        printf("%s berhasil dihapus dari WISHLIST!\n", item.name);
    }
}
