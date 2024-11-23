#include <stdio.h>
#include <stdlib.h>
#include "barang.h"
#include "../Mesin_Kata/mesinkata.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk Arraybarang kosong dengan ukuran InitialSize
 */
Arraybarang MakeArrayDin() {
    Arraybarang array;
    array.A = (Barang *)malloc(InitialSize * sizeof(Barang)); // Allocate memory for barang array
    array.Capacity = InitialSize; // Set initial capacity
    array.Neff = 0; // Initial number of items is 0
    return array;
}

/* Deallocates the dynamic array memory */
void DeallocateArrayDin(Arraybarang *array) {
    free(array->A); // Free the allocated memory for barang array
}

/* Check if the array is empty */
boolean IsEmpty(Arraybarang array) {
    return array.Neff == 0;
}

/* Get the number of elements in the array */
int Length(Arraybarang array) {
    return array.Neff;
}

/* Get the element at index i */
Barang Get(Arraybarang array, IdxType i) {
    return array.A[i]; // Return the barang at index i
}

/* Get the capacity of the array */
int GetCapacity(Arraybarang array) {
    return array.Capacity;
}

/* Insert an element at a specific index */
void InsertAt(Arraybarang *array, Barang el, IdxType i) {
    int length = Length(*array); // Get the current number of elements
    int capacity = GetCapacity(*array); // Get current capacity

    // If the array is full, expand it
    if (length == capacity) {
        int desiredCapacity = capacity *2; // Increase capacity by InitialSize
        Barang *arr = (Barang *)malloc(desiredCapacity * sizeof(Barang)); // Allocate new array
        for (int a = 0; a < length; a++) {
            arr[a] = Get(*array, a); // Copy elements to the new array
        }
        free(array->A); // Free the old array
        array->A = arr; // Update the array pointer
        array->Capacity = desiredCapacity; // Update the capacity
    }

    // Shift elements to the right to make room for the new element
    for (int a = length - 1; a >= i; a--) {
        array->A[a + 1] = array->A[a];
    }

    array->A[i] = el; // Insert the element at index i
    array->Neff++; // Increment the number of elements
}

/* Insert an element at the end of the array */
void InsertLast(Arraybarang *array, Barang el) {
    InsertAt(array, el, Length(*array)); // Insert at the end (i.e., current length)
}

/* Insert an element at the start of the array */
void InsertFirst(Arraybarang *array, Barang el) {
    InsertAt(array, el, 0); // Insert at the start (index 0)
}

/* Delete an element at a specific index */
void DeleteAt(Arraybarang *array, IdxType i) {
    for (int a = i; a < array->Neff - 1; a++) {
        array->A[a] = array->A[a + 1]; // Shift elements to the left
    }
    array->Neff--; // Decrease the number of elements
}

/* Delete the last element of the array */
void DeleteLast(Arraybarang *array) {
    DeleteAt(array, Length(*array) - 1); // Delete the last element
}

/* Delete the first element of the array */
void DeleteFirst(Arraybarang *array) {
    DeleteAt(array, 0); // Delete the first element
}

// Initialize a Barang with name and price
void initBarang(Barang *barang, Word *name, int price) {
    CopyWord(&barang->name, name); // Copy the name
    barang->price = price; // Initialize the price field
}


/* Print the array */


/* Reverse the array */
void ReverseArrayDin(Arraybarang *array) {
    int length = Length(*array);
    for (int i = 0; i < length / 2; i++) {
        Barang temp = array->A[i];
        array->A[i] = array->A[length - i - 1];
        array->A[length - i - 1] = temp;
    }
}

/* Copy the array */
Arraybarang CopyArrayDin(Arraybarang array) {
    Arraybarang copy = MakeArrayDin(); // Create a new array
    for (int i = 0; i < array.Neff; i++) {
        InsertLast(&copy, array.A[i]); // Insert each element into the copied array
    }
    return copy;
}

/* Search for a barang by name */
IdxType SearchArrayDin(Arraybarang array, Word name) {
    for (int i = 0; i < array.Neff; i++) {
        if (IsWordEq(&array.A[i].name, &name)) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

void ClearArrayDin(Arraybarang *array) {
    array->Neff = 0; // Reset the number of elements
}