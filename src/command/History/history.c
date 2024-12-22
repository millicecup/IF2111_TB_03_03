#include <stdio.h>
#include "../../ADT/Stack/stack.h"
#include "../../ADT/User_Barang/user.h"

void DisplayHistory(int N, UserList *userList)
{
    User *currentUser = &userList->users[userList->currentUserIndex];

    if (IsEmptyStack(currentUser->riwayat_pembelian))
    {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }
    else
    {
        History H = currentUser->riwayat_pembelian;
        char itemName[Max_Length];
        int itemPrice, itemQuantity;
        printf("Riwayat pembelian barang:\n");
        printf("+---------------------------------------------------+\n");
        printf("| No | Nama Barang                   | Total Harga  |\n");
        printf("+---------------------------------------------------+\n");
        for (int i = 0; i < N && !IsEmptyStack(H); i++)
        {
            PopStack(&H, itemName, &itemPrice, &itemQuantity);
            int totalPrice = itemPrice * itemQuantity;
            //printf("%d. %s %d\n", i+1, itemName, totalPrice);
            printf("| %-3d| %-30s| %-13d|\n", i+1, itemName, totalPrice);
        }
        printf("+---------------------------------------------------+\n");
    }
}
