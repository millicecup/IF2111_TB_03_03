#include <stdio.h>
#include "../../ADT/Stack/stack.h"
#include "history.h"

void main() 
{
    History H;
    CreateEmptyStack(&H);

    PushStack(&H, "Apple", 10000, 1); 
    PushStack(&H, "Banana", 200, 2);  
    PushStack(&H, "Orange", 50, 3);
    PushStack(&H, "Purry", 8000, 1);
    PushStack(&H, "Phineas's socks", 150, 4); 
    PushStack(&H, "ayam", 2500, 1); 
    // PushStack(&H, "Apple", 100, 2);  
    // PushStack(&H, "Orange", 20, 10); 

    DisplayHistory(H, 3);
}


/* 
gcc -o historydriver historydriver.c history.c ../../ADT/Stack/stack.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Karakter/mesinkarakter.c ../../ADT/Mesin_Baris/mesinbaris.c
*/