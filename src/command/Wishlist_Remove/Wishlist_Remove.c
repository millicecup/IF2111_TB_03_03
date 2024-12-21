#include <stdio.h>
#include <stdlib.h>
#include "Wishlist_Remove.h"

void WishlistRemove(UserList *userlist) {
    User *currentUser = &userlist->users[userlist->currentUserIndex];
    Barang item;

    
    printf("Masukkan nama barang yang akan dihapus: ");
    STARTINPUT(stdin);

    
    assignString(item.name, currentInput.TabWord);

    
    if (!SearchX(currentUser->wishlist, item)) {
        
        printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", item.name);
        return;
    }

    
    address prev = NULL;  
    address curr = First(currentUser->wishlist);  

    while (curr != NULL && !(isEqualString(Item(curr), item.name))) {
        prev = curr;  
        curr = Next(curr); 
    }

    if (prev == NULL) {
        
        DelFirst(&currentUser->wishlist, &curr);
    } else {
        
        DelAfter(&currentUser->wishlist, &curr, prev);
    }

    
    Dealokasi(&curr);

    // Success message
    printf("Berhasil menghapus barang %s dari WISHLIST!\n", item.name);
}



// int main() {
//     // Initialize user list and create an empty wishlist for the current user
//     UserList userlist;
//     CreateEmptyWishlist(&userlist.users->wishlist);

//     // Create sample items to add to the wishlist
//     infoBarang item1 = {"Book", 50000};
//     infoBarang item2 = {"Pen", 2000};
//     infoBarang item3 = {"Laptop", 15000000};

//     // Add the items to the wishlist
//     InsVLast(&userlist.users->wishlist, item1);
//     InsVLast(&userlist.users->wishlist, item2);
//     InsVLast(&userlist.users->wishlist, item3);

//     // Display the wishlist after adding items
//     printf("Wishlist setelah penambahan:\n");
//     PrintList(userlist.users->wishlist);
//     printf("\n");

//     // Call the WishlistRemove function to test item removal
//     WishlistRemove(&userlist);

//     // Display the wishlist after removal
//     printf("Wishlist setelah penghapusan:\n");
//     PrintList(userlist.users->wishlist);
//     printf("\n");

//     return 0;
// }
