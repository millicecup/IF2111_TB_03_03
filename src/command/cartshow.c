#include <stdio.h>
#include "SetMap.h" 

/**
 * Fungsi untuk menampilkan isi keranjang.
 * Menampilkan nama barang, kuantitas, harga per barang, dan total harga.
 */
void CartShow(Basket *basket) {
    if (IsBasketEmpty(*basket)) {
        printf("Keranjang kosong.\n");
        return;
    }

    printf("%-20s %-10s %-10s %-10s\n", "Nama Barang", "Kuantitas", "Harga", "Total");
    printf("====================================================\n");

    int totalKeseluruhan = 0; // total harga semua barang

    // Iterasi melalui semua barang dalam keranjang
    for (int i = 0; i < basket->count; i++) {
        char *namaBarang = basket->items[i].name;
        int kuantitas = basket->items[i].quantity;
        int harga = basket->items[i].price;
        int totalHarga = kuantitas * harga;

        // Menampilkan informasi barang
        printf("%-20s %-10d %-10d %-10d\n", namaBarang, kuantitas, harga, totalHarga);

        // Menambahkan total harga barang ini ke total keseluruhan
        totalKeseluruhan += totalHarga;
    }

    printf("====================================================\n");
    printf("Total keseluruhan: %d\n", totalKeseluruhan);
}

// Contoh penggunaan fungsi CartShow
typedef struct {
    char name[50];
    int quantity;
    int price;
} Item;

typedef struct {
    Item items[100]; // Kapasitas maksimal 100 item
    int count;       // Jumlah item dalam keranjang
} Basket;

int main() {
    // Contoh keranjang belanja
    Basket keranjang = {
        .items = {
            {"Apel", 3, 5000},
            {"Jeruk", 2, 7000},
            {"Pisang", 5, 3000}
        },
        .count = 3
    };

    // Menampilkan isi keranjang
    CartShow(&keranjang);

    return 0;
}