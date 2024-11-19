#include <stdio.h>
#include "user.h"
#include "../Mesin_Kata/mesinkata.h"
#include "../Mesin_Kata/utils.h"
#include "../../command/load/load.h"
#define DATA_FILE "users.txt"

// Global variable to store all users

boolean isInitialized = false;

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
        printf("User %d: ", i);
        for (int j = 0; j < array.A[i].name.Length; j++) {
            printf("%c", array.A[i].name.TabWord[j]);
        }
        printf(", Password: ");
        for (int j = 0; j < array.A[i].password.Length; j++) {
            printf("%c", array.A[i].password.TabWord[j]);
        }
        printf(", Money: %d\n", array.A[i].money);
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
    ArrayUser userArray;
    if (!isInitialized) {
        userArray = MakeArrayUser();
        loadUsersFromFile();
        isInitialized = true;
    }
}

void addUser(ArrayUser *userArray, User *newUser) {
    InsertLastUser(userArray, *newUser);  // Insert the new user to the in-memory array
    saveUsersToFile(userArray);           // Save the updated list of users to the file
}

void saveUsersToFile(ArrayUser *userArray) {
    FILE *file = fopen(DATA_FILE, "wb");  // Assuming you have a file to store user data
    if (file != NULL) {
        fwrite(&userArray->Neff, sizeof(int), 1, file);
        for (int i = 0; i < userArray->Neff; i++) {
            fwrite(&userArray->A[i], sizeof(User), 1, file);
        }
        fclose(file);
    } else {
        printf("Error: Unable to save users.\n");
    }
}


boolean cariUser(const Word *name) {
    if (!isInitialized) {
        return false;
    }
    ArrayUser userArray;
    IdxType idx = SearchArrayUser(userArray, *name);
    return (idx != -1);
}

// Save user data to the text file

// Load user data from the text file
void loadUsersFromFile() {
    FILE *file = fopen(DATA_FILE, "rb");
    if (file != NULL) {
        STARTFILE(file);

        // Read number of users
        int count = WordToInt(&currentWord);
        ADVWORD();

        for (int i = 0; i < count; i++) {
            User user;

            // Read money
            user.money = WordToInt(&currentWord);
            ADVWORD();

            // Read name
            user.name = currentWord;
            ADVWORD();

            // Read password
            user.password = currentWord;
            ADVWORD();
            ArrayUser userArray;
            // Add to user array
            InsertLastUser(&userArray, user);
        }
        fclose(file);
    }
}

boolean validlogin(const Word *name, const Word *password) {
    if (!isInitialized) {
        initializeUserArray();
    }
    ArrayUser userArray;
    // Search through the list of users to check if the credentials match
    for (int i = 0; i < userArray.Neff; i++) {
        if (isKataEqual(&userArray.A[i].name, name) && isKataEqual(&userArray.A[i].password, password)) {
            return true; // Username and password matched
        }
    }
    return false; // No match found
}
