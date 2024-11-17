#include <stdio.h>
#include "barang.h"
#include "../Mesin_Kata/mesinkata.h"

int main() {
    Barang barang1;
    Word name;
    char input[MAX_LEN];

    // Initialize the barang array (dynamic array)
    Arraybarang barangArray = MakeArrayDin();

    // Get name input for Barang
    printf("Enter Barang name: ");
    readLine(input, MAX_LEN);
    toWord(&name, input);

    // Get money input for Barang
    printf("Enter Barang price (money): ");
    int money;
    scanf("%d", &money);

    // Initialize Barang item
    initBarang(&barang1, &name, money);

    // Check if Barang already exists in the array (search by name)
    if (SearchArrayDin(barangArray, name) != -1) {
        printf("Barang already exists.\n");
    } else {
        // Add the new Barang to the array
        InsertLast(&barangArray, barang1);

        // Print the updated array of Barang
        printf("\nBarang successfully added!\n");
        PrintArrayDin(barangArray);
    }

    // Free the allocated memory for the dynamic array
    DeallocateArrayDin(&barangArray);

    return 0;
}

/*
gcc -IADT Mesin_Kata/mesinkata.c Mesin_Kata/mesinkarakterv2.c barang/barang.c barang/barang_driver.c -o barang
*/