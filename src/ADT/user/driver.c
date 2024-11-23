// Implementasi fungsi User
void CreateUserList(ArrayUser *list) {
    list->count = 0;
}

int IsUserListFull(ArrayUser *list) {
    return list->count == MAX_USERS;
}

int IsUserListEmpty(ArrayUser *list) {
    return list->count == 0;
}

// Fungsi untuk menyalin string secara manual
void ManualStringCopy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Tambahkan null terminator
}

// Tambahkan pengguna ke daftar
void AddUser(ArrayUser *list, char *name, char *password, int money) {
    if (!IsUserListFull(list)) {
        // Salin nama pengguna secara manual
        ManualStringCopy(list->A[list->count].name, name);

        // Salin password secara manual
        ManualStringCopy(list->A[list->count].password, password);

        // Simpan jumlah uang
        list->A[list->count].money = money;

        // Perbarui jumlah pengguna
        list->count++;
    } else {
        printf("Daftar pengguna penuh!\n");
    }
}

// Cetak daftar pengguna
void PrintUsers(ArrayUser *list) {
    for (int i = 0; i < list->count; i++) {
        printf("User %d: Nama: %s, Password: %s, Uang: %d\n", 
               i + 1, 
               list->A[i].name, 
               list->A[i].password, 
               list->A[i].money);
    }
}
