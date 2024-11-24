#ifndef QUIT_H
#define QUIT_H

#include "../../command/login/login.h"
#include "../../ADT/user_barang/user.h" 
#include "../../ADT/boolean.h"
#include "../../command/save/save.h"

// Deklarasi fungsi logout
void quit(boolean *issave, UserList list);

#endif