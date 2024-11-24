#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "command/handler/handler.h"

int main() {
    boolean running = true;

    UserList userList;
    BarangList barangList;
    Queue request;
    CreateUserList(&userList);
    CreateBarangList(&barangList, 10);
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
gcc main.c command/handler/handler.c command/Logout/logout.c command/Help/help.c command/animasi/animasi.c command/load/load.c command/login/login.c command/register/register.c command/save/save.c command/Start/start.c command/Store_List/Store_List.c command/Store_Remove/Store_Remove.c command/Store_Request/Store_Request.c command/Store_Supply/Store_Supply.c command/work/work.c command/workchallenge/tebakangka/tebakangka.c command/workchallenge/wordl3/wordl3.c ADT/List/list.c ADT/Mesin_Baris/mesinbaris.c ADT/Mesin_Karakter/mesinkarakter.c ADT/Mesin_Kata/mesinkata.c ADT/queue/queue.c ADT/User_Barang/user.c ADT/User_Barang/barang.c
*/