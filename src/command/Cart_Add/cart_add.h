#ifndef CART_ADD_H
#define CART_ADD_H

#include "../../ADT/boolean.h"
#include "../../ADT/SetMap/setmap.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../Store_List/Store_List.h"

void AddCart(Keranjang *k, char *itemName, int qty, BarangList *store);

#endif 