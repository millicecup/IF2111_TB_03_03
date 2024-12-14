#include <stdio.h>
#include "user.h"
#include "../Mesin_Kata/mesinkata.h"

// Implementasi fungsi User
void CreateUserList(UserList *list) {
    list->count = 0;
}

int IsUserListFull(UserList *list) {
    return list->count == MAX_USERS;
}

int IsUserListEmpty(UserList *list) {
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
void AddUser(UserList *list, char *name, char *password, int money) {
    if (!IsUserListFull(list)) {
        // Salin nama pengguna secara manual
        ManualStringCopy(list->users[list->count].name, name);

        // Salin password secara manual
        ManualStringCopy(list->users[list->count].password, password);

        // Simpan jumlah uang
        list->users[list->count].money = money;

        // Perbarui jumlah pengguna
        list->count++;
    } else {
        printf("Daftar pengguna penuh!\n");
    }
}

// Cetak daftar pengguna
void PrintUsers(UserList *userList) {
    for (int i = 0; i < userList->count; i++) {
        User *user = &userList->users[i]; 
        printf("User %d: Nama: %s, Password: %s, Uang: %d\n", i + 1, user->name, user->password, user->money);

        // show riwayat pembelian
        printf("  Riwayat Pembelian:\n");
        if (!IsEmptyStack(user->riwayat_pembelian)) {
            DisplayStack(user->riwayat_pembelian);
        } else {
            printf("    (No transactions)\n");
        }

        // show wishlist
        printf("  Wishlist:\n");
        if (!IsEmptyWishlist(user->wishlist)) {
            PrintList(user->wishlist);
            printf("\n");
        } else {
            printf("    (No wishlist items)\n");
        }
    }
}



void InsertLastUser(UserList *array, User el) {
    if (array->count < MAX_USERS) {
        array->users[array->count] = el;
        array->count++;
        
    }
}

void addUser(UserList *userArray, User *newUser) {
    InsertLastUser(userArray, *newUser);  // Insert new user to array
                  // Save updated users list
}


void ModifyUserMoney(UserList *list, char *name, int newMoney) {
    for (int i = 0; i < list->count; i++) {
        if (isEqualString(list->users[i].name, name) == 0) { // Check if the user exists
            list->users[i].money = newMoney; // Update the money field
            printf("Uang pengguna %s berhasil diperbarui menjadi %d.\n", name, newMoney);
            return;
        }
    }
    printf("Pengguna dengan nama '%s' tidak ditemukan.\n", name);
}