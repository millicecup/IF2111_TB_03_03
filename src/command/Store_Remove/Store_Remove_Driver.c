#include <stdio.h>
#include <stdlib.h>

#include "../../ADT/boolean.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Baris/mesinbaris.h"
#include "../Store_List/Store_List.h"

#include "Store_Remove.h"
/*
gcc Store_Remove_Driver.c Store_Remove.c ../../ADT/User_Barang/barang.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Baris/mesinbaris.c ../Store_List/Store_List.c ../../ADT/Mesin_Karakter/mesinkarakter.c 
*/
int main() {
    BarangList store = MakeArrayDin();
    Barang itemToRemove;

    Barang gun;
    assignString(gun.name, "Sticky Web Gun");
    gun.price = 10;

    Barang neutralizer;
    assignString(neutralizer.name, "Inator Neutralizer");
    gun.price = 10;

    InsertLast(&store, gun);
    InsertLast(&store, neutralizer);
    DisplayStore(store);

    while (true) {
        printf("\n>> STORE REMOVE\n");
        removeItem(&store);

        printf("\nDaftar barang di toko:\n");
        DisplayStore(store);

        break; 
    }

    DeallocateArrayDin(&store);
    return 0;
}
