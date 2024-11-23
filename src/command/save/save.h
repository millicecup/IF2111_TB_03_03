#ifndef SAVE
#define SAVE
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/User_Barang/user.h"
#include "../../ADT/boolean.h"
void SaveToFile(const char *filename, const BarangList *barangArray, const UserList *userArray);
#endif