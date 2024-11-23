#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>


#include "../../ADT/boolean.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Baris/mesinbaris.h"
#include "../Store_List/Store_List.h"

#include "Store_Remove.h"

void removeItem(BarangList *store, Barang item)
{
    if(!IsEmpty(*store))
    {
        printf("Nama barang yang akan dihapus: ");
        STARTINPUT(stdin);

        assignString(item.name, currentInput.TabWord);
        if(isMemberList(*store, toKata(item.name)))
        {
            int i;
            for(i = 0; i < Length(*store); i++)
            {
                if(isEqualString((*store).items[i].name, item.name))
                {
                    DeleteAt(store, i);
                    printf("%s telah berhasil dihapus.\n", item.name);
                    return;
                }
            }
        }
        else
        {
            printf("Toko tidak menjual %s.\n", item.name);
        }
    }
    else
    {
        printf("Toko kosong!.\n");
    }
}