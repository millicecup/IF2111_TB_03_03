#include <stdio.h>
#include <stdlib.h>

#include "../../ADT/boolean.h"
#include "../../ADT/User_Barang/barang.h"
//#include "../../ADT/List_Barang/listdin_barang.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "Store_List.h"

boolean IsUnique(BarangList store, int idx) 
{
    for (int i = 0; i < idx; i++) 
    {
        if (IsWordEqual(toKata(store.items[idx].name), toKata(store.items[i].name))) 
        {
            return false; 
        }
    }
    return true; 
}

void DisplayStore (BarangList store)
{
    int i;
    printf(">> STORE LIST\n");

    if(!IsEmpty(store))
    {
        for(int i = 0; i < Length(store) ; i++)
        {
            if(IsUnique(store, i))
            {
                printf("- ");
                TulisWord(toKata(store.items[i].name));
                printf("\n");
            }
        }
    }
    else
    {
        printf("TOKO KOSONG");
    }    
}

// nanti fetch dari data (?)
// void InitializeStore(BarangList *storeItems) {
//     Barang item1, item2, item3;

//     Word name1;
//     stringToWord("Item1", &name1);
//     item1.name = name1;

//     Word name2;
//     stringToWord("Item2", &name2);
//     item2.name = name2;

//     Word name3;
//     stringToWord("Item3", &name3);
//     item3.name = name3;

//     InsertLast(storeItems, item1);
//     InsertLast(storeItems, item2);
//     InsertLast(storeItems, item3);
//     printf("Store initialized with default items.\n");
// }