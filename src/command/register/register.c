#include "../../ADT/user/user.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"

#include <stdio.h>


// Register a new user
int registerUser() {
    User user1;
    Word name, password;
    char input[MAX_LEN];

    // Initialize the user array
    initializeUserArray();

    while (true) {
        // Get name input
        printf("Enter Name: ");
        readLine(input, MAX_LEN);
        toWord(&name, input);

        // Check if user already exists
        if (cariUser(&name)) {
            printf("User already exists. Try again.\n");
            continue;  // Retry if the user exists
        }

        // Get password input
        printf("Enter Password: ");
        readLine(input, MAX_LEN);
        toWord(&password, input);

        // Initialize and add the new user
        initUser(&user1, &name, &password);
        addUser(&user1);

        // Print user information
        printf("\nUser successfully created!\n");
        printUser(&user1);
        break;  // Break the loop after successful registration
    }

    return 0;
}
