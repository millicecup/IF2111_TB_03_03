#include <stdio.h>
#include "mesinkar.h"

char CC;
boolean EOP;

void START() {
    CC = getchar();
    EOP = (CC == MARK);
}

void ADV() {
    CC = getchar();
    EOP = (CC == MARK);
}
