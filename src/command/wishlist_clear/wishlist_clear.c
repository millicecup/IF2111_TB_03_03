#include "wishlist_clear.h"
#include <stdio.h>


void WishlistClear(UserList *userArray, char *username) {
    int i = 0;
    boolean found = false;

    //printf("Debug: Clearing wishlist for user: %s\n", username);
    //printf("Debug: UserList contains %d users\n", userArray->count);

    // Print all users in the UserList for debugging
    for (int j = 0; j < userArray->count; j++) {
        printf("User %d: %s\n", j + 1, userArray->users[j].name);
    }

    // Search for the user in the UserList
    while (i < userArray->count && !found) {
        printf("Comparing input: '%s' with stored name: '%s'\n", username, userArray->users[i].name);
        if (isEqualString(userArray->users[i].name, username)) {
            found = true;
        } else {
            i++;
        }
    }

    if (found) {
        // Clear the wishlist for the found user
        CreateEmptyWishlist(&userArray->users[i].wishlist);
        printf("Wishlist %s berhasil dihapus\n", username);
    } else {
        // Print an error if the user is not found
        printf("User %s tidak ditemukan\n", username);
    }
}
