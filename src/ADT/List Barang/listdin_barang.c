#include <stdio.h>
#include <stdlib.h>
#include "listdin_barang.h"
#include "../Mesin_Kata/mesinkata.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk Arraybarang kosong dengan ukuran InitialSize
 */
Arraybarang MakeArrayDin() 
{
    Arraybarang array;
    array.A = (Barang *)malloc(InitialSize * sizeof(Barang)); // Alokasi memori array
    array.Capacity = InitialSize; 
    array.Neff = 0; 
    return array;
}


void DeallocateArrayDin(Arraybarang *array) 
{
    free(array->A); 
}


boolean IsEmpty(Arraybarang array) 
{
    return array.Neff == 0;
}


int Length(Arraybarang array) 
{
    return array.Neff;
}


Barang Get(Arraybarang array, IdxType i) 
{
    return array.A[i];
}


int GetCapacity(Arraybarang array) 
{
    return array.Capacity;
}


void InsertAt(Arraybarang *array, Barang el, IdxType i) 
{
    int length = Length(*array); 
    int capacity = GetCapacity(*array); 

    // Kalo arraynya full di expand
    if (length == capacity) 
    {
        int desiredCapacity = capacity + InitialSize; 
        Barang *arr = (Barang *)malloc(desiredCapacity * sizeof(Barang)); // Alokasi array baru
        for (int a = 0; a < length; a++) {
            arr[a] = Get(*array, a); // Copy elemen ke array baru
        }
        free(array->A); // Free array lama
        array->A = arr; // Update pointer array
        array->Capacity = desiredCapacity; // Update kapasitas
    }

    //  Geser elemen
    for (int a = length - 1; a >= i; a--) {
        array->A[a + 1] = array->A[a];
    }

    array->A[i] = el; //Menambah elemen
    array->Neff++; 
}


void InsertLast(Arraybarang *array, Barang el) 
{
    InsertAt(array, el, Length(*array)); 
}


void InsertFirst(Arraybarang *array, Barang el) {
    InsertAt(array, el, 0); // Menambah elemen pada indeks 0
}



void DeleteAt(Arraybarang *array, IdxType i) 
{
    for (int a = i; a < array->Neff - 1; a++) 
    {
        array->A[a] = array->A[a + 1]; // Geser elemen ke kiri
    }
    array->Neff--; 
}

void DeleteLast(Arraybarang *array) 
{
    DeleteAt(array, Length(*array) - 1); // Hapus elemen terakhir
}

void DeleteFirst(Arraybarang *array) 
{
    DeleteAt(array, 0); // Hapus elemen pertama
}


void initBarang(Barang *barang, char *name, int price) 
{
    assignString(barang->name, name);
    barang->price = price; 
}


void PrintArrayDin(Arraybarang array) 
{
    if (IsEmpty(array)) {
        printf("[]\n"); // Print array kosong
    } else {
        printf("[\n");
        for (int i = 0; i < array.Neff; i++) {
            printf("  {name: ");
            for (int j = 0; j < Length(array); j++) {
                printf("%c", array.A[i].name); // Print nama barang
            }
            printf(", money: %d}", array.A[i].price); // Print harga barang
            if (i < array.Neff - 1) {
                printf(",\n");
            }
        }
        printf("\n]\n");
    }
}



void ReverseArrayDin(Arraybarang *array) 
{
    int length = Length(*array);
    for (int i = 0; i < length / 2; i++) {
        Barang temp = array->A[i];
        array->A[i] = array->A[length - i - 1];
        array->A[length - i - 1] = temp;
    }
}


Arraybarang CopyArrayDin(Arraybarang array) 
{
    Arraybarang copy = MakeArrayDin(); // Buat array baru
    for (int i = 0; i < array.Neff; i++) {
        InsertLast(&copy, array.A[i]); // Pindahin elemen ke array baru
    }
    return copy;
}

IdxType SearchArrayDin(Arraybarang array, char *name) 
{
    for (int i = 0; i < array.Neff; i++) {
        if (isEqualString(array.A[i].name, name)) {
            return i; 
        }
    }
    return -1; //Return -1 kalo gaketemu
}

boolean isMemberList(Arraybarang array, char *name)
{
    int i;
    for(i = 0; i < Length(array); i++)
    {
        if(isEqualString(array.A[i].name, name))
        {
            return true;
        }
    }
    return false;
}

int countString (char *str) 
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}