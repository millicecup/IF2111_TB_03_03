#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/User_Barang/user.h"
#include "../../ADT/User_Barang/barang.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"


// Function to save BarangList and UserList to a file
void SaveToFile(const char *fileName, BarangList *barangList, UserList *userList) {
    const char *parent_dir = "../../save";
    
    char path[255];
    snprintf(path, sizeof(path), "%s/%s.txt", parent_dir, fileName);
    
    FILE *file = fopen(path, "a");

    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    if (barangList != NULL) {
        // Write the number of items in BarangList
        fprintf(file, "%d\n", barangList->count);
        // Write each item in BarangList
        for (int i = 0; i < barangList->count; i++) {
            fprintf(file, "%d %s\n", barangList->items[i].price, barangList->items[i].name);
        }
    }

    if (userList != NULL) {
        // Write the number of users in UserList
        fprintf(file, "%d\n", userList->count);
        // Write each user in UserList
        for (int i = 0; i < userList->count; i++) {
            fprintf(file, "%d %s %s\n", userList->users[i].money, userList->users[i].name, userList->users[i].password);
        }
    }

    fclose(file);
    printf("Data successfully saved to %s\n", path);
}


