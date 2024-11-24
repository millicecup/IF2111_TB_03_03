#include "../../ADT/boolean.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/User_Barang/user.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../ADT/Mesin_Baris/mesinbaris.h"
#include "../../ADT/queue/queue.h"
#include "../../ADT/List/list.h"


#include "handler.h"
#include "../animasi/animasi.h"
#include "../Start/start.h"
#include "../load/load.h"
#include "../login/login.h"
#include "../register/register.h"
#include "../save/save.h"
#include "../work/work.h"
#include "../workchallenge/tebakangka/tebakangka.h"
#include "../workchallenge/wordl3/wordl3.h"
#include "../Store_List/Store_List.h"
#include "../Store_Request/Store_Request.h"
#include "../Store_Supply/Store_Supply.h"
#include "../Store_Remove/Store_Remove.h"
#include "../Help/help.h"
#include "../Logout/logout.h"
#include <stdio.h>
#include <stdlib.h>

void handleStoreMenu(UserList *userList, BarangList *barangList, Queue *request, MenuState *currentMenu) {
    update_menu(currentMenu, menustore);
    boolean isInStoreMenu = true;
    //animasiStore();
    while (isInStoreMenu) {
        animasiStore();
        GetInput();
        Word currentWord;
        chartoWord(&currentWord, currentInput.TabWord);

        if (isWordEqualToString(&currentWord, "STORE LIST")) {
            if (!IsEmpty(*barangList)) {
                printf("Listing all items in the store:\n");
                DisplayStore(*barangList);
            } else {
                printf("The store is currently empty.\n");
            }
        } else if (isWordEqualToString(&currentWord, "STORE REQUEST")) {
            StoreRequest(request, barangList);
        } else if (isWordEqualToString(&currentWord, "STORE REMOVE")) {
            removeItem(barangList);
        } else if (isWordEqualToString(&currentWord, "STORE SUPPLY")) {
            storeSupply(barangList, request);
        } else if (isWordEqualToString(&currentWord, "HELP")) {
            help(currentMenu);
            GetInput();
        } else if (isWordEqualToString(&currentWord, "MENU")) {
            isInStoreMenu = false;
            printf("Returning to Inside Menu...\n");
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}

void handleWorkChallengeMenu(UserList *userList, MenuState *currentMenu) {
    update_menu(currentMenu, menuworkchallenge);
    boolean isInWorkChallengeMenu = true;
    //animasiWorkMenu();
    while (isInWorkChallengeMenu) {
        animasiWorkMenu();
        // printWorkMenu();
        GetInput();
        Word currentWord;
        chartoWord(&currentWord, currentInput.TabWord);

        if (isWordEqualToString(&currentWord, "TEBAK ANGKA")) {
            tebakangka(userList);
        } else if (isWordEqualToString(&currentWord, "WORDL3")) {
            wordl3(userList);
        } else if (isWordEqualToString(&currentWord, "HELP")) {
            help(currentMenu);
            GetInput();
        } else if (isWordEqualToString(&currentWord, "MENU")) {
            isInWorkChallengeMenu = false;
            printf("Returning to Work Menu...\n");
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}

// void handleWorkMenu(UserList *userList, BarangList *barangList, MenuState *currentMenu) {
//     update_menu(currentMenu, menuwork);
//     boolean isInWorkMenu = true;
//     printWorkMenu();
//     while (isInWorkMenu) {
//         GetInput();
//         Word currentWord;
//         chartoWord(&currentWord, currentInput.TabWord);

//         if (isWordEqualToString(&currentWord, "WORK")) {
//             work(userList);
//         } else if (isWordEqualToString(&currentWord, "WORK CHALLENGE")) {
//             handleWorkChallengeMenu(userList, currentMenu);
//         } else if (isWordEqualToString(&currentWord, "HELP")) {
//             help(currentMenu);
//         } else if (isWordEqualToString(&currentWord, "MENU")) {
//             isInWorkMenu = false;
//             printf("Returning to Inside Menu...\n");
//         } else {
//             printf("Invalid command. Please try again.\n");
//         }
//     }
// }

void handleInsideMenu(UserList *userList, BarangList *barangList, Queue *request, MenuState *currentMenu) {
    update_menu(currentMenu, menuutama);
    boolean isInside = true;
    //animasiMenu();
    while (isInside) {
        // printInsideMenu();
        animasiMenu();
        GetInput();
        Word currentWord;
        chartoWord(&currentWord, currentInput.TabWord);

        if (isWordEqualToString(&currentWord, "STORE")) {
            handleStoreMenu(userList, barangList, request, currentMenu);
        } else if (isWordEqualToString(&currentWord, "WORK")) {
            work(userList);
        } else if (isWordEqualToString(&currentWord, "WORK CHALLENGE")) {
            handleWorkChallengeMenu(userList, currentMenu);
        } else if (isWordEqualToString(&currentWord, "HELP")) {
            help(currentMenu);
            GetInput();
        } else if (isWordEqualToString(&currentWord, "SAVE")) {
            printf("Enter the filename to save the current state: ");
            char filename[50];
            GetInput();
            Word file;
            chartoWord(&file, currentInput.TabWord);
            WordToChar(&file, filename);
            SaveToFile(filename, barangList, userList);
        } else if (isWordEqualToString(&currentWord, "LOGOUT")) {
            logout(&isInside, *userList);
            if (isInside == false) {
                printf("Logging out...\n");
                handleLoginMenu(userList, barangList, request, currentMenu);
            }
            
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}

void handleLoginMenu(UserList *userList, BarangList *barangList, Queue *request, MenuState *currentMenu) {
    update_menu(currentMenu, menuforlogin);
    boolean isInLoginMenu = true;
    // animasiLogin();

    while (isInLoginMenu) {
        animasiLogin();
        GetInput();
        Word currentWord;
        chartoWord(&currentWord, currentInput.TabWord);

        if (isWordEqualToString(&currentWord, "LOGIN")) {
            login(userList);
            if (loggedIn) { // Assume loggedIn is set in login()
                update_menu(currentMenu, menuutama); // Update menu state to main
                handleInsideMenu(userList, barangList, request, currentMenu);
            }
        } else if (isWordEqualToString(&currentWord, "REGISTER")) {
            registerUser(userList);
        } else if (isWordEqualToString(&currentWord, "HELP")) {
            help(currentMenu);
            GetInput();
        } else if (isWordEqualToString(&currentWord, "MAIN")) {
            isInLoginMenu = false;
            printf("Returning to Main Menu...\n");
        } else if (isWordEqualToString(&currentWord, "QUIT")) {
            printf("Exiting PURRMART. Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}

void handleMainMenu(UserList *userList, BarangList *barangList, boolean *running, Queue *request, MenuState *currentMenu) {
    while (*running) {
        animasiMainMenu();
        GetInput();
        Word currentWord;
        chartoWord(&currentWord, currentInput.TabWord);

        if (isWordEqualToString(&currentWord, "START")) {
            update_menu(currentMenu, menuforlogin); // Update menu state to login
            if (startfunc(userList, barangList) == 0) {
                printf("Configuration loaded successfully!\n");
                handleLoginMenu(userList, barangList, request, currentMenu);
            } else {
                printf("Failed to load configuration.\n");
            }
        } else if (isWordEqualToString(&currentWord, "LOAD")) {
            update_menu(currentMenu, menuforlogin); // Update menu state to login
            Load(userList, barangList);
            handleLoginMenu(userList, barangList, request, currentMenu);
        } else if (isWordEqualToString(&currentWord, "HELP")) {
            help(currentMenu); // Call the help function for the main menu
            GetInput();
        } else if (isWordEqualToString(&currentWord, "QUIT")) {
            *running = false;
            printf("Exiting PURRMART. Goodbye!\n");
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}
