#include <stdio.h>
#include <stdlib.h>
#include "Wishlist_Remove_i.h"


// Function to remove an item from the userlist->users->wishlist)) { based on the index
void WishlistRemoveI(UserList *userlist, int idx){
    if (IsEmptyWishlist(userlist->users->wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    // Validate 
    if (idx < 1 || idx > NbWishlist(userlist->users->wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", idx);
        return;
    }

    address prev = NULL;
    address curr = First(userlist->users->wishlist);
    int count = 1;

    while (count < idx) {
        prev = curr;
        curr = Next(curr);
        count++;
    }

    // Remove the node at position idx
    if (prev == NULL) {
        // Remove the first node
        DelFirst(&userlist->users->wishlist, &curr);
    } else {
        // Remove a node after the first
        DelAfter(&userlist->users->wishlist, &curr, prev);
    }

    printf("Berhasil menghapus barang posisi ke-%d dari userlist->users->wishlist)) {!\n", idx);
    Dealokasi(&curr); 
}

// int main() {
//     Wishlist userlist->users->wishlist)) {;
//     CreateEmptyWishlist(&userlist->users->wishlist)) {;

//     // Create some sample items to add to the userlist->users->wishlist)) {
//     infoBarang item1 = {"Book", 50000};
//     infoBarang item2 = {"Pen", 2000};
//     infoBarang item3 = {"Laptop", 15000000};

//     // Test insertion
//     InsVLast(&userlist->users->wishlist)) {, item1);
//     InsVLast(&userlist->users->wishlist)) {, item2);
//     InsVLast(&userlist->users->wishlist)) {, item3);

//     printf("Wishlist after insertion:\n");
//     PrintList(userlist->users->wishlist)) {;
//     printf("\n");

//     // Test WishlistRemoveI function
//     int indexToRemove; // Specify the index of the item to remove
//     scanf("%d", &indexToRemove);
//     printf("Removing item at position %d from the userlist->users->wishlist)) {...\n", indexToRemove);
//     WishlistRemoveI(&userlist->users->wishlist)) {, indexToRemove);

//     printf("Wishlist after removal:\n");
//     PrintList(userlist->users->wishlist)) {;
//     printf("\n");

//     // Test removing an invalid index
//     printf("Trying to remove item at position %d (invalid index)...\n", indexToRemove);
// }
/*
gcc Wishlist_Remove_i.c ../../ADT/LinkedList/linkedlist.c ../../ADT/Mesin_Baris/mesinbaris.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Karakter/mesinkarakter.c 
*/