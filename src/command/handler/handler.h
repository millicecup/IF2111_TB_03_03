#ifndef HANDLER_H
#define HANDLER_H

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

// Function declarations
void handleStoreMenu(UserList *userList, BarangList *barangList, Queue *request, MenuState *currentMenu);
void handleWorkChallengeMenu(UserList *userList, MenuState *currentMenu);
void handleWorkMenu(UserList *userList, BarangList *barangList, MenuState *currentMenu);
void handleInsideMenu(UserList *userList, BarangList *barangList, Queue *request, MenuState *currentMenu);
void handleLoginMenu(UserList *userList, BarangList *barangList, Queue *request, MenuState *currentMenu);
void handleMainMenu(UserList *userList, BarangList *barangList, boolean *running, Queue *request, MenuState *currentMenu);

#endif
