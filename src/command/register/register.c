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

    // Get name input
    printf("Enter Name: ");
    readLine(input, MAX_LEN);
    toWord(&name, input);

    // Get password input
    printf("Enter Password: ");
    readLine(input, MAX_LEN);
    toWord(&password, input);

    // Check if user already exists
    if (cariUser(&name)) {
        printf("User already exists.\n");
        return 0;
    }

    // Initialize and add the new user
    initUser(&user1, &name, &password);
    addUser(&user1);
    
    // Print user information
    printf("\nUser successfully created!\n");
    printUser(&user1);
    
    return 0;
}

/*
gcc -IADT -I../command/register -I../command Mesin_Kata/mesinkata.c Mesin_Kata/mesinkarakterv2.c user/user.c List/arrayuser.c ../command/register/register.c ../command/start.c -o program
*/