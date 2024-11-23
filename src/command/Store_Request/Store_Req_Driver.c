#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/Queue/queue.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../Store_List/Store_List.h"
#include "Store_Request.h"


int main() 
{
    Queue q;
    CreateEmptyRequest(&q);

    BarangList store = MakeArrayDin(); 

    Barang item1, item2;
    Word namaBarang1, namaBarang2;

    assignString(item1.name, "Adaditoko");
    item1.price = 100;
    assignString(item2.name, "Barang Purry");
    item2.price = 200;

    InsertLast(&store, item1); 
    InsertLast(&store, item2); 
    DisplayStore(store);


    StoreRequest(&q, &store); 
    printf("\n");
    StoreRequest(&q, &store); 

    printf("\nAntrian Barang:\n");
    DisplayQueue(&q);

    return 0;
}
