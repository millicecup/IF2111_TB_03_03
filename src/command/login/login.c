#include "login.h"
#include "../../ADT/user/user.h"
#include "../../ADT/Mesin_Kata/mesinkarakterv2.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/boolean.h"
#include <stdio.h>

void login(ArrayUser *userArray) {
    Word username, password;
    boolean loggedIn = false;

    // Prompt the user for their username and password
    printf("Enter Name: ");
    STARTWORD(); // Read the username using mesinkata
    username = currentWord; // Store the current word as username

    printf("Enter Password: ");
    STARTWORD(); // Read the password using mesinkata
    password = currentWord; // Store the current word as password

    // Search for the user in the userArray
    for (int i = 0; i < userArray->Neff; i++) {
        User currentUser = userArray->A[i];
        // Compare the username and password using isKataEqual
        if (isKataEqual(&username, &currentUser.name) && isKataEqual(&password, &currentUser.password)) {
            loggedIn = true;
            printf("Login successful! Welcome %s.\n", username.TabWord); // Output the username (TabWord)
            break; // Exit the loop as login is successful
        }
    }

    // If no match was found, print an error message
    if (!loggedIn) {
        printf("Invalid username or password.\n");
    }
}
