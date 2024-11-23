#ifndef STORELIST_H
#define STORELIST_H

#include "../../ADT/boolean.h"
#include "../../ADT/User_Barang/barang.h"
//#include "../../ADT/List_Barang/listdin_barang.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"

boolean IsUnique(BarangList store, int index);
/* mengembalikan true jika elemen unik */

void DisplayStore(BarangList store);
/* mencetak barang di store secara unik (tidak mencetak duplikat) */

void AddStoreItem(BarangList *storeItems, Barang newItem);
void RemoveStoreItem(BarangList *storeItems, Word itemName);
void InitializeStore(BarangList *storeItems);



#endif
