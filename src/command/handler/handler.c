#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/User_Barang/user.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/queue/queue.h"

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
#include "../quit/quit.h"
#include "handler.h"

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
            tunggu(5);
        } else if (isWordEqualToString(&currentWord, "STORE REQUEST")) {
            StoreRequest(request, barangList);
            tunggu(2);
        } else if (isWordEqualToString(&currentWord, "STORE REMOVE")) {
            DisplayStore(*barangList);
            removeItem(barangList);
            tunggu(2);
        } else if (isWordEqualToString(&currentWord, "STORE SUPPLY")) {
            storeSupply(barangList, request);
            tunggu(2);
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
            tunggu(3);
        } else if (isWordEqualToString(&currentWord, "WORDL3")) {
            wordl3(userList);
            tunggu(3);
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
            MenuState insidemenu = *currentMenu;
            clear = true;
            update_menu(currentMenu, menustore);
            handleStoreMenu(userList, barangList, request, currentMenu);
            update_menu(currentMenu, insidemenu);
        } else if (isWordEqualToString(&currentWord, "WORK")) {
            animasiWork();
            clear = false;
            work(userList);
            tunggu(3);
            handleInsideMenu(userList, barangList, request, currentMenu);
        } else if (isWordEqualToString(&currentWord, "WORK CHALLENGE")) {
            MenuState insidemenu = *currentMenu;
            update_menu(currentMenu, menuworkchallenge);
            handleWorkChallenge(userList, currentMenu);
            update_menu(currentMenu, insidemenu);
        } else if (isWordEqualToString(&currentWord, "HELP")) {
            clear = true;
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
            tunggu(3);
            handleInsideMenu(userList, barangList, request, currentMenu);
        } else if (isWordEqualToString(&currentWord, "LOGOUT")) {
            clear = true;
            logout(&isInside, *userList);
            if (isInside == false) {
                printf("Logging out...\n");
                tunggu(2);
                handleLoginMenu(userList, barangList, request, currentMenu); /////////////////////////////////////////////////////////////////////////////
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
            tunggu(2);
        } else if (isWordEqualToString(&currentWord, "REGISTER")) {
            registerUser(userList);
            tunggu(2);
        } else if (isWordEqualToString(&currentWord, "HELP")) {
            help(currentMenu);
        } else if (isWordEqualToString(&currentWord, "MAIN MENU")) {
            isInLoginMenu = false;
            printf("Returning to Main Menu...\n");
            handleMainMenu(userList, barangList, &isInLoginMenu, request, currentMenu);
        } else if (isWordEqualToString(&currentWord, "QUIT")) {
            quit(&isInLoginMenu, *userList);
            if (isInLoginMenu == false) {
                exit(0);
            }
            //printf("Exiting PURRMART. Goodbye!\n");
            // exit(0);
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
                tunggu(1);
                handleLoginMenu(userList, barangList, request, currentMenu);
            } else {
                printf("Failed to load configuration.\n");
            }
        } else if (isWordEqualToString(&currentWord, "LOAD")) {
            update_menu(currentMenu, menuforlogin);
            if (Load(userList, barangList)) {
                tunggu(2);
                handleLoginMenu(userList, barangList, request, currentMenu); 
            } else {
                update_menu(currentMenu, menuforwelcome);
            }
        } else if (isWordEqualToString(&currentWord, "HELP")) {
            help(currentMenu);
        } else if (isWordEqualToString(&currentWord, "QUIT")) {
            quit(running, *userList);
            if(running==false){
                exit(0);
            }
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}