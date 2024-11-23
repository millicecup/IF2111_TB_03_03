#include <stdio.h>
#include <stdlib.h>
#include "../Mesin_Kata/mesinkata.h"
#include "barang.h"

// *** Fungsi untuk Operasi String Manual ***
void ManualStringCopy2(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Tambahkan null terminator
}

// *** Fungsi List Dinamis Barang ***
void CreateBarangList(BarangList *list, int capacity) {
    list->items = (Barang *)malloc(capacity * sizeof(Barang)); // Alokasi memori awal
    list->count = 0;                                           // Jumlah barang awal
    list->capacity = capacity;                                // Kapasitas awal
}

void AddBarang(BarangList *list, char *name, int price) {
    // Periksa apakah kapasitas penuh
    if (list->count == list->capacity) {
        list->capacity *= 2; // Gandakan kapasitas
        list->items = (Barang *)realloc(list->items, list->capacity * sizeof(Barang));
    }
    // Salin nama barang ke dalam array menggunakan manual string copy
    ManualStringCopy2(list->items[list->count].name, name);
    list->items[list->count].price = price; // Simpan harga barang
    list->count++; // Tambahkan jumlah barang
}

void PrintBarang(BarangList *list) {
    // Iterasi untuk mencetak semua barang
    for (int i = 0; i < list->count; i++) {
        printf("Barang %d: Nama: %s, Harga: %d\n", i + 1, list->items[i].name, list->items[i].price);
    }
}

void FreeBarangList(BarangList *list) {
    free(list->items); // Bebaskan memori yang dialokasikan
}

BarangList MakeArrayDin() {
    BarangList array;
    array.items = (Barang *)malloc(InitialSize * sizeof(Barang)); // Allocate memory for barang array
    array.capacity = InitialSize; // Set initial capacity
    array.count = 0; // Initial number of items is 0
    return array;
}

/* Deallocates the dynamic array memory */
void DeallocateArrayDin(BarangList *array) {
    free(array->items); // Free the allocated memory for barang array
}

/* Check if the array is empty */
boolean IsEmpty(BarangList array) {
    return array.count == 0;
}

/* Get the number of elements in the array */
int Length(BarangList array) {
    return array.count;
}

/* Get the element at index i */
Barang Get(BarangList array, IdxType i) {
    return array.items[i]; // Return the barang at index i
}

/* Get the capacity of the array */
int GetCapacity(BarangList array) {
    return array.capacity;
}

/* Insert an element at a specific index */
void InsertAt(BarangList *array, Barang el, IdxType i) {
    int length = Length(*array); // Get the current number of elements
    int capacity = GetCapacity(*array); // Get current capacity

    // If the array is full, expand it
    if (length == capacity) {
        int desiredCapacity = capacity + InitialSize; // Increase capacity by InitialSize
        Barang *arr = (Barang *)malloc(desiredCapacity * sizeof(Barang)); // Allocate new array
        for (int a = 0; a < length; a++) {
            arr[a] = Get(*array, a); // Copy elements to the new array
        }
        free(array->items); // Free the old array
        array->items = arr; // Update the array pointer
        array->capacity = desiredCapacity; // Update the capacity
    }

    // Shift elements to the right to make room for the new element
    for (int a = length - 1; a >= i; a--) {
        array->items[a + 1] = array->items[a];
    }

    array->items[i] = el; // Insert the element at index i
    array->count++; // Increment the number of elements
}

/* Insert an element at the end of the array */
void InsertLast(BarangList *array, Barang el) {
    InsertAt(array, el, Length(*array)); // Insert at the end (i.e., current length)
}

/* Insert an element at the start of the array */
void InsertFirst(BarangList *array, Barang el) {
    InsertAt(array, el, 0); // Insert at the start (index 0)
}

/* Delete an element at a specific index */
void DeleteAt(BarangList *array, IdxType i) {
    for (int a = i; a < array->count - 1; a++) {
        array->items[a] = array->items[a + 1]; // Shift elements to the left
    }
    array->count--; // Decrease the number of elements
}

/* Delete the last element of the array */
void DeleteLast(BarangList *array) {
    DeleteAt(array, Length(*array) - 1); // Delete the last element
}

/* Delete the first element of the array */
void DeleteFirst(BarangList *array) {
    DeleteAt(array, 0); // Delete the first element
}

// Initialize a Barang with name and price
void initBarang(Barang *barang, Word *name, int price) {
    //barang->name = *name;  // Initialize the name field
    barang->price = price; // Initialize the price field
}

/* Print the array */
void PrintArrayDin(BarangList array) {
    if (IsEmpty(array)) {
        printf("[]\n"); // Print empty array
    } else {
        printf("[\n");
        for (int i = 0; i < array.count; i++) {
            printf("  {name: ");
                for (int j = 0; j < toKata(array.items[i].name).Length; j++) {
                    printf("%c", toKata(array.items[i].name).TabWord[j]); // Correct usage
                }
            printf(", money: %d}", array.items[i].price); // Print barang's money
            if (i < array.count - 1) {
                printf(",\n"); // Print comma between items
            }
        }
        printf("\n]\n");
    }
}

/* Reverse the array */
void ReverseArrayDin(BarangList *array) {
    int length = Length(*array);
    for (int i = 0; i < length / 2; i++) {
        Barang temp = array->items[i];
        array->items[i] = array->items[length - i - 1];
        array->items[length - i - 1] = temp;
    }
}

/* Copy the array */
BarangList CopyArrayDin(BarangList array) {
    BarangList copy = MakeArrayDin(); // Create a new array
    for (int i = 0; i < array.count; i++) {
        InsertLast(&copy, array.items[i]); // Insert each element into the copied array
    }
    return copy;
}

/* Search for a barang by name */
IdxType SearchArrayDin(BarangList array, Word name) {
    for (int i = 0; i < array.count; i++) {

        if (isWordEqualToString(&name, array.items[i].name)) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

boolean isMemberList(BarangList array, Word name)
/* mengembalikan true jika name terdapat pada BarangList array */
{
    int i;
    for(i = 0; i < Length(array); i++)
    {
        if(isWordEqualToString(&name, array.items[i].name))
        {
            return true;
        }
    }
    return false;
}

int countString (char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
