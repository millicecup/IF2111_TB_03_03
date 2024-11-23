#include <stdio.h>
#include <stdlib.h>
#include "handler/handler.h"

int main() {
    boolean running = true;

    UserList userList;
    BarangList barangList;
    Queue request;
    CreateUserList(&userList);
    CreateBarangList(&barangList, 2);
    CreateEmptyRequest(&request);

    MenuState currentMenu = menuforwelcome;

    while (running) {
        handleMainMenu(&userList, &barangList, &running, &request, &currentMenu);
    }

    FreeBarangList(&barangList);
    return 0;
}

/*
gcc main.c ../ADT/User_Barang/user.c ../ADT/User_Barang/barang.c ../ADT/Mesin_Karakter/mesinkarakter.c ../ADT/Mesin_Kata/mesinkata.c ../ADT/Mesin_Baris/mesinbaris.c ../ADT/work/mesinword.c ../ADT/work/mesinkar.c Start/start.c login/login.c register/register.c save/save.c load/load.c work/tebakangka/tebakangka.c animasi/animasi.c Store_List/Store_List.c -o program
*/

/*
gcc main.c ../ADT/User_Barang/user.c ../ADT/User_Barang/barang.c ../ADT/Mesin_Karakter/mesinkarakter.c ../ADT/Mesin_Kata/mesinkata.c ../ADT/Mesin_Baris/mesinbaris.c Start/start.c login/login.c register/register.c save/save.c load/load.c animasi/animasi.c Store_List/Store_List.c ../ADT/List/list.c ../ADT/queue/queue.c Store_Request/Store_Request.c Store_Remove/Store_Remove.c Store_Supply/Store_Supply.c workchallenge/wordl3/wordl3.c workchallenge/tebakangka/tebakangka.c work/work.c Help/help.c Logout/logout.c -o program
*/