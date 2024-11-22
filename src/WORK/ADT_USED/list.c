#include <stdio.h>
#include "list.h"

// Deklarasi Fungsi dan Prosedur
void CreateList(List *L) {
    Size(*L) = 0;
}

boolean isEmpty(List L) {
    return Size(L) == 0;
}

boolean isFull(List L) {
    return Size(L) == MAX_CAPACITY;
}

void insertFirst(List *L, ElType val) {
    if (!isFull(*L)) {
        for (int i = Size(*L); i > 0; i--) {
            Elements(*L)[i] = Elements(*L)[i - 1];
        }
        Elements(*L)[0] = val;
        Size(*L)++;
    }
}

void insertLast(List *L, ElType val) {
    if (!isFull(*L)) {
        Elements(*L)[Size(*L)] = val;
        Size(*L)++;
    }
}

void insertAt(List *L, ElType val, int index) {
    if (!isFull(*L) && index >= 0 && index <= Size(*L)) {
        for (int i = Size(*L); i > index; i--) {
            Elements(*L)[i] = Elements(*L)[i - 1];
        }
        Elements(*L)[index] = val;
        Size(*L)++;
    }
}

void deleteFirst(List *L) {
    if (!isEmpty(*L)) {
        for (int i = 0; i < Size(*L) - 1; i++) {
            Elements(*L)[i] = Elements(*L)[i + 1];
        }
        Size(*L)--;
    }
}

void deleteLast(List *L) {
    if (!isEmpty(*L)) {
        Size(*L)--;
    }
}

void deleteAt(List *L, int index) {
    if (!isEmpty(*L) && index >= 0 && index < Size(*L)) {
        for (int i = index; i < Size(*L) - 1; i++) {
            Elements(*L)[i] = Elements(*L)[i + 1];
        }
        Size(*L)--;
    }
}

ElType getFirst(List L) {
    return getElmt(L, 0);
}

ElType getLast(List L) {
    return getElmt(L, Size(L) - 1);
}

ElType getElmt(List L, int index) {
    return Elements(L)[index];
}

int indexOf(List L, ElType val) {
    for (int i = 0; i < Size(L); i++) {
        if (Elements(L)[i] == val) {
            return i;
        }
    }
    return -1; 
}

void displayList(List L) {
    if (isEmpty(L)) {
        printf("[]\n");
    } else {
        printf("[");
        for (int i = 0; i < Size(L); i++) {
            printf("%d", Elements(L)[i]);
            if (i < Size(L) - 1) {
                printf(",");
            }
        }
        printf("]\n");
    }
}
