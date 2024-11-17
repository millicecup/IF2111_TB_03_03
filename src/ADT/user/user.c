#include <stdio.h>
#include "user.h"
#include "../Mesin_Kata/mesinkata.h"
#include "../List/arrayuser.h"
#include <string.h>

#define DATA_FILE "users.txt"

// Global variable to store all users
static ArrayDin userArray;
static boolean isInitialized = false;

void initUser(User *user, const Word *name, const Word *password) {
    user->name = *name;
    user->password = *password;
    user->money = 0;
}

void printUser(const User *user) {
    printf("Name: ");
    for (int i = 0; i < user->name.Length; i++) {
        printf("%c", user->name.TabWord[i]);
    }
    printf("\nMoney: %d\n", user->money);
}

void initializeUserArray() {
    if (!isInitialized) {
        userArray = MakeArrayDin();
        loadUsersFromFile();
        isInitialized = true;
    }
}

void addUser(const User *user) {
    if (!isInitialized) {
        initializeUserArray();
    }
    InsertLast(&userArray, *user);
    saveUsersToFile();
}

boolean cariUser(const Word *name) {
    if (!isInitialized) {
        return false;
    }
    IdxType idx = SearchArrayDin(userArray, *name);
    return (idx != -1);
}

void saveUsersToFile() {
    FILE *file = fopen(DATA_FILE, "wb");
    if (file != NULL) {
        fwrite(&userArray.Neff, sizeof(int), 1, file);
        fwrite(userArray.A, sizeof(User), userArray.Neff, file);
        fclose(file);
    }
}

void loadUsersFromFile() {
    FILE *file = fopen(DATA_FILE, "rb");
    if (file != NULL) {
        int count;
        fread(&count, sizeof(int), 1, file);
        for (int i = 0; i < count; i++) {
            User user;
            fread(&user, sizeof(User), 1, file);
            InsertLast(&userArray, user);
        }
        fclose(file);
    }
}
