#include "../../ADT/user/user.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Kata/utils.h"
#include <stdio.h>


// Function to register a new user
#include "../save/save.h" // Ensure save function is included

void registerUser(ArrayUser *userArray) {
    User newUser;

    // Ask for username
    printf("Enter username: ");
    STARTWORD();
    newUser.name = currentWord;

    // Ask for password
    printf("Enter password: ");
    STARTWORD();
    newUser.password = currentWord;

    // Ask for initial money (default 0)
    printf("Enter initial money (default 0): ");
    STARTWORD();
    newUser.money = WordToInt(&currentWord);

    // Add new user to userArray
    addUser(userArray, &newUser);

    // Save to file
    saveToFile("dummy.txt", NULL, userArray); // Assuming barangArray is NULL for registration

    printf("Registration successful!\n");
}

