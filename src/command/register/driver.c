#include <stdio.h>

#include "register.h"

int main(){
    UserList userArray;
    CreateUserList(&userArray);
    registerUser(&userArray);
    return 0;
}

/*
gcc driver.c ../../ADT/User_Barang/user.c ../../ADT/User_Barang/barang.c ../../ADT/Mesin_Karakter/mesinkarakter.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Kata/mesinkarakterv2.c ../../ADT/Mesin_Baris/mesinbaris.c register.c ../Start/start.c ../save/save.c -o program
*/