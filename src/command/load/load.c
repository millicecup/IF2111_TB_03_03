#include "load.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Kata/utils.h"

void loadFromFile(FILE *file, Arraybarang *barangArray, ArrayUser *userArray) {
    ClearArrayDin(barangArray);
    ClearArrayUser(userArray);

    // Parse number of items
    fscanf(file, "%d", &barangArray->Neff);
    printf("Loading %d items...\n", barangArray->Neff);

    for (int i = 0; i < barangArray->Neff; i++) {
        fscanf(file, "%d %[^\n]", &barangArray->A[i].price, barangArray->A[i].name);
        printf("Loaded item: %s with price %d\n", barangArray->A[i].name, barangArray->A[i].price);
    }

    // Parse number of users
    fscanf(file, "%d", &userArray->Neff);
    printf("Loading %d users...\n", userArray->Neff);

    for (int i = 0; i < userArray->Neff; i++) {
        fscanf(file, "%d %s %s", &userArray->A[i].money, userArray->A[i].name, userArray->A[i].password);
        printf("Loaded user: %s with money %d\n", userArray->A[i].name, userArray->A[i].money);
    }
}
