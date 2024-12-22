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
            //printf("Anda berhasil keluar\n");
            //printf("Exiting PURRMART. Goodbye!\n");

        } else {
            printf("Anda belum melakukan save\n");
            printf("Silahkan lakukan save file terlebih dahulu\n");
            printf("Mengarahkan anda kembali...\n");
        }
    } else {
        printf("Anda belum login\n");
    }
}
