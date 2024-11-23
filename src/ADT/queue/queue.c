#include <stdio.h>
#include <string.h> // For strlen
#include "queue.h"
#include "../mesin_kata/mesinkata.h"
#include "../User_Barang/barang.h"

/* ********* Prototype ********* */
boolean IsEmptyRequest(Queue q)
/* Mengembalikan true jika request kosong */
{
    return (IDX_HEAD(q) == IDX_UNDEFQ && IDX_TAIL(q) == IDX_UNDEFQ);
}

boolean IsFullRequest(Queue q)
/* Mengembalikan true jika request penuh */
{
    return ((IDX_TAIL(q) == IDX_MAXQueue - 1));
}

int LengthRequest(Queue q)
/* Mengembalikan jumlah request pada queue q */
{
    if (IsEmptyRequest(q)) {
        return 0;
    } else {
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
}

void CreateEmptyRequest(Queue *q)
/* Membuat sebuah queue kosong */
{
    IDX_HEAD(*q) = IDX_UNDEFQ;
    IDX_TAIL(*q) = IDX_UNDEFQ;
}

/* ********* Primitif Add/Delete ********* */
void EnqueueRequest(Queue *q, char *item, int price)
/* Menambahkan elemen item dan price pada queue q dengan aturan FIFO */
{
    if (IsFullRequest(*q)) {
        printf("Antrian penuh!.\n");
        return;
    }
    if (IsEmptyRequest(*q)) {
        IDX_HEAD(*q) = 0;
    } 
    else 
    {
        IDX_TAIL(*q)++;
    }

    assignString((*q).item[IDX_TAIL(*q)], item); // Gunakan fungsi assignString
    (*q).price[IDX_TAIL(*q)]= price;           // Set harga
}

void EnqueueItem(Queue *q, char *item)
/* Menambahkan elemen item ke queue q dengan aturan FIFO */
{
    if (IsFullRequest(*q)) {
        printf("Antrian penuh!.\n");
        return;
    }
    if (IsEmptyRequest(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        IDX_TAIL(*q)++;
    }

    assignString(TAILitem(*q), item); // Gunakan fungsi assignString
}

Barang DequeueRequest(Queue *q)
/* Menghapus elemen HEAD pada queue q sesuai aturan FIFO */
{
    Barang item;
    if (!IsEmptyRequest(*q)) {
        assignString(item.name, HEADitem(*q)); // Salin item dari head
        item.price = HEADprice(*q);            // Salin harga dari head

        if (LengthRequest(*q) == 1) {
            CreateEmptyRequest(q); // Kosongkan queue jika hanya ada 1 elemen
        } else {
            for (int i = IDX_HEAD(*q); i < IDX_TAIL(*q); i++) {
                assignString((*q).item[i], (*q).item[i + 1]); // Geser elemen ke kiri
                (*q).price[i] = (*q).price[i + 1];           // Geser harga ke kiri
            }
            IDX_TAIL(*q)--;
        }
    } else 
    {
        printf("Antrian kosong!.\n");
        assignString(item.name, ""); // Set nama barang kosong
        item.price = 0;
    }
    return item;
}

void DisplayQueue(Queue *q)
/* Menampilkan isi queue */
{
    printf("[");
    if (!IsEmptyRequest(*q)) {
        for (int i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++) {
            printf("%s", (*q).item[i]); // Tampilkan item dan harga
            if (i < IDX_TAIL(*q)) {
                printf(", ");
            }
        }
    }
    printf("]\n");
}

boolean IsMemberQueue(Queue q, char *elmt)
/* Mengembalikan true jika elmt terdapat dalam queue q */
{
    if (IsEmptyRequest(q)) {
        return false;
    }

    for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
        if (isEqualString(q.item[i], elmt)) { // Bandingkan string menggunakan isEqualString
            return true;
        }
    }

    return false;
}