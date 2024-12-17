#include <stdio.h>

#include "wishlist_clear.h"
#include "../../ADT/User_Barang/user.h" 

#include <stdlib.h>

#include "../../ADT/LinkedList/linkedlist.h"

void CreateDummyWishlist(Wishlist *wishlist) {
    CreateEmptyWishlist(wishlist);

    infoBarang item1 = {"item1", 100};
    infoBarang item2 = {"item2", 200};
    infoBarang item3 = {"item3", 300};

    InsVLast(wishlist, item1);
    InsVLast(wishlist, item2);
    InsVLast(wishlist, item3);
}

int main() {
    UserList userArray;
    userArray.count = 2;

    // Create first user with a wishlist
    ManualStringCopy(userArray.users[0].name, "alice");
    CreateDummyWishlist(&userArray.users[0].wishlist);

    // Create second user with a wishlist
    ManualStringCopy(userArray.users[1].name, "bob");
    CreateDummyWishlist(&userArray.users[1].wishlist);

    // Display users and their wishlists before clearing
    printf("Before clearing:\n");
    for (int i = 0; i < userArray.count; i++) {
        printf("User: %s\n", userArray.users[i].name);
        PrintList(userArray.users[i].wishlist);
        printf("\n");
    }

    // Clear wishlist for a specific user
    printf("\nClearing wishlist for user: alice\n");
    WishlistClear(&userArray, "alice");

    // Attempt to clear wishlist for a non-existing user
    printf("\nClearing wishlist for user: charlie\n");
    WishlistClear(&userArray, "charlie");

    // Display users and their wishlists after clearing
    printf("\nAfter clearing:\n");
    for (int i = 0; i < userArray.count; i++) {
        printf("User: %s\n", userArray.users[i].name);
        PrintList(userArray.users[i].wishlist);
        printf("\n");
    }

    return 0;
}


/*
 gcc driver.c wishlist_clear.c ../../ADT/Stack/stack.c ../../ADT/User_Barang/user.c ../../ADT/LinkedList/linkedlist.c ../../ADT/User_Barang/barang.c ../../ADT/Mesin_Karakter/mesinkarakter.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Baris/mesinbaris.c

*/