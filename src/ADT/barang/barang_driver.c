void CreateBarangList(Arraybarang *list, int capacity) {
    list->items = (Barang *)malloc(capacity * sizeof(Barang)); // Alokasi memori awal
    list->count = 0;                                           // Jumlah barang awal
    list->capacity = capacity;                                // Kapasitas awal
}

void AddBarang(Arraybarang *list, char *name, int price) {
    // Periksa apakah kapasitas penuh
    if (list->count == list->capacity) {
        list->capacity *= 2; // Gandakan kapasitas
        list->items = (Barang *)realloc(list->items, list->capacity * sizeof(Barang));
    }
    // Salin nama barang ke dalam array menggunakan manual string copy
    ManualStringCopy2(list->items[list->count].name, name);
    list->items[list->count].price = price; // Simpan harga barang
    list->count++; // Tambahkan jumlah barang
}

void PrintBarang(Arraybarang *list) {
    // Iterasi untuk mencetak semua barang
    for (int i = 0; i < list->count; i++) {
        printf("Barang %d: Nama: %s, Harga: %d\n", i + 1, list->items[i].name, list->items[i].price);
    }
}

void FreeBarangList(Arraybarang *list) {
    free(list->items); // Bebaskan memori yang dialokasikan
}
