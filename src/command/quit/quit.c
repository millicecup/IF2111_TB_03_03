#include <stdio.h>
#include "quit.h"
#include "../../ADT/User_Barang/user.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../ADT/Mesin_Baris/mesinbaris.h"

void quit(boolean *isInLoginMenu, UserList list){
    if(*isInLoginMenu == 1){
        printf("Apakah anda sudah melakukan save? (Y/N)\n");
        //char save;
        GetInput();
        if(compareStringsManual(currentInput.TabWord, "Y")){
            *isInLoginMenu = 0;
            printf("Anda berhasil keluar\n");
        } else {
            printf("Anda belum melakukan save\n");
        }
    } else {
        printf("Anda belum login\n");
    }
}
