#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/User_Barang/user.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/queue/queue.h"
#include "../../ADT/Stack/stack.h"
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/SetMap/setmap.h"

#include "../animasi/animasi.h"
#include "../Cart_Add/cart_add.h"
#include "../Cart_Remove/cart_remove.h"
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
#include "../History/history.h"
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
        ResetInput();
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
        ResetInput();
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
void handleInsideMenu(UserList *userList, BarangList *barangList, Queue *request, Keranjang *cart, Wishlist *wishlist, History *history, MenuState *currentMenu) {
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
        ResetInput();
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
            handleInsideMenu(userList, barangList, request, cart, wishlist, history, currentMenu);
        } else if (isWordEqualToString(&currentWord, "WORK CHALLENGE")) {
            MenuState insidemenu = *currentMenu;
            update_menu(currentMenu, menuworkchallenge);
            handleWorkChallenge(userList, currentMenu);
            update_menu(currentMenu, insidemenu);
        } else if (isWordEqualToString(&currentWord, "CART")) {
            MenuState insidemenu = *currentMenu;
            update_menu(currentMenu, menucart);
            handleCartMenu(userList, barangList, cart, currentMenu);
            update_menu(currentMenu, insidemenu);
        } else if (isWordEqualToString(&currentWord, "WISHLIST")) {
            MenuState insidemenu = *currentMenu;
            update_menu(currentMenu, menuwishlist);
            handleWishlistMenu(userList, barangList, wishlist, currentMenu);
            update_menu(currentMenu, insidemenu);
        } else if (isWordEqualToString(&currentWord, "HISTORY")) {
            animasiHistory();
            clear = false;
            DisplayHistory(*history, 5);
            GetInput();
            Word currentWord;
            chartoWord(&currentWord, currentInput.TabWord);
            if (isWordEqualToString(&currentWord, "back"))
            {
                handleInsideMenu(userList, barangList, request, cart, wishlist, history, currentMenu);
            }
            else
            {
                printf("Perintah tidak valid! Ketik 'back' untuk keluar.\n");
            }
        } else if (isWordEqualToString(&currentWord, "PROFILE")) {
            clear = true;
            printf("TBA\n");
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
            handleInsideMenu(userList, barangList, request, cart, wishlist, history, currentMenu);
        } else if (isWordEqualToString(&currentWord, "LOGOUT")) {
            clear = true;
            logout(&isInside, *userList);
            if (isInside == false) {
                printf("Logging out...\n");
                tunggu(2);
                handleLoginMenu(userList, barangList, request, cart, wishlist, history, currentMenu); /////////////////////////////////////////////////////////////////////////////
            }
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}

// Fungsi untuk handle login menu
void handleLoginMenu(UserList *userList, BarangList *barangList, Queue *request, Keranjang *cart, Wishlist *wishlist, History *history, MenuState *currentMenu) { 
    printf("DEBUG: Entering handleLoginMenu.\n");

    update_menu(currentMenu, menuforlogin);
    boolean isInLoginMenu = true;
    // system("cls || clear");
    //animasiLogin();

    while (isInLoginMenu) {
        animasiLogin();
        printf("\n\n");
        printf("Enter command: ");
        ResetInput();
        GetInput();
        Word currentWord;
        chartoWord(&currentWord, currentInput.TabWord);

        printf("DEBUG: Command entered: %s\n", currentInput.TabWord);
        printf("DEBUG: isInLoginMenu = %d\n", isInLoginMenu);

        if (isWordEqualToString(&currentWord, "LOGIN")) {
            login(userList);
            if (loggedIn) {
                update_menu(currentMenu, menuutama);
                handleInsideMenu(userList, barangList, request, cart, wishlist, history, currentMenu);
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
            handleMainMenu(userList, barangList, &isInLoginMenu, request, cart, wishlist, history, currentMenu);
        } else if (isWordEqualToString(&currentWord, "QUIT")) {
            quit(&isInLoginMenu, *userList);
            if (!isInLoginMenu) {
                exit(0);
            }
            printf("Exiting PURRMART. Goodbye!\n");
            // exit(0);
        } 
        else {
            printf("Invalid command. Please try again.\n");
        }
    }

}

// Fungsi untuk handle main menu
void handleMainMenu(UserList *userList, BarangList *barangList, boolean *running, Queue *request, Keranjang *cart, Wishlist *wishlist, History *history, MenuState *currentMenu) {
    update_menu(currentMenu, menuforwelcome);
    system("cls || clear");

    while (*running) {
        //scanf("%s", command);
        animasiMainMenu();
        printf("\n\n");
        printf("Enter command: ");
        ResetInput();
        GetInput();
        Word currentWord;
        chartoWord(&currentWord, currentInput.TabWord);
        if (isWordEqualToString(&currentWord, "START")) {
            update_menu(currentMenu, menuforlogin);
            if (start(userList, barangList) == 0) {
                printf("DEBUG: Start completed successfully.\n");
                //boolean isInLoginMenu = true;  // Ensure state is set correctly
                printf("DEBUG: Transitioning to handleLoginMenu.\n");
                handleLoginMenu(userList, barangList, request, cart, wishlist, history, currentMenu);
            } else {
                printf("DEBUG: Start failed.\n");
            }

        } else if (isWordEqualToString(&currentWord, "LOAD")) {
            update_menu(currentMenu, menuforlogin);
            if (Load(userList, barangList)) {
                tunggu(2);
                handleLoginMenu(userList, barangList, request, cart, wishlist, history, currentMenu); 
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

void handleCartMenu(UserList *userList, BarangList *barangList, Keranjang *keranjang, MenuState *currentMenu) {
    update_menu(currentMenu, menucart);
    boolean isInCartMenu = true;
    system("cls || clear");

    while (isInCartMenu) {
        animasiCart();
        printf("\n\n");
        printf("Enter command: ");
        GetInput(); // Membaca input penuh ke currentInput
        printf("DEBUG: Input received: ");
        TulisWordNoNL(currentInput);
        printf("\n");

        // baca kata dari currentInput
        STARTWORD(stdin);
        if (isWordEqualToString(&currentWord, "CART")) {
            printf("DEBUG: Command CART detected!\n");
            ADVWORD(); // (ADD/REMOVE/SHOW/PAY)
            printf("DEBUG: Sub-command = ");
            TulisWord(currentWord);
            printf("\n");

            if (isWordEqualToString(&currentWord, "ADD")) {
                printf("DEBUG: Sub-command recognized as ADD\n");

                ADVWORD(); // Membaca nama item
                Word itemName;
                CopyWordToVar(&currentWord, itemName);
                printf("DEBUG: Item name = %s\n", itemName);

                ADVWORD(); // Membaca jumlah
                int qty = WordToInt(&currentWord);
                printf("DEBUG: Quantity = %d\n", qty);

                AddCart(keranjang, itemName.TabWord, qty, barangList);
                printf("Item %s dengan jumlah %d berhasil ditambahkan ke keranjang.\n", itemName, qty);
            } else if (isWordEqualToString(&currentWord, "REMOVE")) {
                ADVWORD(); // Membaca nama item
                char itemName[50];
                WordToChar(&currentWord, itemName);
                printf("DEBUG: Item name = %s\n", itemName);

                ADVWORD(); // Membaca jumlah
                int qty = WordtoNum(currentWord);
                printf("DEBUG: Quantity = %d\n", qty);

                RemoveCart(keranjang, itemName, qty);
                printf("Item %s dengan jumlah %d berhasil dihapus dari keranjang.\n", itemName, qty);
            } else if (isWordEqualToString(&currentWord, "SHOW")) {
                printf("TBA\n");
            } else if (isWordEqualToString(&currentWord, "PAY")) {
                printf("TBA\n");
            } else {
                printf("Invalid CART command!\n");
            }
        } else if (isWordEqualToString(&currentWord, "HELP")) {
            help(currentMenu);
        } else if (isWordEqualToString(&currentWord, "MENU")) {
            isInCartMenu = false;
            printf("Returning to Main Menu...\n");
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}



void handleWishlistMenu(UserList *userList, BarangList *barangList, Wishlist *wishlist, MenuState *currentMenu) {
    update_menu(currentMenu, menuwishlist);
    boolean isInWishlistMenu = true;
    system("cls || clear");

    while (isInWishlistMenu) {
        animasiWishlist();
        printf("\n\n");
        printf("Enter command: ");
        ResetInput();
        GetInput();
        Word currentWord;
        chartoWord(&currentWord, currentInput.TabWord);

        if (isWordEqualToString(&currentWord, "WISHLIST ADD")) {
            printf("TBA\n");
        } 
        else if (isWordEqualToString(&currentWord, "WISHLIST SWAP")) {
            printf("TBA\n");
        } 
        else if (isWordEqualToString(&currentWord, "WISHLIST REMOVE")) {
            printf("TBA\n");
        } 
        else if (isWordEqualToString(&currentWord, "WISHLIST CLEAR")) {
            printf("TBA\n");
        } 
        else if (isWordEqualToString(&currentWord, "WISHLIST SHOW")) {
            printf("TBA\n");
        } 
        else if (isWordEqualToString(&currentWord, "HELP")) {
            help(currentMenu);
        } 
        else if (isWordEqualToString(&currentWord, "MENU")) {
            isInWishlistMenu = false;
            printf("Returning to Inside Menu...\n");
        } 
        else {
            printf("Invalid command. Please try again.\n");
        }
    }
}


// void handleCartMenu(UserList *userList, BarangList *barangList, Keranjang *keranjang, MenuState *currentMenu) {
//     update_menu(currentMenu, menucart);
//     boolean isInCartMenu = true;
//     system("cls || clear");

//     while (isInCartMenu) {
//         animasiCart();
//         printf("\n\n");
//         printf("Enter command: ");
//         GetInput();
//         Word currentWord;
//         chartoWord(&currentWord, currentInput.TabWord);

//         if (isWordEqualToString(&currentWord, "CART")) {
//             ADVWORD(); 
//             Word commandType;
//             chartoWord(&commandType, currentInput.TabWord);

//             if (isWordEqualToString(&commandType, "ADD")) {
//                 ADVWORD();
//                 Word itemWord;
//                 chartoWord(&itemWord, currentInput.TabWord);

//                 ADVWORD();
//                 Word quantityWord;
//                 chartoWord(&quantityWord, currentInput.TabWord);

//                 int qty = WordToInt(&quantityWord);
//                 char itemName[50];
//                 WordToChar(&itemWord, itemName);

//                 AddCart(keranjang, itemName, qty, barangList);
//                 tunggu(3);
//             } else if (isWordEqualToString(&commandType, "REMOVE")) {
//                 ADVWORD();
//                 Word itemWord;
//                 chartoWord(&itemWord, currentInput.TabWord);

//                 ADVWORD();
//                 Word quantityWord;
//                 chartoWord(&quantityWord, currentInput.TabWord);

//                 int qty = WordToInt(&quantityWord);
//                 char itemName[50];
//                 WordToChar(&itemWord, itemName);

//                 RemoveCart(keranjang, itemName, qty);
//                 tunggu(3);
//             } else if (isWordEqualToString(&commandType, "SHOW")) {
//                 printf("TBA\n");
//             } else if (isWordEqualToString(&commandType, "PAY")) {
//                 printf("TBA\n");
//             } else {
//                 printf("Invalid command!\n");
//             }
//         } else if (isWordEqualToString(&currentWord, "HELP")) {
//              help(currentMenu);
//         } else if (isWordEqualToString(&currentWord, "MENU")) {
//             isInCartMenu = false;
//             printf("Returning to Main Menu...\n");
//         } else {
//             printf("Invalid command. Please try again.\n");
//         }
//     }
// }
