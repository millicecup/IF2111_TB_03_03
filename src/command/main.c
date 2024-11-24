#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../ADT/User_Barang/user.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/User_Barang/barang.h"
#include "../ADT/queue/queue.h"

#include "animasi/animasi.h"
#include "start/start.h"
#include "load/load.h"
#include "login/login.h"
#include "register/register.h"
#include "save/save.h"
#include "work/work.h"
#include "workchallenge/tebakangka/tebakangka.h"
#include "workchallenge/wordl3/wordl3.h"
#include "Store_List/Store_List.h"
#include "Store_Request/Store_Request.h"
#include "Store_Supply/Store_Supply.h"
#include "Store_Remove/Store_Remove.h"
#include "Help/help.h"
#include "Logout/logout.h"
#include "quit/quit.h"

#define COMMAND_MAX_LEN 50

// Fungsi untuk handle store menu
void handleStoreMenu(UserList *userList, BarangList *barangList, Queue *request, MenuState *currentMenu) {
    update_menu(currentMenu, menustore);
    boolean isInStoreMenu = true;
    system("cls || clear");
    // animasiStore(); 

    while (isInStoreMenu) {
        animasiStore();
        //scanf("%s", command);
        printf("\n\n");
        printf("Enter command: ");
        GetInput();
        Word currentWord;
        chartoWord(&currentWord, currentInput.TabWord);

        if (isWordEqualToString(&currentWord, "STORE LIST")) {
            DisplayStore(*barangList);
        } else if (isWordEqualToString(&currentWord, "STORE REQUEST")) {
            StoreRequest(request, barangList);
        } else if (isWordEqualToString(&currentWord, "STORE REMOVE")) {
            DisplayStore(*barangList);
            removeItem(barangList);
        } else if (isWordEqualToString(&currentWord, "STORE SUPPLY")) {
            storeSupply(barangList, request);
        } else if (isWordEqualToString(&currentWord, "HELP")) {
            help(currentMenu);
        } else if (isWordEqualToString(&currentWord, "MENU")) {
            isInStoreMenu = false;
            printf("Returning to Inside Menu...\n");
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}

// mending dipisah apa engga work challenge nya?????
// // Fungsi untuk handle work menu
// void handleWorkMenu(UserList *userList, BarangList *barangList, MenuState *currentMenu) {
//     update_menu(currentMenu, menuwork);
//     boolean isInWorkMenu = true;
//     system("cls || clear");
//     printWorkMenu();

//     while (isInWorkMenu) {
//         printf("\n\n");
//         printf("Enter command: ");
//         //scanf("%s", command);
//         GetInput();
//         Word currentWord;
//         chartoWord(&currentWord, currentInput.TabWord);

//         if (isWordEqualToString(&currentWord, "TEBAK ANGKA")) {
//             tebakangka(userList);
//         } else if (isWordEqualToString(&currentWord, "WORDL3")) {
//             wordl3(userList);
//         } else if (isWordEqualToString(&currentWord, "WORK")) {
//             work(userList);
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

void handleWorkChallenge(UserList *userList, MenuState *currentMenu) {
    update_menu(currentMenu, menuworkchallenge);
    boolean isInWorkChallengeMenu = true;
    system("cls || clear");
    //animasiChallenge();

    while (isInWorkChallengeMenu) {
        animasiChallenge();
        printf("\n\n");
        printf("Enter command: ");
        //scanf("%s", command);
        GetInput();
        Word currentWord;
        chartoWord(&currentWord, currentInput.TabWord);

        if (isWordEqualToString(&currentWord, "TEBAK ANGKA")) {
            tebakangka(userList);
        } else if (isWordEqualToString(&currentWord, "WORDL3")) {
            wordl3(userList);
        } else if (isWordEqualToString(&currentWord, "HELP")) {
            help(currentMenu);
        } else if (isWordEqualToString(&currentWord, "MENU")) {
            isInWorkChallengeMenu = false;
            printf("Returning to Work Menu...\n");
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}

// Fungsi untuk handle menu
void handleInsideMenu(UserList *userList, BarangList *barangList, Queue *request, MenuState *currentMenu) {
    update_menu(currentMenu, menuutama);
    boolean isInside = true;
    boolean clear = true;

    while (isInside) {
        if (clear)
        {
            system("cls || clear");
            animasiMenu();
        }
        printf("\n\n");
        printf("Enter command: ");
        //scanf("%s", command);
        GetInput();
        Word currentWord;
        chartoWord(&currentWord, currentInput.TabWord);

        if (isWordEqualToString(&currentWord, "STORE")) {
            clear = true;
            handleStoreMenu(userList, barangList, request, currentMenu);
        } else if (isWordEqualToString(&currentWord, "WORK")) {
            animasiWork();
            clear = false;
            work(userList);
        } else if (isWordEqualToString(&currentWord, "WORK CHALLENGE")) {
            clear = true;
            handleWorkChallenge(userList, currentMenu);
        } else if (isWordEqualToString(&currentWord, "HELP")) {
            clear = false;
            help(currentMenu);
        } else if (isWordEqualToString(&currentWord, "SAVE")) {
            clear = false;
            printf("Enter the filename to save the current state: ");
            char filename[COMMAND_MAX_LEN];
            //scanf("%s", filename);
            Word file;
            GetInput();
            chartoWord(&file, currentInput.TabWord);
            WordToChar(&file, filename); 
            SaveToFile(filename, barangList, userList);
        } else if (isWordEqualToString(&currentWord, "LOGOUT")) {
            clear = true;
            logout(&isInside, *userList);
            if (isInside == false) {
                printf("Logging out...\n");
                // handleLoginMenu(userList, barangList, request, currentMenu); /////////////////////////////////////////////////////////////////////////////
            }
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}

// Fungsi untuk handle login menu
void handleLoginMenu(UserList *userList, BarangList *barangList, Queue *request, MenuState *currentMenu) { ////////////////////////////////////////////////////////////
    update_menu(currentMenu, menuforlogin);
    boolean isInLoginMenu = true;
    system("cls || clear");
    //animasiLogin();

    while (isInLoginMenu) {
        animasiLogin();
        //scanf("%s", command);
        printf("\n\n");
        printf("Enter command: ");
        GetInput();
        Word currentWord;
        chartoWord(&currentWord, currentInput.TabWord);
        if (isWordEqualToString(&currentWord, "LOGIN")) {
            login(userList);
            if (loggedIn) { 
                update_menu(currentMenu, menuutama);
                handleInsideMenu(userList, barangList, request, currentMenu);
            }
        } else if (isWordEqualToString(&currentWord, "REGISTER")) {
            registerUser(userList);
        } else if (isWordEqualToString(&currentWord, "HELP")) {
            help(currentMenu);
        } else if (isWordEqualToString(&currentWord, "MAIN MENU")) {
            isInLoginMenu = false;
            printf("Returning to Main Menu...\n");
        } else if (isWordEqualToString(&currentWord, "QUIT")) {
            quit(&isInLoginMenu, *userList);
            if (isInLoginMenu == false) {
                printf("Exiting PURRMART. Goodbye!\n");
                // handleLoginMenu(userList, barangList, request, currentMenu); /////////////////////////////////////////////////////////////////////////////
            }
            //printf("Exiting PURRMART. Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}

// Fungsi untuk handle main menu
void handleMainMenu(UserList *userList, BarangList *barangList, boolean *running, Queue *request, MenuState *currentMenu) {
    update_menu(currentMenu, menuforwelcome);
    system("cls || clear");

    while (*running) {
        //scanf("%s", command);
        animasiMainMenu();
        printf("\n\n");
        printf("Enter command: ");
        GetInput();
        Word currentWord;
        chartoWord(&currentWord, currentInput.TabWord);
        if (isWordEqualToString(&currentWord, "START")) {
            update_menu(currentMenu, menuforlogin);
            if (start(userList, barangList) == 0) {
                printf("Configuration loaded successfully!\n");
                handleLoginMenu(userList, barangList, request, currentMenu);
            } else {
                printf("Failed to load configuration.\n");
            }
        } else if (isWordEqualToString(&currentWord, "LOAD")) {
            update_menu(currentMenu, menuforlogin);
            Load(userList, barangList);
            tunggu(15);
            handleLoginMenu(userList, barangList, request, currentMenu);
        } else if (isWordEqualToString(&currentWord, "HELP")) {
            help(currentMenu);
        } else if (isWordEqualToString(&currentWord, "QUIT")) {
            *running = false;
            printf("Exiting PURRMART. Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}

// Main Function
int main() {
    boolean running = true;

    UserList userList;
    BarangList barangList;
    Queue request;
    CreateUserList(&userList);
    CreateBarangList(&barangList, 2);
    CreateEmptyRequest(&request);

    MenuState currentMenu = menuforwelcome;

    while (running) {
        handleMainMenu(&userList, &barangList, &running, &request, &currentMenu);
    }

    FreeBarangList(&barangList);
    return 0;
}

/*
gcc main.c ../ADT/User_Barang/user.c ../ADT/User_Barang/barang.c ../ADT/Mesin_Karakter/mesinkarakter.c ../ADT/Mesin_Kata/mesinkata.c ../ADT/Mesin_Baris/mesinbaris.c ../ADT/work/mesinword.c ../ADT/work/mesinkar.c Start/start.c login/login.c register/register.c save/save.c load/load.c work/tebakangka/tebakangka.c animasi/animasi.c Store_List/Store_List.c -o program
*/

/*
gcc main.c ../ADT/User_Barang/user.c ../ADT/User_Barang/barang.c ../ADT/Mesin_Karakter/mesinkarakter.c ../ADT/Mesin_Kata/mesinkata.c ../ADT/Mesin_Baris/mesinbaris.c ../ADT/work/mesinword.c ../ADT/work/mesinkar.c Start/start.c login/login.c register/register.c save/save.c load/load.c animasi/animasi.c Store_List/Store_List.c ../ADT/List/list.c ../ADT/queue/queue.c Store_Request/Store_Request.c Store_Remove/Store_Remove.c Store_Supply/Store_Supply.c workchallenge/wordl3/wordl3.c workchallenge/tebakangka/tebakangka.c -o program
*/

/*
gcc main.c ../ADT/User_Barang/user.c ../ADT/User_Barang/barang.c ../ADT/Mesin_Karakter/mesinkarakter.c ../ADT/Mesin_Kata/mesinkata.c ../ADT/Mesin_Baris/mesinbaris.c Start/start.c login/login.c register/register.c save/save.c load/load.c animasi/animasi.c Store_List/Store_List.c ../ADT/List/list.c ../ADT/queue/queue.c Store_Request/Store_Request.c Store_Remove/Store_Remove.c Store_Supply/Store_Supply.c workchallenge/wordl3/wordl3.c workchallenge/tebakangka/tebakangka.c work/work.c help/help.c logout/logout.c quit/quit.c -o program*/