#include <stdio.h>
#include <stdlib.h>
#include "wishlistAdd.h"

int main() {
    // Inisialisasi wishlist dan menu
    Wishlist wishlist;
    CreateEmptyWishlist(&wishlist);
    BarangList menu = MakeArrayDin(); 

    // Isi menu dengan beberapa barang
    Barang barang1, barang2, barang3;
    assignString(barang1.name, "Ayam Geprek Bakar Crispy Besthal");
    barang1.price = 25000;
    assignString(barang2.name, "Mie Goreng");
    barang2.price = 15000;
    assignString(barang3.name, "Es Teh");
    barang3.price = 5000;

    // Tambahkan barang ke wishlist
    InsVLast(&wishlist, barang1);
    InsVLast(&wishlist, barang2);
    InsVLast(&wishlist, barang3);

    // Tambahkan barang ke menu
    InsertLast(&menu, barang1);
    InsertLast(&menu, barang2);
    InsertLast(&menu, barang3);

    // Test case 1: Menambah barang yang ada di menu
    printf("Test Case 1:\n");
    WishlistAdd(&wishlist, &menu);  // Input: Ayam Geprek Bakar Crispy Besthal

    // Test case 2: Menambah barang yang sudah ada di wishlist
    printf("\nTest Case 2:\n");
    WishlistAdd(&wishlist, &menu);  // Input: Ayam Geprek Bakar Crispy Besthal

    // Test case 3: Menambah barang yang tidak ada di menu
    printf("\nTest Case 3:\n");
    WishlistAdd(&wishlist, &menu);  // Input: Ayam Geprek Sambalado Besthal

    return 0;
}

// gcc wishlistadd.c ../../ADT/LinkedList/linkedlist.c ../../ADT/User_Barang/barang.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Karakter/mesinkarakter.c ../../ADT/Mesin_Baris/mesinbaris.c -o program