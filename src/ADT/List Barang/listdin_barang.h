#ifndef BARANG_H
#define BARANG_H

#include "../Mesin_Kata/mesinkata.h"
#include "../boolean.h"

#define InitialSize 10
#define MAX_LEN 50
#define IdxType int

typedef struct {
    char name[MAX_LEN];  
    int price;  
} Barang;

typedef struct {
    Barang *A;      // Pointer ke arraydin Barang
    int Capacity;   // Max capacity Arraybarang
    int Neff;       // Jumlah elemen pada Arraybarang
} Arraybarang;


Arraybarang MakeArrayDin();
/* 
Membuat Arraybarang (dinamis)
{ I.S. : sembarang }
{ F.S. : Mengembalikan Arraybarang kosong dengan ukuran InitialSize }
*/

void DeallocateArrayDin(Arraybarang *array);
/*
Dealokasi memori yang digunakan oleh array dinamis
{ I.S. : Arraybarang terdefinisi }
{ F.S. : array->A terdealokasi }
*/

boolean IsEmpty(Arraybarang array);
/*
Mengembalikan true jika Arraybarang array kosong
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Mengembalikan true jika Neff = 0 }
*/

int Length(Arraybarang array);
/*
Mengembalikan panjang Arraybarang array
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Mengembalikan Neff }
*/


Barang Get(Arraybarang array, IdxType i);
/*
{ I.S. : Arraybarang terdefinisi, i di antara 0..Length(array) }
{ F.S. : Mengembalikan elemen ke-i dari array }
*/

int GetCapacity(Arraybarang array);
/*
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Mengembalikan Capacity }
*/

void InsertAt(Arraybarang *array, Barang el, IdxType i);
/*
Menambahkan barang el ke dalam Arraybarang array pada indeks i
{ I.S. : Arraybarang terdefinisi, i di antara 0..Length(array) }
{ F.S. : Menambahkan elemen el ke array }
*/

void InsertLast(Arraybarang *array, Barang el);
/*
Menambahkan barang el ke akhir Arraybarang array 
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Menambahkan elemen el di akhir array }
*/


void InsertFirst(Arraybarang *array, Barang el);
/*
Menambahkan barang el ke awal Arraybarang array 
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Menambahkan elemen el di awal array }
*/

void DeleteAt(Arraybarang *array, IdxType i);
/*
Menghapus barang el dari Arraybarang array pada indeks i
{ I.S. : Arraybarang terdefinisi, i di antara 0..Length(array) }
{ F.S. : Menghapus elemen ke-i dari array }
*/

void DeleteLast(Arraybarang *array);
/*
Menghapus barang el dari Arraybarang array pada indeks terakhir
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Menghapus elemen terakhir dari array }
*/

void DeleteFirst(Arraybarang *array);
/*
Menghapus barang el dari Arraybarang array pada indeks pertama
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Menghapus elemen pertama dari array }
*/

void initBarang(Barang *Barang, char *name, int price);
/*
{ I.S. : Barang sembarang }
{ F.S. : Barang terdefinisi dengan name = name dan password = password }
*/

void PrintArrayDin(Arraybarang array);
/*
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Menampilkan isi array ke layar }
*/

void ReverseArrayDin(Arraybarang *array);
/*
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Membalikkan isi array }
*/

Arraybarang CopyArrayDin(Arraybarang array);
/*
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Menghasilkan salinan array }
*/

IdxType SearchArrayDin(Arraybarang array, char *name);
/*
{ I.S. : Arraybarang terdefinisi, name diberikan }
{ F.S. : Mengembalikan indeks pertama elemen dengan name tersebut, -1 jika tidak ditemukan }
*/

boolean isMemberList(Arraybarang array, char *name);
/* Mengembalikan true jika name terdapat pada Arraybarang array */

int countString (char *str);
/* Mengembalikan panjang string */


#endif // BARANG_H