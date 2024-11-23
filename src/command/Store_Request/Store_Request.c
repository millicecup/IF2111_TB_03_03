#include <stdio.h>
#include <stdlib.h>

#include "../../ADT/boolean.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/queue/queue.h"
#include "../Store_List/Store_List.h"
#include "Store_Request.h"

void StoreRequest(Queue *q, BarangList *store)  
{
    if (!IsFullRequest(*q))
    {
        Barang item;
        printf("Nama barang yang diminta: ");
        STARTINPUT(stdin);

        assignString(item.name, currentInput.TabWord); 

        if (IsMemberQueue(*q, item.name))
        {
            printf("Barang dengan nama yang sama sudah ada di antrian!\n");
        }
        else if (isMemberList(*store, toKata(item.name)))
        {
            printf("Barang dengan nama yang sama sudah ada di toko!\n");
        }
        else
        {
            EnqueueItem(q, item.name);
            printf("Barang berhasil dimasukkan ke antrian!\n");
        }
    }
}
