#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "load.h"
#include "../../ADT/User_Barang/user.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Baris/mesinbaris.h"

// Function to load both BarangList and UserList from a file
void LoadConfig(const char *filename, UserList *userList, BarangList *barangList) {
    FILE *pita = fopen(filename, "r");
    if (pita == NULL) {
        printf("Error: Unable to open file %s.\n", filename);
        return;
    }

    if (userList != NULL) {
        CreateUserList(userList); // Initialize user list if not NULL
    }
    if (barangList != NULL) {
        CreateBarangList(barangList, 2); // Initialize barang list if not NULL
    }

    // Start reading from the file
    STARTFILE(pita);

    // Read number of items (Barang)
    if (barangList != NULL) {
        int num_items = atoi(currentLine.kalimat);
        printf("Jumlah barang: %d\n", num_items);

        for (int i = 0; i < num_items; i++) {
            ADVWORD(); // Read item price
            int price = WordtoNum(currentWord);

            ADVSENTENCE(); // Read item name
            AddBarang(barangList, currentLine.kalimat, price);
        }

        ADVSENTENCE(); // Move to the next line (number of users)
    }

    // Read number of users
    if (userList != NULL) {
        int num_users = atoi(currentLine.kalimat);
        printf("Jumlah pengguna: %d\n", num_users);

        for (int i = 0; i < num_users; i++) {
            ADVWORD(); // Read user money
            int money = WordtoNum(currentWord);

            ADVWORD(); // Read username
            char username[MAX_LEN];
            for (int j = 0; j < currentWord.Length && j < MAX_LEN - 1; j++) {
                username[j] = currentWord.TabWord[j];
            }
            username[currentWord.Length] = '\0';

            ADVWORD(); // Read password
            char password[MAX_LEN];
            for (int j = 0; j < currentWord.Length && j < MAX_LEN - 1; j++) {
                password[j] = currentWord.TabWord[j];
            }
            password[currentWord.Length] = '\0';

            AddUser(userList, username, password, money);
        }
    }

    fclose(pita);
    printf("\nConfig file %s successfully loaded.\n", filename);
}

void Load(UserList *userList, BarangList *barangList) {
    char filename[MAX_LEN];
    Word file;
    printf("Enter the file name to load: ");
    GetInput();
    chartoWord(&file, currentInput.TabWord);
    // strncpy(filename, currentInput.TabWord, currentInput.Length);
    // filename[currentInput.Length] = '\0'; // Null-terminate the filename string
    WordToChar(&file, filename);
    // Pass the entered filename to LoadConfig
    LoadConfig(filename, userList, barangList);
    printf("\nDaftar Barang:\n");
    PrintBarang(barangList);

    printf("\nDaftar Pengguna:\n");
    PrintUsers(userList);
}

/*
int main() {
    UserList userArray;
    CreateUserList(&userArray);

    BarangList barangArray;
    CreateBarangList(&barangArray, 2);
    LoadConfig("../../../save/config.txt", &userArray, &barangArray);

    // Print loaded items and users for verification
    printf("\nDaftar Barang:\n");
    PrintBarang(&barangArray);

    printf("\nDaftar Pengguna:\n");
    PrintUsers(&userArray);

    return 0;
}
*/
/*
gcc load.c ../../ADT/User_Barang/user.c ../../ADT/User_Barang/barang.c ../../ADT/Mesin_Karakter/mesinkarakter.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Baris/mesinbaris.c
*/
