#include <stdio.h>
#include "Wishlist_Remove.h"
int main() {
    // Assuming UserList is defined correctly and initialized.
    UserList userlist;  
    CreateEmptyWishlist(&userlist.users->wishlist);

    // Create some sample items to add to the wishlist
    Barang item1 = {"Book", 50000};
    Barang item2 = {"Pen", 2000};
    Barang item3 = {"Laptop", 15000000};

    // Test insertion
    InsVLast(&userlist.users->wishlist, item1);
    InsVLast(&userlist.users->wishlist, item2);
    InsVLast(&userlist.users->wishlist, item3);

    printf("Wishlist after insertion:\n");
    PrintList(userlist.users->wishlist);
    printf("\n");

    // Test WishlistRemove function
    WishlistRemove(&userlist);

    printf("Wishlist after removal:\n");
    PrintList(userlist.users->wishlist);
    printf("\n");

    // Test removing an invalid index (to simulate the error message)
    // This code should be handled already by the logic above
}