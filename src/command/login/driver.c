#include <stdio.h>
#include "../../ADT/User_Barang/user.h"
#include "login.h"
#include "../load/load.h"

int main() {
    UserList userArray;
    CreateUserList(&userArray); // Initialize the UserList

    printf("=== User Login ===\n");
    //LoadConfig("../../../save/config.txt", &userArray, &barangArray);
    // Call the login function
    login(&userArray);

    return 0;
}

/*
 Compilation Command:
 gcc driver.c login.c ../../ADT/User_Barang/user.c ../../ADT/User_Barang/barang.c ../../ADT/Mesin_Karakter/mesinkarakter.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Baris/mesinbaris.c ../load/load.c -o program
 */
