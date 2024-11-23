#include <stdio.h>
#include "../../ADT/Queue/queue.h"
#include "../../ADT/List Barang/listdin_barang.h"
#include "../Store Supply/Store_Supply.h"

int main() 
{
    Arraybarang store = MakeArrayDin();
    Queue request;
    CreateEmptyRequest(&request);

    EnqueueItem(&request, "Barang X");
    EnqueueItem(&request, "Barang Y");
    EnqueueItem(&request, "Barang Z");

    printf("Store List:\n");
    DisplayStore(store);
    printf("Store Request:\n");
    DisplayQueue(&request);

    storeSupply(&store, &request); 
    storeSupply(&store, &request); 

    printf("\nStore List (updated):\n");
    DisplayStore(store);
    printf("\nStore Request:\n");
    DisplayQueue(&request);

    return 0;
}
