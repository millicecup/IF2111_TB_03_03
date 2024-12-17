#include <stdio.h>
#include "setmap.h"

int main() 
{
    Keranjang keranjang;
    CreateEmptyBasket(&keranjang);

    Barang apple = {"Apple", 5000};
    Barang banana = {"Banana", 3000};
    Barang orange = {"Orange", 4000};

    printf(">>> Keranjang awal:\n");
    DisplayBasket(keranjang);

    printf("\n>>> Keranjang: \n");
    AddBasket(&keranjang, apple, 3); 
    AddBasket(&keranjang, banana, 2);
    AddBasket(&keranjang, orange, 5); 
    DisplayBasket(keranjang);

    printf("\nMenambah 2 apple...\n");
    printf(">>> Keranjang: \n");
    AddBasket(&keranjang, apple, 2); 
    DisplayBasket(keranjang);

    printf("\nMenghapus 1 banana...\n");
    printf(">>> Keranjang: \n");
    DelBasket(&keranjang, banana, 1); 
    DisplayBasket(keranjang);

    printf("\nMenghapus orange...\n");
    printf(">>> Keranjang: \n");
    DelBasket(&keranjang, orange, 5); 
    DisplayBasket(keranjang);

    printf("\nMenghapus orange lagi...\n");
    printf(">>> Keranjang: \n");
    DelBasket(&keranjang, orange, 1);
    DisplayBasket(keranjang);

    return 0;
}

/*
gcc -o setdriver setmap_driver.c setmap.c ../Mesin_Kata/mesinkata.c ../Mesin_Karakter/mesinkarakter.c ../Mesin_Baris/mesinbaris.c 
*/