#ifndef ARRAY_DINAMIK_H
#define ARRAY_DINAMIK_H

#include "../Mesin_Kata/mesinkata.h"
#include "../boolean.h"
#include "../user/user.h"

#define InitialSize 10
#define MAX_LEN 50

typedef int IdxType;

/* Array structure */
typedef struct {
    User *A;       // Pointer to the dynamic array
    int Capacity;  // Maximum capacity of the array
    int Neff;      // Effective number of elements
} ArrayDin;

/* Function prototypes */
ArrayDin MakeArrayDin();
/* 
{ I.S. : sembarang }
{ F.S. : Mengembalikan ArrayDin kosong dengan ukuran InitialSize }
*/
void DeallocateArrayDin(ArrayDin *array);
/*
{ I.S. : ArrayDin terdefinisi }
{ F.S. : array->A terdealokasi }
*/
boolean IsEmpty(ArrayDin array);
/*
{ I.S. : ArrayDin terdefinisi }
{ F.S. : Mengembalikan true jika Neff = 0 }
*/
int Length(ArrayDin array);
/*
{ I.S. : ArrayDin terdefinisi }
{ F.S. : Mengembalikan Neff }
*/
User Get(ArrayDin array, IdxType i);
/*
{ I.S. : ArrayDin terdefinisi, i di antara 0..Length(array) }
{ F.S. : Mengembalikan elemen ke-i dari array }
*/
int GetCapacity(ArrayDin array);
/*
{ I.S. : ArrayDin terdefinisi }
{ F.S. : Mengembalikan Capacity }
*/
void InsertAt(ArrayDin *array, User el, IdxType i);
/*
{ I.S. : ArrayDin terdefinisi, i di antara 0..Length(array) }
{ F.S. : Menambahkan elemen el ke array
*/
void InsertLast(ArrayDin *array, User el);
/*
{ I.S. : ArrayDin terdefinisi }
{ F.S. : Menambahkan elemen el di akhir array }
*/
void InsertFirst(ArrayDin *array, User el);
/*
{ I.S. : ArrayDin terdefinisi }
{ F.S. : Menambahkan elemen el di awal array }
*/
void DeleteAt(ArrayDin *array, IdxType i);
/*
{ I.S. : ArrayDin terdefinisi, i di antara 0..Length(array) }
{ F.S. : Menghapus elemen ke-i dari array }
*/
void DeleteLast(ArrayDin *array);
/*
{ I.S. : ArrayDin terdefinisi }
{ F.S. : Menghapus elemen terakhir dari array }
*/
void DeleteFirst(ArrayDin *array);
/*
{ I.S. : ArrayDin terdefinisi }
{ F.S. : Menghapus elemen pertama dari array }
*/
void PrintArrayDin(ArrayDin array);
/*
{ I.S. : ArrayDin terdefinisi }
{ F.S. : Menampilkan isi array ke layar }
*/
void ReverseArrayDin(ArrayDin *array);
/*
{ I.S. : ArrayDin terdefinisi }
{ F.S. : Membalikkan isi array }
*/
ArrayDin CopyArrayDin(ArrayDin array);
/*
{ I.S. : ArrayDin terdefinisi }
{ F.S. : Menghasilkan salinan array }
*/
IdxType SearchArrayDin(ArrayDin array, Word name);
/*
{ I.S. : ArrayDin terdefinisi, name diberikan }
{ F.S. : Mengembalikan indeks pertama elemen dengan name tersebut, -1 jika tidak ditemukan }
*/

#endif
