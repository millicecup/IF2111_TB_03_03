#ifndef LIST_H
#define LIST_H

#include "boolean.h"

#define MAX_SIZE 100

typedef char ElType;
typedef struct {
    ElType buffer[MAX_SIZE];
    int size;
} List;

void CreateList(List *l, int size);
void SetELMT(List *l, int idx, ElType val);
ElType ELMT(List l, int idx);

#endif
