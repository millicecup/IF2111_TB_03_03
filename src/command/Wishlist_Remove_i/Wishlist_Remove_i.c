#include <stdio.h>
#include <stdlib.h>
#include "Wishlist_Remove_i.h"

// hapus index ke i
void WishlistRemoveI(UserList *userlist, int idx) {
    User *currentUser = &userlist->users[userlist->currentUserIndex];
    if (IsEmptyWishlist(currentUser->wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    // Validate
    if (idx < 1 || idx > NbWishlist(currentUser->wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", idx);
        return;
    }

    address prev = NULL;
    address curr = First(currentUser->wishlist);
    int count = 1;

    while (count < idx) {
        prev = curr;
        curr = Next(curr);
        count++;
    }

    if (prev == NULL) {
       
        DelFirst(&currentUser->wishlist, &curr);
    } else {
        
        DelAfter(&currentUser->wishlist, &curr, prev);
    }

    printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", idx);
    Dealokasi(&curr); 
}

// int main() {
//     // Assuming UserList is defined correctly and initialized.
//     UserList userlist;  
//     CreateEmptyWishlist(&userlist.users->wishlist);

//     // Create some sample items to add to the wishlist
//     infoBarang item1 = {"Book", 50000};
//     infoBarang item2 = {"Pen", 2000};
//     infoBarang item3 = {"Laptop", 15000000};

//     // Test insertion
//     InsVLast(&userlist.users->wishlist, item1);
//     InsVLast(&userlist.users->wishlist, item2);
//     InsVLast(&userlist.users->wishlist, item3);

//     printf("Wishlist after insertion:\n");
//     PrintList(userlist.users->wishlist);
//     printf("\n");

//     // Test WishlistRemoveI function
//     int indexToRemove; 
//     printf("Enter index to remove: ");
//     scanf("%d", &indexToRemove);
//     printf("Removing item at position %d from the wishlist...\n", indexToRemove);
//     WishlistRemoveI(&userlist, indexToRemove);

//     printf("Wishlist after removal:\n");
//     PrintList(userlist.users->wishlist);
//     printf("\n");

//     // Test removing an invalid index
//     printf("Trying to remove item at position %d (invalid index)...\n", indexToRemove);
// }

/*
gcc Wishlist_Remove_i.c ../../ADT/LinkedList/linkedlist.c ../../ADT/Mesin_Baris/mesinbaris.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Karakter/mesinkarakter.c 
*/