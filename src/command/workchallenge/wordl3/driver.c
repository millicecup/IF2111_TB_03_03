#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../../ADT/boolean.h"
#include "../../../ADT/Mesin_Kata/mesinkata.h"
#include "../../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../../ADT/List/list.h"
#include "wordl3.h"
#include "../../../ADT/User_Barang/user.h"

int main(){
    User user;
    wordl3(user);
    return 0;
}

/*
gcc driver.c wordl3.c ../../../ADT/Mesin_Kata/mesinkata.c ../../../ADT/Mesin_Karakter/mesinkarakter.c ../../../ADT/List/List.c ../../../ADT/Mesin_Baris/mesinbaris.c
*/