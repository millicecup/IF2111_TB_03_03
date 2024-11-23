#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/boolean.h"
#include "../../ADT/List/list.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Baris/mesinbaris.h"
#include "../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../ADT/User_Barang/user.h"
#include "work.h"

#include <stdio.h>
#include "../../ADT/User_Barang/user.h"
#include "work.h"

int main() {
    // Initialize UserList
    UserList userList;
    CreateUserList(&userList);

    // Add a test user
    AddUser(&userList, "testuser", "password123", 5000);

    // Set the current user to the first user in the list
    userList.currentUserIndex = 0; // Assuming the user logs in successfully
    printf("User %s is logged in. Current balance: %d\n", 
           userList.users[userList.currentUserIndex].name, 
           userList.users[userList.currentUserIndex].money);

    // Call the work function
    printf("\n--- WORK MENU ---\n");
    work(&userList);

    // Display updated user balance
    printf("\nUpdated balance for user %s: %d\n", 
           userList.users[userList.currentUserIndex].name, 
           userList.users[userList.currentUserIndex].money);

    return 0;
}


// gcc -o work.exe work_driver.c work.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Karakter/mesinkarakter.c ../../ADT/Mesin_Baris/mesinbaris.c  ../../ADT/List/list.c 