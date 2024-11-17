#include <stdio.h>
#include "user.h"
#include "../Mesin_Kata/mesinkata.h"

#define DATA_FILE "users.txt"

// Global variable to store all users
static ArrayUser userArray;
static boolean isInitialized = false;

ArrayUser MakeArrayUser() {
    ArrayUser array;
    array.Neff = 0; // Start with an empty array
    return array;
}

boolean IsEmptyUser(ArrayUser array) {
    return (array.Neff == 0);
}

int LengthUser(ArrayUser array) {
    return array.Neff;
}

User GetUser(ArrayUser array, int i) {
    if (i >= 0 && i < array.Neff) {
        return array.A[i];
    }
    // Handle error if the index is invalid
    User errorUser = {{"INVALID"}, {"INVALID"}, -1};
    return errorUser;
}

int GetUserCapacity() {
    return MAX_USERS;
}

void InsertAtUser(ArrayUser *array, User el, int i) {
    if (i >= 0 && i <= array->Neff && array->Neff < MAX_USERS) {
        for (int j = array->Neff; j > i; j--) {
            array->A[j] = array->A[j - 1];
        }
        array->A[i] = el;
        array->Neff++;
    }
}

void InsertLastUser(ArrayUser *array, User el) {
    if (array->Neff < MAX_USERS) {
        array->A[array->Neff] = el;
        array->Neff++;
    }
}

void InsertFirstUser(ArrayUser *array, User el) {
    if (array->Neff < MAX_USERS) {
        for (int i = array->Neff; i > 0; i--) {
            array->A[i] = array->A[i - 1];
        }
        array->A[0] = el;
        array->Neff++;
    }
}

void DeleteAtUser(ArrayUser *array, int i) {
    if (i >= 0 && i < array->Neff) {
        for (int j = i; j < array->Neff - 1; j++) {
            array->A[j] = array->A[j + 1];
        }
        array->Neff--;
    }
}

void DeleteLastUser(ArrayUser *array) {
    if (array->Neff > 0) {
        array->Neff--;
    }
}

void DeleteFirstUser(ArrayUser *array) {
    if (array->Neff > 0) {
        for (int i = 0; i < array->Neff - 1; i++) {
            array->A[i] = array->A[i + 1];
        }
        array->Neff--;
    }
}

void PrintArrayUser(ArrayUser array) {
    for (int i = 0; i < array.Neff; i++) {
        printf("User %d: %s, Password: %s, Money: %d\n", i, array.A[i].name, array.A[i].password, array.A[i].money);
    }
}

ArrayUser CopyArrayUser(ArrayUser array) {
    ArrayUser newArray;
    newArray.Neff = array.Neff;
    for (int i = 0; i < array.Neff; i++) {
        newArray.A[i] = array.A[i];
    }
    return newArray;
}

int SearchArrayUser(ArrayUser array, Word name) {
    for (int i = 0; i < array.Neff; i++) {
        if (isKataEqual(&array.A[i].name, &name)) {
            return i;  // Found the user at index i
        }
    }
    return -1;  // User not found
}

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
        userArray = MakeArrayUser();
        loadUsersFromFile();
        isInitialized = true;
    }
}

void addUser(const User *user) {
    if (!isInitialized) {
        initializeUserArray();
    }
    InsertLastUser(&userArray, *user);
    saveUsersToFile();
}

boolean cariUser(const Word *name) {
    if (!isInitialized) {
        return false;
    }
    IdxType idx = SearchArrayUser(userArray, *name);
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
            InsertLastUser(&userArray, user);
        }
        fclose(file);
    }
}
