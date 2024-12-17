#include <stdio.h>
#include "Store_List.h"
#include "../../ADT/User_Barang/barang.h"

int main() {
    BarangList store = MakeArrayDin();
    Barang item1, item2, item3, item4;

    assignString(item1.name, "Apple");
    item1.price = 15000;

    assignString(item2.name, "Banana");
    item2.price = 8000;

    assignString(item3.name, "Apple"); // Tes duplikat item
    item3.price = 15000;

    assignString(item4.name, "Orange");
    item4.price = 15000;


    InsertLast(&store, item1);
    InsertLast(&store, item2);
    InsertLast(&store, item3);
    InsertLast(&store, item4);

    DisplayStore(store);

    return 0;
}
