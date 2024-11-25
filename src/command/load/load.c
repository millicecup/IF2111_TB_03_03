#include <stdio.h>
#include <stdlib.h>
#include "load.h"
#include "../../ADT/User_Barang/user.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Baris/mesinbaris.h"
#include "../work/work.h"

// Function to load both BarangList and UserList from a file
boolean LoadConfig(const char *filename, UserList *userList, BarangList *barangList) {
    const char *parent_dir = "../../root";
    
    char path[255];
    snprintf(path, sizeof(path), "%s/%s", parent_dir, filename);
    
    FILE *pita = fopen(path, "r");
    
    if (pita == NULL) {
        printf("Error: Unable to open file %s.\n", filename);
        return false;
    }

    if (userList == NULL) {
        CreateUserList(userList); // Initialize user list ga NULL
    }
    if (barangList == NULL) {
        CreateBarangList(barangList, 3); // Initialize barang list ga NULL
    }

    // baca
    STARTFILE(pita);

    // Read Barang
    if (barangList != NULL) {
        int num_items = atoi(currentLine.kalimat);
        // printf("Jumlah barang: %d\n", num_items);

        for (int i = 0; i < num_items; i++) {
            ADVWORD(); // baca price
            int price = WordtoNum(currentWord);

            ADVSENTENCE(); // baca name
            AddBarang(barangList, currentLine.kalimat, price);
        }

        ADVSENTENCE(); // pindah baris
    } else {
        // Skip barang-related lines if BarangList is NULL
        int num_items = atoi(currentLine.kalimat);
        for (int i = 0; i < num_items; i++) {
            ADVSENTENCE(); // Skip each barang entry
        }

        ADVSENTENCE(); // pindah baris
    }

    // Read users
    if (userList != NULL) {
        int num_users = atoi(currentLine.kalimat);
        // printf("Jumlah pengguna: %d\n", num_users);

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
    return true;
}


boolean Load(UserList *userList, BarangList *barangList) {
    char filename[MAX_LEN];
    Word file;
    printf("Enter the file name to load: ");
    GetInput();
    chartoWord(&file, currentInput.TabWord);
    WordToChar(&file, filename);
    LoadConfig(filename, userList, barangList);
    // printf("\nDaftar Barang:\n");
    // PrintBarang(barangList);
    if (LoadConfig(filename, userList, barangList)) {
        return true; // Load berhasil
    } else {
        printf("\nReturning to main menu...\n");
        tunggu(3); 
        return false; // Load gagal
    }
    // printf("\nDaftar Pengguna:\n");
    // PrintUsers(userList);
}


// int main() {
//     UserList userArray;
//     CreateUserList(&userArray);

//     BarangList barangArray;
//     CreateBarangList(&barangArray, 2);
//     Load(&userArray, &barangArray);
//     //LoadConfig("../../../save/config.txt", &userArray, &barangArray);

//     // Print loaded items and users for verification
//     printf("\nDaftar Barang:\n");
//     PrintBarang(&barangArray);

//     printf("\nDaftar Pengguna:\n");
//     PrintUsers(&userArray);

//     return 0;
// }

//gcc load.c ../../ADT/User_Barang/user.c ../../ADT/User_Barang/barang.c ../../ADT/Mesin_Karakter/mesinkarakter.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Baris/mesinbaris.c

