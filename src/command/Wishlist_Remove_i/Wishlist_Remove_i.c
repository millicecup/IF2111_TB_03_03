#include <stdio.h>
#include <stdlib.h>
#include "Wishlist_Remove_i.h"


// Function to remove an item from the wishlist based on the index
void WishlistRemoveI(Wishlist *wishlist, int idx) {
    if (IsEmptyWishlist(*wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    // Validate 
    if (idx < 1 || idx > NbWishlist(*wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", idx);
        return;
    }

    address prev = NULL;
    address curr = First(*wishlist);
    int count = 1;

    while (count < idx) {
        prev = curr;
        curr = Next(curr);
        count++;
    }

    // Remove the node at position idx
    if (prev == NULL) {
        // Remove the first node
        DelFirst(wishlist, &curr);
    } else {
        // Remove a node after the first
        DelAfter(wishlist, &curr, prev);
    }

    printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", idx);
    Dealokasi(&curr); 
}

// int main() {
//     Wishlist wishlist;
//     CreateEmptyWishlist(&wishlist);

//     // Create some sample items to add to the wishlist
//     infoBarang item1 = {"Book", 50000};
//     infoBarang item2 = {"Pen", 2000};
//     infoBarang item3 = {"Laptop", 15000000};

//     // Test insertion
//     InsVLast(&wishlist, item1);
//     InsVLast(&wishlist, item2);
//     InsVLast(&wishlist, item3);

//     printf("Wishlist after insertion:\n");
//     PrintList(wishlist);
//     printf("\n");

//     // Test WishlistRemoveI function
//     int indexToRemove; // Specify the index of the item to remove
//     scanf("%d", &indexToRemove);
//     printf("Removing item at position %d from the wishlist...\n", indexToRemove);
//     WishlistRemoveI(&wishlist, indexToRemove);

//     printf("Wishlist after removal:\n");
//     PrintList(wishlist);
//     printf("\n");

//     // Test removing an invalid index
//     printf("Trying to remove item at position %d (invalid index)...\n", indexToRemove);
// }
/*
gcc Wishlist_Remove_i.c ../../ADT/LinkedList/linkedlist.c ../../ADT/Mesin_Baris/mesinbaris.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Karakter/mesinkarakter.c 
*/