#include <stdio.h>
#include <stdlib.h>
#include "wishlist_show.h"

void WishlistShow(UserList *userList) {
    User *currentUser = &userList->users[userList->currentUserIndex];
    address temp = First(currentUser->wishlist);  
    int counter = 1;
    if (temp == Nill) {
        printf("Wishlist kamu kosong!\n");
        return;
    }
    
    //printf("Berikut adalah isi wishlist-mu:\n");
    //printf("===============================\n");
    printf(">> WISHLIST\n");
    printf("+------------------------------+\n");
    printf("| No | Nama                    |\n");
    printf("+------------------------------+\n");
    //printf("===============================\n");

    address checker;
    while (temp != Nill) {
        boolean isDuplicate = false;
        checker = First(currentUser->wishlist);

        while (checker != temp) {  
            if (IsWordEqual(toKata(Item(temp)), toKata(Item(checker)))) {
                isDuplicate = true;  
                break;
            }
            checker = Next(checker);
        }

        if (!isDuplicate) {
            printf("| %-3d| %-24s|\n", counter, Item(temp));
            counter++;
        } 

        temp = Next(temp);  
    }
    printf("+------------------------------+\n");
    // printf("===============================\n");
}