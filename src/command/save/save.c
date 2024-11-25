#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/User_Barang/user.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "save.h"
boolean issave = false;

// Function to save BarangList and UserList to a file
void SaveToFile(const char *filename, const BarangList *barangArray, const UserList *userArray){
    const char *parent_dir = "../../root";
    
    char path[255];
    snprintf(path, sizeof(path), "%s/%s", parent_dir, filename);
    
    FILE *file = fopen(path, "a");

    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    if (barangArray != NULL) {
        // Write the number of items in BarangList
        fprintf(file, "%d\n", barangArray->count);
        // Write each item in BarangList
        for (int i = 0; i < barangArray->count; i++) {
            fprintf(file, "%d %s\n", barangArray->items[i].price, barangArray->items[i].name);
        }
    }

    if (userArray != NULL) {
        // Write the number of users in UserList
        fprintf(file, "%d\n", userArray->count);
        // Write each user in UserList
        for (int i = 0; i < userArray->count; i++) {
            fprintf(file, "%d %s %s\n", userArray->users[i].money, userArray->users[i].name, userArray->users[i].password);
        }
    }

    fclose(file);
    issave = true;
    printf("Data successfully saved to %s\n", path);
}


