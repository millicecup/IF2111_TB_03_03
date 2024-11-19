#include <stdio.h>
#include "login.h"
#include "../../ADT/user/user.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Kata/utils.h"
#include "../../ADT/boolean.h"



// Handle login
int login() {
    Word name, password;
    char input[MAX_LEN];

    // Initialize the user array
    initializeUserArray();

    // Get name input
    printf("Enter Name: ");
    readLine(input, MAX_LEN);
    toWord(&name, input);

    // Get password input
    printf("Enter Password: ");
    readLine(input, MAX_LEN);
    toWord(&password, input);

    // Validate the credentials
    if (validlogin(&name, &password)) {
        printf("Login successful!\n");
        return 1; // Login successful
    } else {
        printf("Invalid username or password.\n");
        return 0; // Login failed
    }
}
