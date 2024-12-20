#include <stdio.h>
#include "Wishlist_Remove.h"
int main() {
    // Initialize user list and create an empty wishlist for the current user
    UserList userlist;
    CreateEmptyWishlist(&userlist.users->wishlist);

    // Create sample items to add to the wishlist
    infoBarang item1 = {"Book", 50000};
    infoBarang item2 = {"Pen", 2000};
    infoBarang item3 = {"Laptop", 15000000};

    // Add the items to the wishlist
    InsVLast(&userlist.users->wishlist, item1);
    InsVLast(&userlist.users->wishlist, item2);
    InsVLast(&userlist.users->wishlist, item3);

    // Display the wishlist after adding items
    printf("Wishlist setelah penambahan:\n");
    PrintList(userlist.users->wishlist);
    printf("\n");

    // Call the WishlistRemove function to test item removal
    WishlistRemove(&userlist);

    // Display the wishlist after removal
    printf("Wishlist setelah penghapusan:\n");
    PrintList(userlist.users->wishlist);
    printf("\n");

    // Test removing an item that does not exist
    printf("Mencoba menghapus item yang tidak ada:\n");
    WishlistRemove(&userlist);

    return 0;
}
