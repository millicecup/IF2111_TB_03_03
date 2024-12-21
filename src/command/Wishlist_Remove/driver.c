#include <stdio.h>
#include "Wishlist_Remove.h"
int main() {
    // Initialize user list and create an empty wishlist for the current user
    UserList userlist;
    CreateEmptyWishlist(&userlist.users->wishlist);
    infoBarang item1, item2, item3;
    Wishlist Wishlist = userlist.users->wishlist;
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

    // Display the wishlist after adding items
    printf("Wishlist setelah penambahan:\n");
    PrintList(Wishlist);
    printf("\n");

    // Call the WishlistRemove function to test item removal
    WishlistRemove(&userlist);

    // Display the wishlist after removal
    printf("Wishlist setelah penghapusan:\n");
    PrintList(Wishlist);
    printf("\n");

    // Test removing an item that does not exist
    printf("Mencoba menghapus item yang tidak ada:\n");
    WishlistRemove(&userlist);

    return 0;
}

/*
gcc Wishlist_Remove.c  driver.c ../work/work.c ../../ADT/Stack/stack.c ../../ADT/User_Barang/user.c ../../ADT/LinkedList/linkedlist.c ../../ADT/User_Barang/barang.c ../../ADT/Mesin_Karakter/mesinkarakter.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Baris/mesinbaris.c ../../ADT/List/list.c
*/