#include <stdio.h>
#include "wishlistAdd.h"

void WishlistAdd(Wishlist *wishlist, BarangList *menu) {
    Barang item;
    
    printf("Masukkan nama barang: ");
    STARTINPUT(stdin);

    assignString(item.name, currentInput.TabWord);

    if (!isMemberList(*menu, toKata(item.name))) {
        printf("Tidak ada barang dengan nama %s!\n", item.name);
    }
    else if (SearchX(*wishlist, item)) {
        printf("%s sudah ada di wishlist!\n", item.name);
    }
    else {
        InsVLast(wishlist, item);
        printf("Berhasil menambahkan %s ke wishlist!\n", item.name);
    }
}


