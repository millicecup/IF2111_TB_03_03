#include <stdio.h>
#include <stdlib.h>

#include "../../ADT/boolean.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Queue/queue.h"
#include "../Store_List/Store_List.h"
#include "../Store_Request/Store_Request.h"
#include "Store_Supply.h"

void storeSupply(BarangList *store, Queue *request)
{
    if(IsEmptyRequest(*request))
    {
        printf("Tidak ada barang di antrian!\n");
        return;
    }
    else
    {
        printf("Apakah kamu ingin menambahkan barang %s ?: ", HEADitem(*request));
        STARTINPUT(stdin);

        char input[50];
        WordToChar(&currentInput, input);

        if (isEqualString(input, "Terima") || isEqualString(input, "Tunda") || isEqualString(input, "Tolak"))
        {
            Barang req;
            assignString(req.name, HEADitem(*request));
            DequeueRequest(request);

            if (isEqualString(input, "Terima"))
            {
                printf("Harga barang: ");
                STARTINPUT(stdin);
                int price = WordToInt(&currentInput);

                if (price > 0)
                {
                    req.price = price;
                    InsertLast(store, req);
                    printf("%s dengan harga %d telah ditambahkan ke toko.\n", req.name, price);
                }
                else
                {
                    printf("Harga barang tidak valid!.\n");
                }
            }
            else if (isEqualString(input, "Tunda"))
            {
                EnqueueItem(request, req.name);
                printf("%s dikembalikan ke antrian.\n", req.name);
            }
            else if (isEqualString(input, "Tolak"))
            {
                printf("%s dihapuskan dari antrian.\n", req.name);
            }
        }
    }
}

