#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/boolean.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/SetMap/setmap.h"
#include "cart_remove.h"

int main() 
{
    Keranjang k;
    CreateEmptyBasket(&k);

    Barang Apple = { "Apple", 1000 };
    Barang Banana = { "Banana", 1500 };
    Barang Orange = { "Orange", 5000 };

    AddBasket(&k, Apple, 10);  
    AddBasket(&k, Banana, 5);   
    AddBasket(&k, Orange, 3); 

    printf("Keranjang awal...\n");
    DisplayBasket(k);

    printf("\nMenghapus 10 Apple...\n");
    RemoveCart(&k, Apple.name, 10);
    printf("\nKeranjang setelah CART REMOVE:\n");
    DisplayBasket(k);

    printf("\nMenghapus 2 Banana...\n");
    RemoveCart(&k, Banana.name, 2);  
    printf("\nKeranjang setelah CART REMOVE:\n");
    DisplayBasket(k);

    printf("\nMenghapus 15 Orange...\n");
    RemoveCart(&k, Orange.name, 15); 
    printf("\nKeranjang setelah CART REMOVE:\n");
    DisplayBasket(k);

    return 0;
}