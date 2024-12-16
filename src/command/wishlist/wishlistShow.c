#include <stdio.h>
#include <stdlib.h>
#include "wishlistShow.h"

void WishlistShow(Wishlist wishlist) {
    address temp = First(wishlist);  
    int counter = 1;
    if (temp == Nil) {
        printf("Wishlist kamu kosong!\n");
        return;
    }
    
    printf("Berikut adalah isi wishlist-mu:\n");

    address checker;
    while (temp != Nil) {
        boolean isDuplicate = false;
        checker = First(wishlist);

        while (checker != temp) {  
            if (IsWordEqual(toKata(Item(temp)), toKata(Item(checker)))) {
                isDuplicate = true;  
                break;
            }
            checker = Next(checker);
        }

        if (!isDuplicate) {
            printf("%d %s\n", counter, Item(temp));
            counter++;
        } 

        temp = Next(temp);  
    }
}

