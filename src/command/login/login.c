#include "login.h"
#include "../../ADT/User_Barang/user.h"
#include "../load/load.h"

#include "login.h"
#include "../../ADT/User_Barang/user.h"
#include "../load/load.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include <stdio.h>
boolean loggedIn = false;

void login(UserList *userArray) {
    // Load users from configuration file kalo ga di main
    // LoadConfig("../save/dummy.txt", userArray, NULL); 
    if (userArray->count == 0) {
        printf("No users found in the system. Please register first.\n");
        return;
    }
    else {
        printf("Users loaded successfully.\n");
    }

    Word username, password;


    // Get username from the user
    printf("Enter Username: ");
    GetInput();
    chartoWord(&username, currentInput.TabWord);

    // Get password from the user
    printf("Enter Password: ");
    GetInput();
    chartoWord(&password, currentInput.TabWord);

    // Check credentials
    for (int i = 0; i < userArray->count; i++) {
        User currentUser = userArray->users[i];

        // Debugging: Print user being compared
        //printf("Debug: Comparing with Username: %s, Password: %s\n", currentUser.name, currentUser.password);

        if (isWordEqualToString(&username, currentUser.name) &&
            isWordEqualToString(&password, currentUser.password)) {
            loggedIn = true;
            userArray->currentUserIndex = i;
            printf("Login successful! Welcome, %s.\n", currentUser.name);
            break;
        }
    }

    // If no match is found
    if (!loggedIn) {
        printf("Invalid username or password. Please try again.\n");
    }
}

