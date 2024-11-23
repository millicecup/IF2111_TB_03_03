#ifndef HANDLER_H
#define HANDLER_H

#include "../../ADT/User_Barang/user.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/queue/queue.h"
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
