#include <stdio.h>
#include <stdlib.h>

#include "cart_remove.h"

void RemoveCart(Keranjang *k, char *itemName, int qty)
{
    if (!IsMemberBasket(*k, itemName))
    {
        printf("Barang tidak ada di keranjang belanja!\n");
    }
    else
    {
        int idx = indeksBasket(*k, itemName);
        if (idx == undefined) 
        {
            printf("Barang tidak ada di keranjang belanja!\n");
            return;
        }
        if ((*k).quantity[idx] < qty) 
        {
            printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", (*k).quantity[idx], itemName);
        } 
        else 
        {
            DelBasket(k, (*k).item[idx], qty);
            printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", qty, itemName);
        }
    }
}