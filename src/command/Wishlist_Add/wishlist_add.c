#include <stdio.h>
#include "wishlist_add.h"

void WishlistAdd(UserList *userList, BarangList *menu) {
    User *currentUser = &userList->users[userList->currentUserIndex];
    Barang item;
    
    printf("Masukkan nama barang: ");
    STARTINPUT(stdin);

    assignString(item.name, currentInput.TabWord);
    int idx = SearchArrayDin(*menu, toKata(item.name));
    myStrcpy(item.name, menu->items[idx].name); 

    if (!isMemberList(*menu, toKata(item.name))) {
        printf("Tidak ada barang dengan nama %s!\n", item.name);
    }
    else if (SearchX(currentUser->wishlist, item)) {
        printf("%s sudah ada di wishlist!\n", item.name);
    }
    else {
        InsVLast(&currentUser->wishlist, item);
        printf("Berhasil menambahkan %s ke wishlist!\n", item.name);
    }
}