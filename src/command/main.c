#include "../../ADT/user/user.h"
#include <stdio.h>
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Kata/utils.h"
#include "../../ADT/boolean.h"
#include "../../ADT/barang/barang.h"

#include "register/register.h"
#include "start/start.h"
#include "login/login.h"
#include "load/load.h"

void printMenu() {
    printf("=========================================\n");
    printf("Welcome to PURRMART!\n");
    printf("1. Start (load default configuration)\n");
    printf("2. Login\n");
    printf("3. Register\n");
    printf("4. Load (load from a saved file)\n");
    printf("5. Exit\n");
    printf("=========================================\n");
    printf("Enter your choice: ");
}

int main() {
    Arraybarang barangArray = MakeArrayDin(); // Initialize the dynamic array for Barang
    ArrayUser userArray = MakeArrayUser();   // Initialize the dynamic array for Users

    boolean running = true;
    Word inputWord;
    int choice;

    while (running) {
        printMenu();

        // Read user input using mesinkata
        STARTWORD();  // Read a single line of input

        if (isEndWord()) {
            printf("No input detected. Please try again.\n");
            continue;  // Restart the loop
        }

        // Convert Word input to an integer
        inputWord = currentWord;  // Store the current word
        choice = WordToInt(&inputWord);

        if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            continue;
        }

        switch (choice) {
            case 1: // Start
                startCommand(&barangArray, &userArray);
                break;

            case 2: // Login
                login(&userArray);
                break;

            case 3: // Register
                registerUser(&userArray);
                break;

            case 4: // Load
            {
                char filename[MAX_LEN];
                printf("Enter the filename to load: ");
                STARTWORD();

                for (int i = 0; i < currentWord.Length; i++) {
                    filename[i] = currentWord.TabWord[i];
                }
                //filename[currentWord.Length] = '\0';  // Null-terminate the string

                loadFromFile(filename, &barangArray, &userArray);
                break;
            }

            case 5: // Exit
                printf("Exiting PURRMART. Goodbye!\n");
                running = false;
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    }


    // Clean up and deallocate memory before exiting
    DeallocateArrayDin(&barangArray);

    return 0;
}



/*
gcc -IADT -I../command/register -I../command Mesin_Kata/mesinkata.c Mesin_Kata/utils.c Mesin_Kata/mesinkarakterv2.c user/user.c barang/barang.c ../command/register/register.c ../command/main.c ../command/login/login.c ../command/save/save.c ../command/start/start.c ../command/load/load.c -o program
*/