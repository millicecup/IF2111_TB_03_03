#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../ADT/User_Barang/user.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "save.h" // Ensure save function is included

int main() {
    BarangList barangList;
    UserList userList;

    // Create empty lists
    CreateBarangList(&barangList, 2);
    CreateUserList(&userList);

    // Collect Barang data from user
    int barangCount;
    printf("Enter the number of barang: ");
    scanf("%d", &barangCount);
    getchar(); // Consume the newline character

    for (int i = 0; i < barangCount; i++) {
        char name[MAX_LEN];
        int price;
        printf("Enter name of barang %d: ", i + 1);
        fgets(name, MAX_LEN, stdin);
        name[strcspn(name, "\n")] = '\0'; // Remove newline character
        printf("Enter price of barang %d: ", i + 1);
        scanf("%d", &price);
        getchar(); // Consume the newline character
        AddBarang(&barangList, name, price);
    }

    // Collect User data from user
    int userCount;
    printf("Enter the number of users: ");
    scanf("%d", &userCount);
    getchar(); // Consume the newline character

    for (int i = 0; i < userCount; i++) {
        char name[MAX_LEN];
        char password[MAX_LEN];
        int money;
        printf("Enter name of user %d: ", i + 1);
        fgets(name, MAX_LEN, stdin);
        name[strcspn(name, "\n")] = '\0'; // Remove newline character
        printf("Enter password of user %d: ", i + 1);
        fgets(password, MAX_LEN, stdin);
        password[strcspn(password, "\n")] = '\0'; // Remove newline character
        printf("Enter money of user %d: ", i + 1);
        scanf("%d", &money);
        getchar(); // Consume the newline character
        AddUser(&userList, name, password, money);
    }

    // Save the data to a file
    SaveToFile("dummy.txt", &barangList, &userList);

    // Free memory allocated for BarangList
    FreeBarangList(&barangList);

    return 0;
}


/* 
gcc driver.c ../../ADT/User_Barang/user.c ../../ADT/User_Barang/barang.c ../../ADT/Mesin_Karakter/mesinkarakter.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Kata/mesinkarakterv2.c ../../ADT/Mesin_Baris/mesinbaris.c save.c ../Start/start.c -o program
*/