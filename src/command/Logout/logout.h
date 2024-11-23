#ifndef LOGOUT_H
#define LOGOUT_H

#include "../../command/login/login.h"
#include "../../ADT/user_barang/user.h" 
#include "../../ADT/boolean.h"

// Deklarasi fungsi logout
void logout(boolean *LoggedIn, UserList list);

#endif