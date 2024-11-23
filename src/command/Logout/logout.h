#ifndef LOGOUT_H
#define LOGOUT_H

#include "../../command/login/login.h"
#include "../../ADT/user_barang/user.h" // Gunakan user.h untuk akses struktur User dan TabUser

// Deklarasi fungsi logout
void logout(boolean *LoggedIn, UserList list, User *iduser);

#endif