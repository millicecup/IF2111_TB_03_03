#include <stdio.h>
#include <stdlib.h>
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

#define COMMAND_MAX_LEN 50

// Fungsi untuk menghandle store menu
void handleStoreMenu(UserList *userList, BarangList *barangList, Queue *request, MenuState *currentMenu) {
    boolean isInStoreMenu = true;

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
        } else if (isWordEqualToString(&currentWord, "MENU")) {
            isInStoreMenu = false;
            printf("Returning to Inside Menu...\n");
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}

// Fungsi untuk menghandle work menu
void handleWorkMenu(UserList *userList, BarangList *barangList, MenuState *currentMenu) {
    boolean isInWorkMenu = true;

    while (isInWorkMenu) {
        printWorkMenu();
        GetInput();
        Word currentWord;
        chartoWord(&currentWord, currentInput.TabWord);

        if (isWordEqualToString(&currentWord, "TEBAKANGKA")) {
            tebakangka();
        } else if (isWordEqualToString(&currentWord, "WORDL3")) {
            wordl3(userList);
        } else if (isWordEqualToString(&currentWord, "WORK")) {
            work(userList);
        } else if (isWordEqualToString(&currentWord, "HELP")) {
            help(currentMenu);
        } else if (isWordEqualToString(&currentWord, "MENU")) {
            isInWorkMenu = false;
            printf("Returning to Inside Menu...\n");
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}

// Fungsi untuk menghandle menu
void handleInsideMenu(UserList *userList, BarangList *barangList, Queue *request, MenuState *currentMenu) {
    boolean isInside = true;

    while (isInside) {
        animasiMenu();
        //scanf("%s", command);
        GetInput();
        Word currentWord;
        chartoWord(&currentWord, currentInput.TabWord);
        if (isWordEqualToString(&currentWord, "STORE")) {
            update_menu(currentMenu, menuutama);
            handleStoreMenu(userList, barangList, request, currentMenu);
        } else if (isWordEqualToString(&currentWord, "WORK")) {
            update_menu(currentMenu, menuutama);
            handleWorkMenu(userList, barangList, currentMenu);
        } else if (isWordEqualToString(&currentWord, "HELP")) {
            help(currentMenu);
        } else if (isWordEqualToString(&currentWord, "SAVE")) {
            printf("Enter the filename to save the current state: ");
            char filename[COMMAND_MAX_LEN];
            GetInput();
            Word file;
            chartoWord(&file, currentInput.TabWord);
            WordToChar(&file, filename);
            SaveToFile(filename, barangList, userList);
        } else if (isWordEqualToString(&currentWord, "LOGOUT")) {
            logout(&isInside, *userList); // Call logout
            printf("Logging out...\n");
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}

// Fungsi untuk menghandle login menu
void handleLoginMenu(UserList *userList, BarangList *barangList, Queue *request, MenuState *currentMenu) {
    boolean isInLoginMenu = true;

    while (isInLoginMenu) {
        animasiLogin();
        //scanf("%s", command);
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

// Fungsi untuk menghandle main menu
void handleMainMenu(UserList *userList, BarangList *barangList, boolean *running, Queue *request, MenuState *currentMenu) {
    while (*running) {
        animasiMainMenu();
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
gcc main.c ../ADT/User_Barang/user.c ../ADT/User_Barang/barang.c ../ADT/Mesin_Karakter/mesinkarakter.c ../ADT/Mesin_Kata/mesinkata.c ../ADT/Mesin_Baris/mesinbaris.c Start/start.c login/login.c register/register.c save/save.c load/load.c animasi/animasi.c Store_List/Store_List.c ../ADT/List/list.c ../ADT/queue/queue.c Store_Request/Store_Request.c Store_Remove/Store_Remove.c Store_Supply/Store_Supply.c workchallenge/wordl3/wordl3.c workchallenge/tebakangka/tebakangka.c work/work.c Help/help.c Logout/logout.c -o program
*/