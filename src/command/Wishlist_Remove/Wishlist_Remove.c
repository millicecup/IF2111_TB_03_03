#include <stdio.h>
#include "Wishlist_Remove.h"

void WishlistRemove(UserList *userlist) {
    User *currentuser = &userlist->users[userlist->currentUserIndex];
    Barang item;
    address P;

    // Ask user for the item to remove
    printf("Masukkan nama barang yang akan dihapus: ");
    STARTINPUT(stdin);  // Start input to capture the name

    // Debug: Print the item name entered
    printf("User input item name: %s\n", currentInput.TabWord);

    // Assign the input string to item.name
    assignString(item.name, currentInput.TabWord);

    // Search for the item in the wishlist using SearchX
    P = Search(currentuser->wishlist, item);  // Search the wishlist for the item

    if (P == Nill) {
        // Item not found in wishlist
        printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", item.name);
    } else {
        // Item is found, proceeding to remove it
        printf("Item '%s' found in wishlist. Proceeding to remove...\n", item.name);

        // Initialize the previous and current addresses for removal
        address Prec = NULL;
        address Curr = First(currentuser->wishlist);

        // Traverse to find the item and check if it's the correct one
        while (Curr != Nill) {
            // Compare the current item with the target item
            if (isEqualString(Item(Curr), item.name) && Price(Curr) == item.price) {
                P = Curr;  // Found the item to be removed
                break;     // Exit the loop
            }
            Prec = Curr;
            Curr = Next(Curr);
        }

        // Debug: After traversal
        printf("Prec: %p, Curr: %p\n", (void*)Prec, (void*)Curr);

        if (Curr == Nill) {
            // If Curr is Nill, it means the item was not found
            printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", item.name);
        } else {
            // If Prec is NULL, the item is the first element
            if (Prec == NULL) {
                DelFirst(&currentuser->wishlist, &P);  // Remove the first item
                printf("%s berhasil dihapus dari WISHLIST!\n", item.name);
            } else {
                // Remove the item after the first node
                DelAfter(&currentuser->wishlist, &P, Prec);  
                printf("%s berhasil dihapus dari WISHLIST!\n", item.name);
            }

            // Free memory allocated for the removed item
            Dealokasi(&P);
        }
    }
}


