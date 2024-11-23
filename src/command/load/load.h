#ifndef LOAD_H
#define LOAD_H

#include "../../ADT/User_Barang/user.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Baris/mesinbaris.h"

// Function to load both BarangList and UserList from a file
void LoadConfig(const char *filename, UserList *userList, BarangList *barangList);

void Load(UserList *userList, BarangList *barangList);
#endif 