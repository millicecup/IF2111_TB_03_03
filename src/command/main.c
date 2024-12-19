#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../ADT/User_Barang/user.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/Mesin_Baris/mesinbaris.h"
#include "../ADT/User_Barang/barang.h"
#include "../ADT/queue/queue.h"
#include "../ADT/Stack/stack.h"
#include "../ADT/LinkedList/linkedlist.h"
#include "../ADT/SetMap/setmap.h"

#include "animasi/animasi.h"
#include "Start/start.h"
#include "load/load.h"
#include "login/login.h"
#include "register/register.h"
#include "save/save.h"
#include "work/work.h"
#include "workchallenge/tebakangka/tebakangka.h"
#include "workchallenge/wordl3/wordl3.h"
#include "Store_List/Store_List.h"
#include "Store_Request/Store_Request.h"
#include "Store_Supply/Store_Supply.h"
#include "Store_Remove/Store_Remove.h"
#include "Wishlist_Clear/wishlist_clear.h"
#include "Wishlist_Remove_i/Wishlist_Remove_i.h"
#include "Wishlist_Remove/Wishlist_Remove.h"
#include "Help/help.h"
#include "Logout/logout.h"
#include "quit/quit.h"
#include "handler/handler.h"

// Main Function
int main() {
    boolean running = true;

    UserList userList;
    BarangList barangList;
    Queue request;
    Keranjang cart;
    Wishlist wishlist;
    History history;
    CreateUserList(&userList);
    CreateBarangList(&barangList, 2);
    CreateEmptyRequest(&request);
    CreateEmptyBasket(&cart);
    CreateEmptyWishlist(&wishlist);
    CreateEmptyStack(&history);

    MenuState currentMenu = menuforwelcome;

    while (running) {
        handleMainMenu(&userList, &barangList, &running, &request, &cart, &wishlist, &history, &currentMenu);
    }

    FreeBarangList(&barangList);
    return 0;
}


/*
gcc main.c ../ADT/Stack/stack.c ../ADT/LinkedList/linkedlist.c ../ADT/User_Barang/user.c ../ADT/User_Barang/barang.c ../ADT/Mesin_Karakter/mesinkarakter.c ../ADT/Mesin_Kata/mesinkata.c ../ADT/Mesin_Baris/mesinbaris.c Start/start.c login/login.c register/register.c save/save.c load/load.c animasi/animasi.c Store_List/Store_List.c ../ADT/List/list.c ../ADT/queue/queue.c Store_Request/Store_Request.c Store_Remove/Store_Remove.c Store_Supply/Store_Supply.c workchallenge/wordl3/wordl3.c workchallenge/tebakangka/tebakangka.c work/work.c Help/help.c Logout/logout.c quit/quit.c handler/handler.c ../ADT/SetMap/setmap.c Cart_Add/cart_add.c Cart_Remove/cart_remove.c Cart_Show/cart_show.c Cart_Pay/cart_pay.c History/history.c -o program
*/