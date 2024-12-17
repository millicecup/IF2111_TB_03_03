#include <stdio.h>
#include <stdlib.h>

#include "cart_add.h"

void AddCart(Keranjang *k, char *itemName, int qty, BarangList *store)
{
    if (IsEmptyBasket(*k))
    {
        if (isMemberList(*store, toKata(itemName)))
        {
            int idx = SearchArrayDin(*store, toKata(itemName));

            Barang item;
            assignString(item.name, itemName);
            item.price = store->items[idx].price;

            AddBasket(k, item, qty);
            printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", qty, itemName);
        }
        else
        {
            printf("Barang tidak ada di toko!");
        }
    }
}