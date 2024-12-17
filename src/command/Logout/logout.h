#ifndef LOGOUT_H
#define LOGOUT_H

#include "../../command/login/login.h"
<<<<<<< HEAD
#include "../../ADT/user_barang/user.h" // Gunakan user.h untuk akses struktur User dan TabUser

// Deklarasi fungsi logout
void logout(boolean *LoggedIn, UserList list, User *iduser);
=======
#include "../../ADT/User_Barang/user.h" 
#include "../../ADT/boolean.h"

// Deklarasi fungsi logout
void logout(boolean *LoggedIn, UserList list);
>>>>>>> 14461a768f56c1fb4c3d01ed572ad58d173d89e0

#endif