#include <stdio.h>
#include <stdlib.h>
#include "arrayuser.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin() {
    ArrayDin array;
    array.A = (User *)malloc(InitialSize * sizeof(User));
    array.Capacity = InitialSize;
    array.Neff = 0;
    return array;
}

/* Deallocates the dynamic array memory */
void DeallocateArrayDin(ArrayDin *array) {
    free(array->A);
}

/* Check if the array is empty */
boolean IsEmpty(ArrayDin array) {
    return array.Neff == 0;
}

/* Get the number of elements in the array */
int Length(ArrayDin array) {
    return array.Neff;
}

/* Get the element at index i */
User Get(ArrayDin array, IdxType i) {
    return array.A[i];
}

/* Get the capacity of the array */
int GetCapacity(ArrayDin array) {
    return array.Capacity;
}

/* Insert an element at a specific index */
void InsertAt(ArrayDin *array, User el, IdxType i) {
    int length = Length(*array);
    int capacity = GetCapacity(*array);

    if (length == capacity) {
        int desiredCapacity = capacity + InitialSize;
        User *arr = (User *)malloc(desiredCapacity * sizeof(User));
        for (int a = 0; a < length; a++) {
            arr[a] = Get(*array, a);
        }
        free(array->A);
        array->A = arr;
        array->Capacity = desiredCapacity;
    }

    for (int a = length - 1; a >= i; a--) {
        array->A[a + 1] = array->A[a];
    }

    array->A[i] = el;
    array->Neff++;
}

/* Insert an element at the end of the array */
void InsertLast(ArrayDin *array, User el) {
    InsertAt(array, el, Length(*array));
}

/* Insert an element at the start of the array */
void InsertFirst(ArrayDin *array, User el) {
    InsertAt(array, el, 0);
}

/* Delete an element at a specific index */
void DeleteAt(ArrayDin *array, IdxType i) {
    for (int a = i; a < array->Neff - 1; a++) {
        array->A[a] = array->A[a + 1];
    }
    array->Neff--;
}

/* Delete the last element of the array */
void DeleteLast(ArrayDin *array) {
    DeleteAt(array, Length(*array) - 1);
}

/* Delete the first element of the array */
void DeleteFirst(ArrayDin *array) {
    DeleteAt(array, 0);
}

/* Print the array */
void PrintArrayDin(ArrayDin array) {
    if (IsEmpty(array)) {
        printf("[]\n");
    } else {
        printf("[\n");
        for (int i = 0; i < array.Neff; i++) {
            printf("  {name: ");
            for (int j = 0; j < array.A[i].name.Length; j++) {
                printf("%c", array.A[i].name.TabWord[j]);
            }
            printf(", money: %d}", array.A[i].money);
            if (i < array.Neff - 1) {
                printf(",\n");
            }
        }
        printf("\n]\n");
    }
}

/* Reverse the array */
void ReverseArrayDin(ArrayDin *array) {
    int length = Length(*array);
    for (int i = 0; i < length / 2; i++) {
        User temp = array->A[i];
        array->A[i] = array->A[length - i - 1];
        array->A[length - i - 1] = temp;
    }
}

/* Copy the array */
ArrayDin CopyArrayDin(ArrayDin array) {
    ArrayDin copy = MakeArrayDin();
    for (int i = 0; i < array.Neff; i++) {
        InsertLast(&copy, array.A[i]);
    }
    return copy;
}

/* Search for a user by name */
IdxType SearchArrayDin(ArrayDin array, Word name) {
    for (int i = 0; i < array.Neff; i++) {
        if (isKataEqual(&array.A[i].name, &name)) {
            return i;
        }
    }
    return -1;
}
