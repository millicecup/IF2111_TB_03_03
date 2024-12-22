#include <stdio.h>
#include "profile.h"
#include "../../ADT/User_Barang/user.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
// #include ".."

void profile(UserList *userList){
    User *user = &userList->users[userList->currentUserIndex];

    // printf("Nama: %s\n", user->name);
    // printf("Password: %s\n", user->password);
    // printf("Uang: %d\n", user->money);
    // printf("\nketik back untuk kembali ke menu\n"); 
    printf("|=============================================================================================================|\n");
    printf("|                                                                                                             |\n");
    printf("|                                                                                                             |\n");
    animasiProfile();
    printf("|                                                                                                             |\n");
    printf("|                                                                                                             |\n");
    printf("|=============================================================================================================|\n");
    printf("|                                                                                                             |\n");
    printf("|                                                                                      Halo, %-16s |\n", user->name);
    printf("|                                                                                                             |\n");
    printf("|-------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                                                             |\n");
    printf("|                                                                                                             |\n");
    printf("|     Nama      : %-92s|\n", user->name);
    printf("|     Password  : %-92s|\n", user->password);
    printf("|     Uang      : %-92d|\n", user->money);
    printf("|                                                                                                             |\n");
    printf("|                                                                                                             |\n");
    printf("|=============================================================================================================|\n");
    printf("| Ketik 'back' untuk kembali ke menu utama                                                                    |\n");
    printf("|=============================================================================================================|\n");

}

    // Show riwayat pembelian
//     printf("Riwayat Pembelian:\n");
//     if (!IsEmptyStack(user->riwayat_pembelian)) {
//         DisplayStack(user->riwayat_pembelian);
//     } else {
//         printf("    (No transactions)\n");
//     }

//     // Show wishlist
//     printf("Wishlist:\n");
//     if (!IsEmptyWishlist(user->wishlist)) {
//         PrintList(user->wishlist);
//         printf("\n");
//     } else {
//         printf("    (No wishlist items)\n");
//     }