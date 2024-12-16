#ifndef LOAD_H
#define LOAD_H

#include "../../ADT/User_Barang/user.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Baris/mesinbaris.h"
#include "../work/work.h"
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/Stack/stack.h"

// Function to load both BarangList and UserList from a file
boolean LoadConfig(const char *filename, UserList *userList, BarangList *barangList);

boolean Load(UserList *userList, BarangList *barangList) ;
#endif 