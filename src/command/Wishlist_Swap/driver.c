#include <stdio.h>
#include "Wishlist_Swap.h"

int main() {
    Wishlist wishlist;
    CreateEmptyWishlist(&wishlist);

    // Add sample items to the wishlist
    infoBarang item1 = {"Ayam Goreng Crisbar"};
    infoBarang item2 = {"AK47"};
    infoBarang item3 = {"Lalabu"};

    InsVLast(&wishlist, item1);
    InsVLast(&wishlist, item2);
    InsVLast(&wishlist, item3);

    // Display initial wishlist
    printf("Initial Wishlist:\n");
    PrintList(wishlist);

    // Test 1: Swap first and second items
    printf("\nTest 1: Swapping position 1 and 2\n");
    WishlistSwap(&wishlist, 1, 2);
    PrintList(wishlist);

    // Test 2: Swap second and third items
    printf("\nTest 2: Swapping position 2 and 3\n");
    WishlistSwap(&wishlist, 2, 3);
    PrintList(wishlist);

    // Test 3: Swap invalid indices (e.g., 0 and 4)
    printf("\nTest 3: Swapping invalid positions 0 and 4\n");
    WishlistSwap(&wishlist, 0, 4);

    // Test 4: Swap same indices (e.g., 2 and 2)
    printf("\nTest 4: Swapping same position 2 and 2\n");
    WishlistSwap(&wishlist, 2, 2);

    // Test 5: Swap in an empty wishlist
    printf("\nTest 5: Swapping in an empty wishlist\n");
    Wishlist emptyWishlist;
    CreateEmptyWishlist(&emptyWishlist);
    WishlistSwap(&emptyWishlist, 1, 2);

    return 0;
}
/*
gcc driver.c Wishlist_Swap.c ../../ADT/LinkedList/linkedlist.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Karakter/mesinkarakter.c ../../ADT/Mesin_Baris/mesinbaris.c
*/