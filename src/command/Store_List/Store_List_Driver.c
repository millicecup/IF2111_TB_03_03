#include <stdio.h>
#include <stdlib.h>

#include "../../ADT/boolean.h"
#include "../../ADT/List_Barang/listdin_barang.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "Store_List.h"

int main() {
    // Initialize the dynamic array of barang (items)
    Arraybarang storeItems = MakeArrayDin();

    // Add some items to the store
    Barang item1, item2, item3;
    
    // Define the first item
    item1.name.Length = 5;
    Word namaBarang1;
    stringToWord("Item1", &namaBarang1);
    item1.name = namaBarang1;

    // Define the second item
    item2.name.Length = 5;
    Word namaBarang2;
    stringToWord("Item2", &namaBarang2);
    item2.name = namaBarang2;

    // Define the third item
    item3.name.Length = 5;
    Word namaBarang3;
    stringToWord("Item3", &namaBarang3);
    item3.name = namaBarang3;

    // Insert the items into the array
    InsertLast(&storeItems, item1);
    InsertLast(&storeItems, item2);
    InsertLast(&storeItems, item3);

    // Display the store's inventory
    DisplayStore(storeItems);

    // Free the dynamic array
    DeallocateArrayDin(&storeItems);

    return 0;
}

/*
gcc Store_List_Driver.c ../../ADT/List_Barang/listdin_barang.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Karakter/mesinkarakter.c ../../ADT/Mesin_Baris/mesinbaris.c Store_List.c -o s
*/