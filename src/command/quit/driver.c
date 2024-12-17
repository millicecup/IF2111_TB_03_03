#include <stdio.h>
#include "quit.h"
#include "../../ADT/User_Barang/user.h"

/*
gcc driver.c logout.c ../../ADT/User_Barang/user.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Karakter/mesinkarakter.c ../../ADT/Mesin_Baris/mesinbaris.c
*/

int main() {
    boolean loggedIn = 1; 
    UserList userList;    
    CreateUserList(&userList); 

    User currentUser = {"testuser", "password", 100}; 

    printf("=== Testing Logout Function ===\n");
    printf("Current User: %s\n", currentUser.name);
    quit(&loggedIn, userList);

    if (!loggedIn) {
        printf("Logged-out successfully.\n");
    } else {
        printf("Still logged-in.\n");
    }

    return 0;
}
