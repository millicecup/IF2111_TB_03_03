#include <stdio.h>
#include "queue.h"
#include "../boolean.h"
#include "../mesin_kata/mesinkata.h"
#include "../Mesin_Baris/mesinbaris.h"
#include "../User_Barang/barang.h"

int main() {
    Queue q;
    CreateEmptyRequest(&q);

    printf("=== TEST QUEUE OPERATIONS ===\n");

    // 1. Test CreateEmptyRequest
    printf("Queue created.\n");
    printf("Is queue empty? %s\n", IsEmptyRequest(q) ? "Yes" : "No");

    // 2. Test EnqueueItem
    printf("\n=== ENQUEUE ITEM ===\n");
    EnqueueItem(&q, "item1");
    EnqueueItem(&q, "item2");
    EnqueueItem(&q, "item3");

    printf("Items added to queue.\n");
    DisplayQueue(&q);

    // 3. Test IsMemberQueue
    printf("\n=== IS MEMBER QUEUE ===\n");
    printf("Is 'item1' in queue? %s\n", IsMemberQueue(q, "item1") ? "Yes" : "No");
    printf("Is 'item4' in queue? %s\n", IsMemberQueue(q, "item4") ? "Yes" : "No");

    // 4. Test DequeueRequest
    printf("\n=== DEQUEUE ITEM ===\n");
    Barang dequeuedItem = DequeueRequest(&q);
    printf("Dequeued: %s\n", dequeuedItem.name);
    DisplayQueue(&q);

    dequeuedItem = DequeueRequest(&q);
    printf("Dequeued: %s\n", dequeuedItem.name);
    DisplayQueue(&q);

    // 5. Test Full Queue
    printf("\n=== FILLING QUEUE TO FULL ===\n");
    for (int i = 0; i < IDX_MAXQueue - 1; i++) {
        char itemName[10];
        sprintf(itemName, "item%d", i + 4);
        EnqueueItem(&q, itemName);
    }
    printf("Queue filled.\n");
    DisplayQueue(&q);

    // Test if queue is full
    printf("Is queue full? %s\n", IsFullRequest(q) ? "Yes" : "No");

    // Attempt to enqueue on full queue
    EnqueueItem(&q, "overflowItem");

    // 6. Test Empty Queue
    printf("\n=== EMPTYING QUEUE ===\n");
    while (!IsEmptyRequest(q)) {
        dequeuedItem = DequeueRequest(&q);
        printf("Dequeued: %s\n", dequeuedItem.name);
    }
    printf("Queue emptied.\n");
    DisplayQueue(&q);
    printf("Is queue empty? %s\n", IsEmptyRequest(q) ? "Yes" : "No");

    return 0;
}
