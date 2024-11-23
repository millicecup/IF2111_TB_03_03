#ifndef BARANG_H
#define BARANG_H

#include "../Mesin_Kata/mesinkata.h"
#include "../boolean.h"

#define InitialSize 10
#define MAX_LEN 50
#define IdxType int

// Define the Barang structure with a name and price
typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;

/* Array structure for dynamic array of Barang */
typedef struct {
    Barang *A;      // Pointer to the dynamic array of Barang
    int Capacity;   // Maximum capacity of the array
    int Neff;       // Number of elements in the array
} Arraybarang;

/* Function prototypes */

/* Create a dynamic array of Barang */
Arraybarang MakeArrayDin();
/* 
{ I.S. : sembarang }
{ F.S. : Mengembalikan Arraybarang kosong dengan ukuran InitialSize }
*/

/* Deallocate memory used by the dynamic array */
void DeallocateArrayDin(Arraybarang *array);
/*
{ I.S. : Arraybarang terdefinisi }
{ F.S. : array->A terdealokasi }
*/

/* Check if the array is empty */
boolean IsEmpty(Arraybarang array);
/*
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Mengembalikan true jika Neff = 0 }
*/

/* Get the length (number of elements) of the array */
int Length(Arraybarang array);
/*
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Mengembalikan Neff }
*/

/* Get the element at index i */
Barang Get(Arraybarang array, IdxType i);
/*
{ I.S. : Arraybarang terdefinisi, i di antara 0..Length(array) }
{ F.S. : Mengembalikan elemen ke-i dari array }
*/

/* Get the capacity of the array */
int GetCapacity(Arraybarang array);
/*
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Mengembalikan Capacity }
*/

/* Insert a Barang element at a specific index */
void InsertAt(Arraybarang *array, Barang el, IdxType i);
/*
{ I.S. : Arraybarang terdefinisi, i di antara 0..Length(array) }
{ F.S. : Menambahkan elemen el ke array }
*/

/* Insert a Barang element at the end of the array */
void InsertLast(Arraybarang *array, Barang el);
/*
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Menambahkan elemen el di akhir array }
*/

/* Insert a Barang element at the start of the array */
void InsertFirst(Arraybarang *array, Barang el);
/*
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Menambahkan elemen el di awal array }
*/

/* Delete a Barang element at a specific index */
void DeleteAt(Arraybarang *array, IdxType i);
/*
{ I.S. : Arraybarang terdefinisi, i di antara 0..Length(array) }
{ F.S. : Menghapus elemen ke-i dari array }
*/

/* Delete the last Barang element from the array */
void DeleteLast(Arraybarang *array);
/*
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Menghapus elemen terakhir dari array }
*/

/* Delete the first Barang element from the array */
void DeleteFirst(Arraybarang *array);
/*
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Menghapus elemen pertama dari array }
*/

void initBarang(Barang *Barang, Word *name, int price);
/*
{ I.S. : Barang sembarang }
{ F.S. : Barang terdefinisi dengan name = name dan password = password }
*/

/* Print the dynamic array of Barang */

/*
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Menampilkan isi array ke layar }
*/

/* Reverse the order of elements in the array */
void ReverseArrayDin(Arraybarang *array);
/*
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Membalikkan isi array }
*/

/* Create a copy of the dynamic array */
Arraybarang CopyArrayDin(Arraybarang array);
/*
{ I.S. : Arraybarang terdefinisi }
{ F.S. : Menghasilkan salinan array }
*/

/* Search for a Barang by name */
IdxType SearchArrayDin(Arraybarang array, Word name);
/*
{ I.S. : Arraybarang terdefinisi, name diberikan }
{ F.S. : Mengembalikan indeks pertama elemen dengan name tersebut, -1 jika tidak ditemukan }
*/
void ClearArrayDin(Arraybarang *array);

void CreateBarangList(Arraybarang *list, int capacity);

void AddBarang(Arraybarang *list, char *name, int price);

void PrintBarang(Arraybarang *list);

void FreeBarangList(Arraybarang *list);


#endif // BARANG_H
