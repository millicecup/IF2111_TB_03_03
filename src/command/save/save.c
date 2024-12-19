#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/User_Barang/user.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "save.h"
boolean issave = false;

// Function to save BarangList and UserList to a file
void SaveToFile(const char *filename, const BarangList *barangArray, const UserList *userArray) {
    const char *parent_dir = "../../root";
    char path[255];
    snprintf(path, sizeof(path), "%s/%s", parent_dir, filename);
    
    FILE *file = fopen(path, "w"); // Overwrite mode
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    // Save BarangList
    if (barangArray != NULL) {
        fprintf(file, "%d\n", barangArray->count); // Number of items
        for (int i = 0; i < barangArray->count; i++) {
            fprintf(file, "%d %s\n", barangArray->items[i].price, barangArray->items[i].name);
        }
    }

    // Save UserList
    if (userArray != NULL) {
        fprintf(file, "%d\n", userArray->count); // Number of users
        for (int i = 0; i < userArray->count; i++) {
            const User *user = &userArray->users[i];
            fprintf(file, "%d %s %s\n", user->money, user->name, user->password);

            // Save transaction history
            const History *history = &user->riwayat_pembelian;
            fprintf(file, "%d\n", history->TOP + 1); // Number of transactions
            for (int j = 0; j <= history->TOP; j++) {
                fprintf(file, "%d %s\n",
                        history->price[j],
                        history->item[j]);
            }

            // Save wishlist
            int wishlistCount = NbWishlist(user->wishlist);
            fprintf(file, "%d\n", wishlistCount); // Number of wishlist items
            address current = First(user->wishlist);
            while (current != NULL) {
                fprintf(file, "%s\n", Info(current).name);
                current = Next(current);
            }
        }
    }

    fclose(file);
    printf("Data successfully saved to %s\n", path);
}
