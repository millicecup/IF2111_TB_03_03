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
        printf("Jika ingin menambahkan barang, silahkan ketik 'Terima'.\n");
        printf("Jika ingin menolak, silahkan ketik 'Tolak'.\n");
        printf("Jika ingin menunda, silahkan ketik 'Tunda'.\n");
        printf("Pastikan Anda memasukkan jawaban dengan benar!\n");
        printf("Apakah kamu ingin menambahkan barang %s ?: ", HEADitem(*request));

        GetInput();
        Word currentWord;
        chartoWord(&currentWord, currentInput.TabWord);
        
        if (isWordEqualToString(&currentWord, "Terima") || isWordEqualToString(&currentWord, "Tunda") || isWordEqualToString(&currentWord, "Tolak"))
        {
            Barang req;
            assignString(req.name, HEADitem(*request));
            DequeueRequest(request);

            if (isWordEqualToString(&currentWord, "Terima"))
            {
                boolean isValidPrice = false;
                int price = 0;

                while(!isValidPrice)
                {
                    printf("Harga barang: ");
                    STARTINPUT(stdin);
                    price = WordToInt(&currentInput);

                    if (price > 0)
                    {
                        isValidPrice = true;
                    }
                    else
                    {
                        printf("Harga barang tidak valid!.\n");
                    }
                }
                req.price = price;
                InsertLast(store, req);
                printf("%s dengan harga %d telah ditambahkan ke toko.\n", req.name, price);
            }
            else if (isWordEqualToString(&currentWord, "Tunda"))
            {
                EnqueueItem(request, req.name);
                printf("%s dikembalikan ke antrian.\n", req.name);
            }
            else if (isWordEqualToString(&currentWord, "Tolak"))
            {
                printf("%s dihapuskan dari antrian.\n", req.name);
            }
        }
    }
}

