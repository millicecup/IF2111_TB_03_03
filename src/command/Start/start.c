#include <stdio.h>
#include <stdlib.h>

#include "../../ADT/User_Barang/user.h"  // ADT User
#include "../../ADT/User_Barang/barang.h"  // ADT Barang
#include "../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Baris/mesinbaris.h"

// Function to load default configuration and populate UserList and BarangList
int start(UserList *userList, BarangList *barangList) {
    FILE *pita = fopen("../../save/config.txt", "r");
    if (pita == NULL) {
        printf("Error: Unable to open default configuration file.\n");
        return 1; // Return error code
    }

    // Initialize UserList and BarangList
    CreateUserList(userList);
    CreateBarangList(barangList, 10); // Initial capacity 2 for BarangList

    // Start reading the file
    STARTFILE(pita);

    // Read the number of items (Barang)
    int num_items = atoi(currentLine.kalimat);
    //printf("Jumlah barang: %d\n", num_items);

    for (int i = 0; i < num_items; i++) {
        ADVWORD();
        int price = WordtoNum(currentWord);
        ADVSENTENCE();
        AddBarang(barangList, currentLine.kalimat, price);
    }

    // Read the number of users
    ADVSENTENCE();
    int num_users = atoi(currentLine.kalimat);
    //printf("Jumlah pengguna: %d\n", num_users);

    for (int i = 0; i < num_users; i++) {
        // Read user money
        ADVWORD();
        int money = WordtoNum(currentWord);

        // Read username
        ADVWORD();
        char username[MAX_LEN];
        for (int j = 0; j < currentWord.Length && j < MAX_LEN - 1; j++) {
            username[j] = currentWord.TabWord[j];
        }
        username[currentWord.Length] = '\0'; // Null-terminate username

        // Read password
        ADVWORD();
        char password[MAX_LEN];
        for (int j = 0; j < currentWord.Length && j < MAX_LEN - 1; j++) {
            password[j] = currentWord.TabWord[j];
        }
        password[currentWord.Length] = '\0'; // Null-terminate password

        // Add user to UserList
        AddUser(userList, username, password, money);
    }

    fclose(pita);

    // Print loaded items for verification
    // printf("\nDaftar Barang:\n");
    // PrintBarang(barangList);

    // printf("\nDaftar Pengguna:\n");
    // PrintUsers(userList);

    printf("\nDefault configuration successfully loaded. PURRMART is ready.\n");
    return 0; // Success
}
