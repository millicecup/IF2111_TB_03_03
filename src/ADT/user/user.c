#include <stdio.h>
#include "user.h"
#include "../Mesin_Kata/mesinkata.h"
#include "../Mesin_Kata/utils.h"
#include "../../command/load/load.h"
#define DATA_FILE "users.txt"

// Global variable to store all users
ArrayUser userArray;  // Global array to store users
boolean isInitialized = false;  // Flag to check if userArray has been initialized

// Initialize user array with zero users
ArrayUser MakeArrayUser() {
    ArrayUser array;
    array.Neff = 0; // Start with an empty array
    return array;
}

// Check if user array is empty
boolean IsEmptyUser(ArrayUser array) {
    return (array.Neff == 0);
}

// Get the length (number of users) in the array
int LengthUser(ArrayUser array) {
    return array.Neff;
}

// Get a specific user from the array by index
User GetUser(ArrayUser array, int i) {
    if (i >= 0 && i < array.Neff) {
        return array.A[i];
    }
    // Handle error if the index is invalid
    User errorUser = {{"INVALID"}, {"INVALID"}, -1};
    return errorUser;
}

// Get the maximum capacity of the user array
int GetUserCapacity() {
    return MAX_USERS;
}

// Insert a user at a specific position in the array
void InsertAtUser(ArrayUser *array, User el, int i) {
    if (i >= 0 && i <= array->Neff && array->Neff < MAX_USERS) {
        for (int j = array->Neff; j > i; j--) {
            array->A[j] = array->A[j - 1];
        }
        array->A[i] = el;
        array->Neff++;
    }
}

// Insert a user at the end of the array
void InsertLastUser(ArrayUser *array, User el) {
    if (array->Neff < MAX_USERS) {
        array->A[array->Neff] = el;
        array->Neff++;
    }
}

// Insert a user at the beginning of the array
void InsertFirstUser(ArrayUser *array, User el) {
    if (array->Neff < MAX_USERS) {
        for (int i = array->Neff; i > 0; i--) {
            array->A[i] = array->A[i - 1];
        }
        array->A[0] = el;
        array->Neff++;
    }
}

// Delete a user at a specific position in the array
void DeleteAtUser(ArrayUser *array, int i) {
    if (i >= 0 && i < array->Neff) {
        for (int j = i; j < array->Neff - 1; j++) {
            array->A[j] = array->A[j + 1];
        }
        array->Neff--;
    }
}

// Delete the last user from the array
void DeleteLastUser(ArrayUser *array) {
    if (array->Neff > 0) {
        array->Neff--;
    }
}

// Delete the first user from the array
void DeleteFirstUser(ArrayUser *array) {
    if (array->Neff > 0) {
        for (int i = 0; i < array->Neff - 1; i++) {
            array->A[i] = array->A[i + 1];
        }
        array->Neff--;
    }
}

// Print all users in the array
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

// Copy the array of users
ArrayUser CopyArrayUser(ArrayUser array) {
    ArrayUser newArray;
    newArray.Neff = array.Neff;
    for (int i = 0; i < array.Neff; i++) {
        newArray.A[i] = array.A[i];
    }
    return newArray;
}

// Search for a user in the array by name
int SearchArrayUser(ArrayUser array, Word name) {
    for (int i = 0; i < array.Neff; i++) {
        if (isKataEqual(&array.A[i].name, &name)) {
            return i;  // Found the user at index i
        }
    }
    return -1;  // User not found
}

// Initialize a new user with the given name, password, and initial money
void initUser(User *user, const Word *name, const Word *password) {
    user->name = *name;
    user->password = *password;
    user->money = 0;
}

// Print details of a specific user
void printUser(const User *user) {
    printf("Name: ");
    for (int i = 0; i < user->name.Length; i++) {
        printf("%c", user->name.TabWord[i]);
    }
    printf("\nMoney: %d\n", user->money);
}

// Initialize the user array by loading users from the file
void initializeUserArray() {
    if (!isInitialized) {
        userArray = MakeArrayUser();  // Create the user array only once
        loadUsersFromFile();          // Load users from file
        isInitialized = true;
    }
}

// Add a new user to the user array and save to file
void addUser(ArrayUser *userArray, User *newUser) {
    InsertLastUser(userArray, *newUser);  // Insert new user to array
    saveUsersToFile();                    // Save updated users list
}

// Save users to file in append mode
void saveUsersToFile() {
    FILE *file = fopen(DATA_FILE, "ab");  // Open in append mode
    if (file != NULL) {
        fwrite(&userArray.Neff, sizeof(int), 1, file);  // Save the number of users
        for (int i = 0; i < userArray.Neff; i++) {
            fwrite(&userArray.A[i], sizeof(User), 1, file);  // Save each user
        }
        fclose(file);
    } else {
        printf("Error: Unable to save users.\n");
    }
}

// Check if a user with the given name exists in the user array
boolean cariUser(const Word *name) {
    if (!isInitialized) {
        return false;
    }
    int idx = SearchArrayUser(userArray, *name);
    return (idx != -1);  // Return true if user found
}

// Load users from the file
void loadUsersFromFile() {
    FILE *file = fopen(DATA_FILE, "rb");  // Open in read binary mode
    if (file != NULL) {
        STARTFILE(file);

        // Read number of users
        int count = WordToInt(&currentWord);
        ADVWORD();

        for (int i = 0; i < count; i++) {
            User user;
            user.money = WordToInt(&currentWord);
            ADVWORD();

            user.name = currentWord;
            ADVWORD();

            user.password = currentWord;
            ADVWORD();

            // Insert the loaded user into the global userArray
            InsertLastUser(&userArray, user);
        }
        fclose(file);
    } else {
        printf("Error: Unable to load users. File not found.\n");
    }
}

// Validate login credentials for a user
boolean validlogin(const Word *name, const Word *password) {
    if (!isInitialized) {
        initializeUserArray(); // Initialize the array if it's not already done
    }

    // Iterate over the global userArray
    for (int i = 0; i < userArray.Neff; i++) {
        if (isKataEqual(&userArray.A[i].name, name) && isKataEqual(&userArray.A[i].password, password)) {
            return true;  // Username and password matched
        }
    }
    return false;  // No match found
}
