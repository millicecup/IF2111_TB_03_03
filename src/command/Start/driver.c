#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/User_Barang/user.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "start.h"
#include "../login/login.h"

int main() {
    UserList userArray;
    CreateUserList(&userArray);

    BarangList barangArray;
    CreateBarangList(&barangArray, 2);

    // Call the start function to load data
    start(&userArray, &barangArray);
    login(&userArray);

    return 0;
}

/*
 gcc driver.c ../login/login.c ../../ADT/User_Barang/user.c ../../ADT/User_Barang/barang.c ../../ADT/Mesin_Karakter/mesinkarakter.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Baris/mesinbaris.c start.c ../load/load.c -o program

*/