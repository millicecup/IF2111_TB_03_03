#include <stdio.h>
#include "../../ADT/Queue/queue.h"
#include "../../ADT/User_Barang/barang.h"
#include "Store_Supply.h"

int main() 
{
    BarangList store = MakeArrayDin();
    Queue request;
    CreateEmptyRequest(&request);

    EnqueueItem(&request, "Barang X");
    EnqueueItem(&request, "Barang Y");
    EnqueueItem(&request, "Barang Z");

    DisplayStore(store);
    printf("\n");
    printf("\nStore Request:\n");
    DisplayQueue(&request);

    storeSupply(&store, &request); 
    storeSupply(&store, &request); 

    printf("\nStore List (updated):\n");
    DisplayStore(store);
    printf("\nStore Request:\n");
    DisplayQueue(&request);

    return 0;
}
