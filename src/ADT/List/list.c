#include <stdio.h>
#include "list.h"

// Konstruktor

List MakeList() {
	List L;
	IdxType i;
	for (i = 0; i < MaxEl; i++) {
		L.A[i] = Mark;
	}
	return L;
}

boolean IsEmptyList(List L) {
	return (L.A[0] == Mark);
}

int LengthList(List L) {
	int i = 0;
	while (L.A[i] != Mark) {
		i += 1;
	}
	return i;
}

ElType GetList(List L, IdxType i) {
	return L.A[i];
}

void SetList(List *L, IdxType i, ElType v) {
	(*L).A[i] = v;
}

IdxType FirstIdxL(List L) {
    return 0;
}

IdxType LastIdxL(List L) {
	int i = FirstIdxL(L);
	while ((i < MaxEl) && (L.A[i+1] != Mark)) {
		i += 1;
	}
	return i;
}

boolean IsIdxValidL (List L, IdxType i) {
	return (0 <= i) && (MaxEl >= i);
}

boolean IsIdxEffL (List L, IdxType i) {
	return (FirstIdxL(L) <= i) && (LastIdxL(L) >= i);
}

boolean SearchL(List L, ElType X) {
	int i = FirstIdxL(L);
	int j = LastIdxL(L);
	boolean found = false;
	while ((i <= j) && !found) {
		i += 1;
		if (L.A[i] == X) {
			found = true;
		}
	}
    return found;
}

void InsertFirstL(List *L, ElType X) {
	IdxType i = LastIdxL(*L);
	IdxType j = FirstIdxL(*L);
	while (i > j) {
		SetList(L, i+1, GetList(*L, i));
		i--;
	}
	SetList(L, j, X);
}

void InsertAtL(List *L, ElType X, IdxType i) {
    IdxType j = LastIdxL(*L);
	while (i <= j) {
		SetList(L, j+1, GetList(*L, j));
        j--;
	}
	SetList(L, i, X);
}

void InsertLastL(List *L, ElType X) {
    if (IsEmptyList(*L)) {
        InsertFirstL(L, X);
    } else {
        (*L).A[LastIdxL(*L) + 1] = X;
    }
}

void DeleteFirstL(List *L) {
	int i = FirstIdxL(*L);
	while (i < LastIdxL(*L)) {
		(*L).A[i] = (*L).A[i+1];
        i++;
	}
    (*L).A[i] = Mark;
}

void DeleteAtL(List *L, IdxType i) {
	int j = LastIdxL(*L);
	// while (i <= j) {
	// 	(*L).A[j] = (*L).A[j+1];
    //     j--;
	// }
	while (i <= j) {
		(*L).A[i] = (*L).A[i+1];
        i++;
	}
}

void DeleteLastL(List *L) {
	(*L).A[LastIdxL(*L)] = Mark;
}

List ConcatL(List L1, List L2) {
	List L3 = MakeList();
	int i = FirstIdxL(L1);
	int j = FirstIdxL(L2);
	int idx = 0;
	while (i <= LastIdxL(L1)) {
		L3.A[idx] = L1.A[i];
        idx++;
        i++;
	}
	while (j <= LastIdxL(L2)) {
		L3.A[idx] = L2.A[j];
        idx++;
        j++;
	}

    return L3;
}

void CreateList(List *l, int size) {
    l->size = size;
}