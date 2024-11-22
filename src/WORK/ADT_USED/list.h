#ifndef LIST_H
#define LIST_H

#include "boolean.h"

#define MAX_CAPACITY 100 // Kapasitas maksimum list

typedef int ElType; 

typedef struct {
    ElType elements[MAX_CAPACITY];
    int size;
} List;

// Selektor
#define Size(L) (L).size
#define Elements(L) (L).elements

// Deklarasi Fungsi dan Prosedur
void CreateList(List *L);
boolean isEmpty(List L);
boolean isFull(List L);
void insertFirst(List *L, ElType val);
void insertLast(List *L, ElType val);
void insertAt(List *L, ElType val, int index);
void deleteFirst(List *L);
void deleteLast(List *L);
void deleteAt(List *L, int index);
ElType getFirst(List L);
ElType getLast(List L);
ElType getElmt(List L, int index);
int indexOf(List L, ElType val);
void displayList(List L);

#endif
