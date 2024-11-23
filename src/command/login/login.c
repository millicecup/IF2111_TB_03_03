#include "login.h"
#include "../../ADT/User_Barang/user.h"
#include "../load/load.h"

#include "login.h"
#include "../../ADT/User_Barang/user.h"
#include "../load/load.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include <stdio.h>

User *loggedInUser = NULL; // Pointer to track the logged-in user

User* login(UserList *userList) {
    if (userList->count == 0) {
        printf("No users found in the system. Please register first.\n");
        return NULL;
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
    for (int i = 0; i < userList->count; i++) {
        User *currentUser = &userList->users[i];
        if (isWordEqualToString(&username, currentUser->name) &&
            isWordEqualToString(&password, currentUser->password)) {
            printf("Login successful! Welcome, %s.\n", currentUser->name);
            return currentUser; // Return the logged-in user
        }
    }

    printf("Invalid username or password. Please try again.\n");
    return NULL;
}
