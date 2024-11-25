#ifndef LOGIN_H
#define LOGIN_H

#include "../../ADT/User_Barang/user.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"

#include "../../ADT/boolean.h"

extern boolean loggedIn;
void login(UserList *userList);

#endif