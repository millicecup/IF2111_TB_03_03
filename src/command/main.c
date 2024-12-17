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
    CreateUserList(&userList);
    CreateBarangList(&barangList, 2);
    CreateEmptyRequest(&request);
    CreateEmptyBasket(&cart);

    MenuState currentMenu = menuforwelcome;

    while (running) {
        handleMainMenu(&userList, &barangList, &running, &request, &currentMenu);
    }

    FreeBarangList(&barangList);
    return 0;
}

