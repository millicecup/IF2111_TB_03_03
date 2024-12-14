#include <stdio.h>
#include <stdlib.h>
#include "load.h"
#include "../../ADT/User_Barang/user.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Baris/mesinbaris.h"
#include "../work/work.h"
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/Stack/stack.h"

boolean LoadConfig(const char *filename, UserList *userList, BarangList *barangList) {
    const char *parent_dir = "../../root/";
    char path[255];
    snprintf(path, sizeof(path), "%s/%s", parent_dir, filename);

    FILE *pita = fopen(path, "r");
    if (pita == NULL) {
        printf("Error: Unable to open file %s.\n", filename);
        return false;
    }

    STARTFILE(pita);

    // 1. Read Barang List
    int num_items = atoi(currentLine.kalimat);
    //printf("Loading barang list...\n");
    if (num_items < 0) {
        //printf("Error: Invalid number of items.\n");
        fclose(pita);
        return false;
    }
    for (int i = 0; i < num_items; i++) {
        ADVWORD(); // Read price
        int price = WordtoNum(currentWord);

        ADVSENTENCE(); // Read item name
        AddBarang(barangList, currentLine.kalimat, price);
        //printf("Added barang: %s, Price: %d\n", currentLine.kalimat, price);
    }
    ADVSENTENCE();
    //printf("Done loading barang list.\n");

    // 2. Read Users
    int num_users = atoi(currentLine.kalimat);
    //printf("Loading user list...\n");
    if (num_users < 0) {
        printf("Error: Invalid number of users.\n");
        fclose(pita);
        return false;
    }
    for (int i = 0; i < num_users; i++) {
        ADVWORD(); // Read user money
        int money = WordtoNum(currentWord);

        ADVWORD(); // Read username
        char username[MAX_LEN];
        WordToChar(&currentWord, username);

        ADVWORD(); // Read password
        char password[MAX_LEN];
        WordToChar(&currentWord, password);

        User user;
        ManualStringCopy(user.name, username);
        ManualStringCopy(user.password, password);
        user.money = money;
        CreateEmptyStack(&user.riwayat_pembelian);
        CreateEmptyWishlist(&user.wishlist);

        // 2.1. Load Transaction History
        ADVSENTENCE();
        int num_history = atoi(currentLine.kalimat);
        //printf("Loading transaction history for user %s...\n", username);
        for (int j = 0; j < num_history; j++) {
            ADVWORD(); // Read price
            int price = WordtoNum(currentWord);

            ADVSENTENCE(); // Read item name
            char historyItem[MAX_LEN];
            ManualStringCopy(historyItem, currentLine.kalimat);

            PushStack(&user.riwayat_pembelian, historyItem, price, 1);
            //printf("Added to history: %s, Price: %d\n", historyItem, price);
        }

        // 2.2. Load Wishlist
        ADVSENTENCE();
        int num_wishlist = atoi(currentLine.kalimat);
        //printf("Loading wishlist for user %s...\n", username);
        for (int j = 0; j < num_wishlist; j++) {
            ADVSENTENCE();
            infoBarang newBarang;
            ManualStringCopy(newBarang.name, currentLine.kalimat);
            newBarang.price = 0;

            InsVLast(&user.wishlist, newBarang);
            //printf("Added to wishlist: %s\n", newBarang.name);
        }

        addUser(userList, &user);
        //printf("Done loading user %s.\n", username);
    }

    fclose(pita);
    printf("Config file %s successfully loaded.\n", filename);
    return true;
}


boolean Load(UserList *userList, BarangList *barangList) {
    char filename[MAX_LEN];
    Word file;
    printf("Enter the file name to load: ");
    GetInput();
    chartoWord(&file, currentInput.TabWord);
    WordToChar(&file, filename);

    if (LoadConfig(filename, userList, barangList)) {
        printf("\nConfig successfully loaded.\n");
        return true;
    } else {
        printf("\nReturning to main menu...\n");
        return false;
    }
}

// main
// int main() {
//     UserList userArray;
//     CreateUserList(&userArray);

//     BarangList barangArray;
//     CreateBarangList(&barangArray, 2);

//     if (Load(&userArray, &barangArray)) {
//         // for (int i = 0; i < userArray.count; i++) {
//         //     CreateBarangList(&barangArray, 2);
//         //     CreateUserList(&userArray);  
//         printf("\nDaftar Barang:\n");
//         PrintBarang(&barangArray);

//         printf("\nDaftar Pengguna:\n");
//         PrintUsers(&userArray);  // print
//     }

//     return 0;
// }

/*
 gcc load.c ../../ADT/Stack/stack.c ../../ADT/User_Barang/user.c ../../ADT/LinkedList/linkedlist.c ../../ADT/User_Barang/barang.c ../../ADT/Mesin_Karakter/mesinkarakter.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Baris/mesinbaris.c
*/