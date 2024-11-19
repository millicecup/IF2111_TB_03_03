#include "start.h"
#include <stdio.h>
#include "../../ADT/barang/barang.h"
#include "../../ADT/user/user.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Kata/utils.h"
#include "../../ADT/boolean.h"

void startCommand(Arraybarang *barangArray, ArrayUser *userArray) {
    ClearArrayDin(barangArray);

    FILE *configFile = fopen("dummy.txt", "r");
    if (configFile == NULL) {
        printf("Default configuration file not found. PURRMART failed to start.\n");
        return;
    }

    STARTFILE(configFile);  // Initialize reading from file

    // Read number of items (N)
    int N = WordToInt(&currentWord);
    ADVWORD();

    // Read N items
    for (int i = 0; i < N; i++) {
        Barang newBarang;

        // Read price
        newBarang.price = WordToInt(&currentWord);
        ADVWORD();

        // Read name
        newBarang.name = currentWord;  // CurrentWord contains the name
        ADVWORD();

        // Insert the item into the array
        InsertLast(barangArray, newBarang);
    }

    // Read number of users (M)
    int M = WordToInt(&currentWord);
    ADVWORD();

    // Read M users
    for (int i = 0; i < M; i++) {
        User newUser;

        // Read money
        newUser.money = WordToInt(&currentWord);
        ADVWORD();

        // Read name
        newUser.name = currentWord;
        ADVWORD();

        // Read password
        newUser.password = currentWord;
        ADVWORD();

        // Insert the user into the array (corrected function call)
        addUser(userArray, &newUser);  // Pass both the userArray and newUser
    }

    fclose(configFile);
    printf("Default configuration file loaded. PURRMART successfully started.\n");
}
