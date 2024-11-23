#ifndef __BARANG_H_
#define __BARANG_H_

#include "../Mesin_Kata/mesinkata.h"
#include "../boolean.h"
#define MAX_LEN 100
#define InitialSize 10
// #define MAX_LEN 50
#define IdxType int

typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;

typedef struct {
    Barang *items; // Pointer ke array dinamis
    int count;     // Jumlah barang saat ini
    int capacity;  // Kapasitas maksimum saat ini
} BarangList;

// void ManualStringCopy2(char *dest, char *src);

void CreateBarangList(BarangList *list, int capacity);

void AddBarang(BarangList *list, char *name, int price);

void PrintBarang(BarangList *list);

void FreeBarangList(BarangList *list);

BarangList MakeArrayDin();
/* 
{ I.S. : sembarang }
{ F.S. : Mengembalikan BarangList kosong dengan ukuran InitialSize }
*/

/* Deallocate memory used by the dynamic array */
void DeallocateArrayDin(BarangList *array);
/*
{ I.S. : BarangList terdefinisi }
{ F.S. : array->A terdealokasi }
*/

/* Check if the array is empty */
boolean IsEmpty(BarangList array);
/*
{ I.S. : BarangList terdefinisi }
{ F.S. : Mengembalikan true jika Neff = 0 }
*/

/* Get the length (number of elements) of the array */
int Length(BarangList array);
/*
{ I.S. : BarangList terdefinisi }
{ F.S. : Mengembalikan Neff }
*/

/* Get the element at index i */
Barang Get(BarangList array, IdxType i);
/*
{ I.S. : BarangList terdefinisi, i di antara 0..Length(array) }
{ F.S. : Mengembalikan elemen ke-i dari array }
*/

/* Get the capacity of the array */
int GetCapacity(BarangList array);
/*
{ I.S. : BarangList terdefinisi }
{ F.S. : Mengembalikan Capacity }
*/

/* Insert a Barang element at a specific index */
void InsertAt(BarangList *array, Barang el, IdxType i);
/*
{ I.S. : BarangList terdefinisi, i di antara 0..Length(array) }
{ F.S. : Menambahkan elemen el ke array }
*/

/* Insert a Barang element at the end of the array */
void InsertLast(BarangList *array, Barang el);
/*
{ I.S. : BarangList terdefinisi }
{ F.S. : Menambahkan elemen el di akhir array }
*/

/* Insert a Barang element at the start of the array */
void InsertFirst(BarangList *array, Barang el);
/*
{ I.S. : BarangList terdefinisi }
{ F.S. : Menambahkan elemen el di awal array }
*/

/* Delete a Barang element at a specific index */
void DeleteAt(BarangList *array, IdxType i);
/*
{ I.S. : BarangList terdefinisi, i di antara 0..Length(array) }
{ F.S. : Menghapus elemen ke-i dari array }
*/

/* Delete the last Barang element from the array */
void DeleteLast(BarangList *array);
/*
{ I.S. : BarangList terdefinisi }
{ F.S. : Menghapus elemen terakhir dari array }
*/

/* Delete the first Barang element from the array */
void DeleteFirst(BarangList *array);
/*
{ I.S. : BarangList terdefinisi }
{ F.S. : Menghapus elemen pertama dari array }
*/

void initBarang(Barang *Barang, Word *name, int price);
/*
{ I.S. : Barang sembarang }
{ F.S. : Barang terdefinisi dengan name = name dan password = password }
*/

/* Print the dynamic array of Barang */
void PrintArrayDin(BarangList array);
/*
{ I.S. : BarangList terdefinisi }
{ F.S. : Menampilkan isi array ke layar }
*/

/* Reverse the order of elements in the array */
void ReverseArrayDin(BarangList *array);
/*
{ I.S. : BarangList terdefinisi }
{ F.S. : Membalikkan isi array }
*/

/* Create a copy of the dynamic array */
BarangList CopyArrayDin(BarangList array);
/*
{ I.S. : BarangList terdefinisi }
{ F.S. : Menghasilkan salinan array }
*/

/* Search for a Barang by name */
IdxType SearchArrayDin(BarangList array, Word name);
/*
{ I.S. : BarangList terdefinisi, name diberikan }
{ F.S. : Mengembalikan indeks pertama elemen dengan name tersebut, -1 jika tidak ditemukan }
*/

boolean isMemberList(BarangList array, Word name);


#endif