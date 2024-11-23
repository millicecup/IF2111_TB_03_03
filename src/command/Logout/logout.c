#include <stdio.h>
#include "logout.h"
#include "../../ADT/User_Barang/user.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../ADT/Mesin_Baris/mesinbaris.h"

void logout(boolean *isInside, UserList list){
    if(*isInside == 1){
        printf("Apakah anda sudah melakukan save? (Y/N)\n");
        //char save;
        GetInput();
        if(compareStringsManual(currentInput.TabWord, "Y")){
            *isInside = 0;
            printf("Anda berhasil logout\n");
        } else {
            printf("Anda belum melakukan save\n");
        }
    } else {
        printf("Anda belum login\n");
    }
}
