#include <stdio.h>
#include "linkedlist.h"

int main() {
    Wishlist Wishlist;
    infoBarang item1, item2, item3;

    CreateEmptyWishlist(&Wishlist);
    printf(">>> Wishlist awal:\n");
    PrintList(Wishlist);
    printf("\n");

    assignString(item1.name, "Apple");
    item1.price = 15000000;
    assignString(item2.name, "Banana");
    item2.price = 8000000;
    assignString(item3.name, "Orange");
    item3.price = 1500000;

    /// Nambahin barang
    InsVFirst(&Wishlist, item1);
    InsVLast(&Wishlist, item2);
    InsVLast(&Wishlist, item3);

    printf("\nMenambah wishlist...\n");
    printf(">>> Wishlist: \n");
    PrintList(Wishlist);
    printf("\n");

    printf("Jumlah wishlist: %d\n", NbWishlist(Wishlist));

    // Cari barang
    printf("\nMencari 'Banana'...\n");
    if (SearchX(Wishlist, item2)) {
        printf("Ketemu!\n");
    } else {
        printf("Gaada %s\n", item2.name);
    }

    // Hapus barang pertama
    printf("\nMenghapus wishlist pertama...\n");
    infoBarang removedItem;
    DelVFirst(&Wishlist, &removedItem);
    printf("Wishlist dihapus: %s, %d\n", removedItem.name, removedItem.price);

    // Wishlist setelah diapus
    printf("\n>>> Wishlist: \n");
    PrintList(Wishlist);
    printf("\n");

    // Hapus barang terakhir
    printf("\nMenghapus wishlist terakhir...\n");
    DelVLast(&Wishlist, &removedItem);
    printf("Wishlist dihapus: %s, %d\n", removedItem.name, removedItem.price);

    // Wishlist setelah diapus
    printf("\n>>> Wishlist: \n");
    PrintList(Wishlist);
    printf("\n");

    return 0;
}
