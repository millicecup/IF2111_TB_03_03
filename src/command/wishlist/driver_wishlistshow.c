#include <stdio.h>
#include <stdlib.h>
#include "wishlistShow.h"

int main() {
    Wishlist L, l1;
    CreateEmptyWishlist(&L);
    CreateEmptyWishlist(&l1);  // Membuat Wishlist kosong

    // Misalnya kamu ingin menambahkan beberapa barang ke wishlist
    infoBarang barang1 = {"Laptop", 10000.0};
    infoBarang barang2 = {"Smartphone", 5000.0};
    infoBarang barang3 = {"Smartphone", 5000.0};
    address p1 = Alokasi(barang1);
    address p2 = Alokasi(barang2);
    address p3 = Alokasi(barang3);

    First(L) = p1; 
    Next(p1) = p2;  
    Next(p2) = p3;

    // Mencetak seluruh isi wishlist
    WishlistShow(L);

    // Mencetak isi wishlist kosong
    WishlistShow(l1);

    return 0;
}

// gcc wishlistshow.c ../../ADT/LinkedList/linkedlist.c ../../ADT/User_Barang/barang.c ../../ADT/Mesin_Kata/mesinkata.c ../../ADT/Mesin_Karakter/mesinkarakter.c ../../ADT/Mesin_Baris/mesinbaris.c -o program