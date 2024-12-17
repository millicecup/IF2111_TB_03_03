#include <stdio.h>
#include "stack.h"

int main() {
    History S;
    CreateEmptyStack(&S);

    printf("Adding items to the stack...\n");

    char itemA[] = "Apple";
    char itemB[] = "Banana";
    char itemC[] = "Cherry";
    char itemD[] = "Donut";

    PushStack(&S, itemA, 50, 2);
    PushStack(&S, itemB, 30, 5);
    PushStack(&S, itemC, 50, 3);
    PushStack(&S, itemD, 60, 1);

    printf("\nStack:\n");
    DisplayStack(S);

    return 0;
}

/*
gcc -o driverstack driver_stack.c stack.c ../Mesin_Kata/mesinkata.c ../Mesin_Karakter/mesinkarakter.c ../Mesin_Baris/mesinbaris.c
*/
