#include <stdio.h>
#include "../../ADT/barang/barang.h"
#include "../../ADT/user/user.h"
#include "../../ADT/boolean.h"

// Save function to write the data to a file
boolean saveToFile(const char *filename, Arraybarang *barangArray, ArrayUser *userArray) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return false;
    }

    // Save barangArray
    if (barangArray != NULL) {
        fprintf(file, "%d\n", barangArray->Neff);
        for (int i = 0; i < barangArray->Neff; i++) {
            Barang currentBarang = barangArray->A[i];
            fprintf(file, "%d %s\n", currentBarang.price, currentBarang.name);
        }
    } else {
        fprintf(file, "0\n");
    }

    // Save userArray
    if (userArray != NULL) {
        fprintf(file, "%d\n", userArray->Neff);
        for (int i = 0; i < userArray->Neff; i++) {
            User currentUser = userArray->A[i];
            fprintf(file, "%d %s %s\n", currentUser.money, currentUser.name, currentUser.password);
        }
    }

    fclose(file);
    return true;
}
