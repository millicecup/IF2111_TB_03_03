#ifndef ADTqueue_H
#define ADTqueue_H

#include "../boolean.h"
#include "../mesin_kata/mesinkata.h"
#include "../List Barang/listdin_barang.h"

#define IDX_UNDEFQ -1
#define MAX_STRING_LENGTH 50 
#define IDX_MAXQueue 100 

/* Definisi tipe elemen dan indeks pada Queue */
typedef struct {
        char item[IDX_MAXQueue+1][MAX_STRING_LENGTH];
        int price[IDX_MAXQueue+1];
        int idxHead;
        int idxTail;
} Queue;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEADitem(q) (q).item[(q).idxHead]
#define HEADprice(q) (q).price[(q).idxHead]
#define TAILitem(q) (q).item[(q).idxTail]
#define TAILprice(q) (q).price[(q).idxTail]

/* ********* Prototype ********* */
boolean IsEmptyRequest(Queue q);
/* mengembalikan true jika request kosong */

boolean IsFullRequest(Queue q);
/* mengembalikan true jika request penuh */

int LengthRequest(Queue q);
/* mengembalikan jumlah request pada queue q */

void CreateEmptyRequest(Queue *q);
/* membuat sebuah queue kosong */

/* ********* Primitif Add/Delete ********* */
void EnqueueRequest(Queue *q, char *item, int price);
/* menambahkan elemen item dan price pada queue q dengan aturan FIFO */

void EnqueueItem(Queue *q, char *item);
/* menambahkan elemen item pada queue q dengan aturan FIFO */

Barang DequeueRequest(Queue *q);
/* menambahkan elemen HEAD pada queue q sesuai aturan FIFO */

void DisplayQueue(Queue *q);
/**/

boolean IsMemberQueue(Queue q, char *elmt);

#endif