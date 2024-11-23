#include <stdio.h>
#include <stdlib.h>

#include "../../ADT/boolean.h"
#include "../../ADT/List Barang/listdin_barang.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Queue/queue.h"
#include "../Store List/Store_List.h"
#include "../Store Request/Store_Request.h"
#include "Store_Supply.h"

void storeSupply(Arraybarang *store, Queue *request)
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
        wordToString(&currentWord, input);

        if (isEqualString(input, "Terima") || isEqualString(input, "Tunda") || isEqualString(input, "Tolak"))
        {
            Barang req;
            assignString(req.name, HEADitem(*request));
            DequeueRequest(request);

            if (isEqualString(input, "Terima"))
            {
                printf("Harga barang: ");
                STARTINPUT(stdin);
                int price = WordToInt(&currentWord);

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

