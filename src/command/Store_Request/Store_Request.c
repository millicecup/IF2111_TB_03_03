#include <stdio.h>
#include <stdlib.h>

#include "../../ADT/boolean.h"
#include "../../ADT/List Barang/listdin_barang.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Queue/queue.h"
#include "../Store List/Store_List.h"
#include "Store_Request.h"

void StoreRequest(Queue *q, Barang item, Arraybarang store)  
{
    if (!IsFullRequest(*q))
    {
        printf("Nama barang yang diminta: ");
        STARTINPUT(stdin);

        assignString(item.name, currentWord.TabWord); 

        if (IsMemberQueue(*q, item.name))
        {
            printf("Barang dengan nama yang sama sudah ada di antrian!\n");
        }
        else if (isMemberList(store, item.name))
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
