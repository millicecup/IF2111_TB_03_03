#include <stdio.h>
#include "../../ADT/Stack/stack.h"

void DisplayHistory(History H, int N)
{
    if (IsEmptyStack(H))
    {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }
    else
    {
        History temp = H;
        char itemName[Max_Length];
        int itemPrice, itemQuantity;
        printf("Riwayat pembelian barang:\n");
        for (int i = 0; i < N && !IsEmptyStack(temp); i++)
        {
            PopStack(&temp, itemName, &itemPrice, &itemQuantity);
            int totalPrice = itemPrice * itemQuantity;
            printf("%d. %s %d\n", i+1, itemName, totalPrice);
            // printf("%d. ", i+1);
            // TulisWordNoNL(toKata(itemName));
            // printf(" %d\n", totalPrice);
        }
    }
}
