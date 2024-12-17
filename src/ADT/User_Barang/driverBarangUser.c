#include <stdio.h>
#include "barang.h"
#include "user.h"
/*
gcc user.c barang.c driverBarangUser.c ../Mesin_Kata/mesinkata.c ../Mesin_Karakter/mesinkarakter.c ../Mesin_Baris/mesinbaris.c 
*/
int main() {
    printf("=== Testing User Functions ===\n");
    // Create User List
    UserList userList;
    CreateUserList(&userList);
    printf("User list created. Is it empty? %s\n", IsUserListEmpty(&userList) ? "Yes" : "No");

    // Add Users
    AddUser(&userList, "admin", "password123", 500);
    AddUser(&userList, "user1", "pass1", 100);
    AddUser(&userList, "user2", "pass2", 200);
    PrintUsers(&userList);

    // Modify User Money
    printf("\nModifying money for 'user1'...\n");
    ModifyUserMoney(&userList, "user1", 300);
    PrintUsers(&userList);

    // Add User via InsertLastUser
    User newUser = {"user3", "pass3", 150};
    InsertLastUser(&userList, newUser);
    printf("\nAdded 'user3' via InsertLastUser:\n");
    PrintUsers(&userList);

    // Search User
    printf("\nSearching for 'user2'...\n");
    int found = -1;
    for (int i = 0; i < userList.count; i++) {
        if (isEqualString(userList.users[i].name, "user2") == 0) {
            found = i;
            break;
        }
    }
    printf("User 'user2' is %sfound.\n", (found != -1) ? "" : "not ");

    // Testing ManualStringCopy
    printf("\nTesting ManualStringCopy...\n");
    char dest[100];
    ManualStringCopy(dest, "Test String");
    printf("Copied string: %s\n", dest);

    printf("\n=== Testing Barang Functions ===\n");
    // Create Barang List
    BarangList barangList;
    CreateBarangList(&barangList, 2);
    printf("Barang list created. Is it empty? %s\n", IsEmpty(barangList) ? "Yes" : "No");

    // Add Barang
    AddBarang(&barangList, "Item1", 1000);
    AddBarang(&barangList, "Item2", 2000);
    AddBarang(&barangList, "Item3", 3000);
    printf("Barang list after adding items:\n");
    PrintBarang(&barangList);

    // Search for Barang
    printf("\nSearching for 'Item2'...\n");
    Word searchName;
    stringToWord("Item2", &searchName);
    int idx = SearchArrayDin(barangList, searchName);
    if (idx != -1) {
        printf("Item 'Item2' found at index %d.\n", idx);
    } else {
        printf("Item 'Item2' not found.\n");
    }

    // Insert Barang at specific position
    printf("\nInserting 'NewItem' at index 1...\n");
    Barang newBarang;
    ManualStringCopy(newBarang.name, "NewItem");
    newBarang.price = 2500;
    InsertAt(&barangList, newBarang, 1);
    PrintBarang(&barangList);

    // Delete Barang
    printf("\nDeleting first barang...\n");
    DeleteFirst(&barangList);
    PrintBarang(&barangList);

    // Copy Barang List
    printf("\nCopying barang list...\n");
    BarangList copiedList = CopyArrayDin(barangList);
    printf("Copied list:\n");
    PrintBarang(&copiedList);

    // Reverse Barang List
    printf("\nReversing barang list...\n");
    ReverseArrayDin(&barangList);
    PrintBarang(&barangList);

    // Free memory
    printf("\nFreeing memory for barang lists...\n");
    FreeBarangList(&barangList);
    FreeBarangList(&copiedList);
    printf("Memory freed successfully.\n");

    return 0;
}
