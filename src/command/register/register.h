#ifndef REGISTER_H
#define REGISTER_H

#include "../../ADT/User_Barang/user.h"

// Register a new user
void registerUser(UserList *userArray);

/*
{ I.S. : User array terdefinisi, username dan password diberikan }
{ F.S. : Menambahkan user baru ke array, menyimpan data ke file jika sukses }
{ Mengembalikan 1 jika berhasil, 0 jika gagal }
*/

void saveuser(char *filename, UserList *userList);


#endif
