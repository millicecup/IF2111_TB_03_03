#include "list.h"

void CreateList(List *l, int size) {
    l->size = size;
}

void SetELMT(List *l, int idx, ElType val) {
    l->buffer[idx] = val;
}

ElType ELMT(List l, int idx) {
    return l.buffer[idx];
}
