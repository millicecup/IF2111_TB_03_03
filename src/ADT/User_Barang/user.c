#include <stdio.h>

#include "user.h"
#include "../Mesin_Kata/mesinkata.h"

// Implementasi fungsi User
void CreateUserList(UserList *list) {
    list->count = 0;
    list->currentUserIndex = -1;  // Initialize with no active user
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
    while (src[i] != '\0' && i < MAX_LEN - 1) {  // Prevent overflow
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // Tambahkan null terminator
}

// Tambahkan pengguna ke daftar
int AddUser(UserList *list, char *name, char *password, int money) {
    if (IsUserListFull(list)) {
        printf("Daftar pengguna penuh!\n");
        return 0;  // Failure
    }
    ManualStringCopy(list->users[list->count].name, name);
    ManualStringCopy(list->users[list->count].password, password);
    list->users[list->count].money = money;

    // Initialize user-specific structures
    CreateEmptyStack(&list->users[list->count].riwayat_pembelian);
    CreateEmptyWishlist(&list->users[list->count].wishlist);

    list->count++;
    return 1;  // Success
}

// Cetak daftar pengguna dengan detail
void PrintUsersDetailed(UserList *userList) {
    for (int i = 0; i < userList->count; i++) {
        User *user = &userList->users[i];
        printf("User %d: Nama: %s, Password: %s, Uang: %d\n", i + 1, user->name, user->password, user->money);

        // Show riwayat pembelian
        printf("  Riwayat Pembelian:\n");
        if (!IsEmptyStack(user->riwayat_pembelian)) {
            DisplayStack(user->riwayat_pembelian);
        } else {
            printf("    (No transactions)\n");
        }

        // Show wishlist
        printf("  Wishlist:\n");
        if (!IsEmptyWishlist(user->wishlist)) {
            PrintList(user->wishlist);
            printf("\n");
        } else {
            printf("    (No wishlist items)\n");
        }
    }
}

// Cetak daftar pengguna (ringkas)
void PrintUsers(UserList *list) {
    for (int i = 0; i < list->count; i++) {
        printf("User %d: Nama: %s, Password: %s, Uang: %d\n", 
               i + 1, 
               list->users[i].name, 
               list->users[i].password, 
               list->users[i].money);
    }
}

// Tambahkan pengguna di akhir daftar
void InsertLastUser(UserList *array, User el) {
    if (array->count < MAX_USERS) {
        array->users[array->count] = el;
        array->count++;
    }
}

// Fungsi tambahan pengguna
void addUser(UserList *userArray, User *newUser) {
    InsertLastUser(userArray, *newUser);  // Insert new user to array
}

// Periksa apakah pengguna ada
int UserExists(UserList *list, char *name) {
    for (int i = 0; i < list->count; i++) {
        if (compareStringsManual(list->users[i].name, name) == 0) {
            return 1;  // User exists
        }
    }
    return 0;  // User not found
}

// Hapus pengguna dari daftar
int RemoveUser(UserList *list, char *name) {
    for (int i = 0; i < list->count; i++) {
        if (compareStringsManual(list->users[i].name, name) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                list->users[j] = list->users[j + 1];
            }
            list->count--;
            return 1;  // Success
        }
    }
    return 0;  // User not found
}

// Ubah uang pengguna
void ModifyUserMoney(UserList *list, char *name, int newMoney) {
    for (int i = 0; i < list->count; i++) {
        if (compareStringsManual(list->users[i].name, name) == 0) { // Check if the user exists
            list->users[i].money = newMoney; // Update the money field
            printf("Uang pengguna %s berhasil diperbarui menjadi %d.\n", name, newMoney);
            return;
        }
    }
    printf("Pengguna dengan nama '%s' tidak ditemukan.\n", name);
}
