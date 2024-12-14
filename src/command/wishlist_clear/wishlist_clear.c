#include "wishlist_clear.h"
#include <stdio.h>

WishlistClear(UserList *userArray, char *username){
    int i = 0;
    boolean found = false;
    while (i < userArray->count && !found){
        if (strcmp(userArray->users[i].name, username) == 0){
            found = true;
        } else {
            i++;
        }
    }
    if (found){
        userArray->users[i].wishlist = NULL;
        printf("Wishlist %s berhasil dihapus\n", username);
    } else {
        printf("User %s tidak ditemukan\n", username);
    }
}