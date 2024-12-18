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

// Fungsi untuk handle store menu
void handleStoreMenu(UserList *userList, BarangList *barangList, Queue *request, MenuState *currentMenu);

void handleWorkChallenge(UserList *userList, MenuState *currentMenu);

// Fungsi untuk handle menu
void handleInsideMenu(UserList *userList, BarangList *barangList, Queue *request, Keranjang *cart, Wishlist *wishlist, History *history, MenuState *currentMenu);

// Fungsi untuk handle login menu
void handleLoginMenu(UserList *userList, BarangList *barangList, Queue *request, Keranjang *cart, Wishlist *wishlist, History *history, MenuState *currentMenu);

// Fungsi untuk handle main menu
void handleMainMenu(UserList *userList, BarangList *barangList, boolean *running, Queue *request, Keranjang *cart, Wishlist *wishlist, History *history, MenuState *currentMenu);

// Fungsi untuk handle cart menu
void handleCartMenu(UserList *userList, BarangList *barangList, Keranjang *keranjang, MenuState *currentMenu);

// Fungsi untuk handle wishlist menu
void handleWishlistMenu(UserList *userList, BarangList *barangList, Wishlist *wishlist, MenuState *currentMenu);