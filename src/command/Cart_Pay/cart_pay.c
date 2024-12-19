#include <stdio.h>
#include <stdlib.h>

#include "cart_pay.h"

int calculateTotalBasketCost(Keranjang k) {
    int totalCost = 0;
    for (int i = 0; i < TotalBasket(k); i++) {
        totalCost += k.quantity[i] * k.item[i].price;
    }
    return totalCost;
}

void findHighestTotalItem(Keranjang k, char* maxName, int* maxPrice, int* maxQuantity) {
    int maxTotal = 0;
    *maxPrice = 0;
    *maxQuantity = 0;
    
    // Inisialisasi maxName dengan item pertama jika keranjang tidak kosong
    if (!IsEmptyBasket(k)) {
        assignString(maxName, k.item[0].name);
    }
    
    for (int i = 0; i < TotalBasket(k); i++) {
        int currentTotal = k.item[i].price * k.quantity[i];
        
        // Jika total lebih besar atau sama dengan total maksimum saat ini
        if (currentTotal > maxTotal || 
            (currentTotal == maxTotal && isGreaterString(k.item[i].name, maxName))) {
            maxTotal = currentTotal;
            assignString(maxName, k.item[i].name);
            *maxPrice = k.item[i].price;
            *maxQuantity = k.quantity[i];
        }
    }
}

void cartPay(Keranjang *k, int *userMoney, History *h) {
    if (IsEmptyBasket(*k)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }
    cartShow(*k);
    printf("Apakah jadi dibeli? (Ya/Tidak): ");
    
    ResetInput();
    GetInput();
    if (isWordEqualToString(&currentInput, "ya") || isWordEqualToString(&currentInput, "Ya")) {
        int totalCost = calculateTotalBasketCost(*k);
        if (*userMoney >= totalCost) {
            *userMoney -= totalCost;
            
            char maxName[Max_Length];
            int maxPrice, maxQuantity;
            findHighestTotalItem(*k, maxName, &maxPrice, &maxQuantity);
            
            // Menambahkan ke history menggunakan PushStack yang sudah ada
            PushStack(h, maxName, maxPrice, maxQuantity);
            
            printf("Selamat kamu telah membeli barang-barang tersebut!\n");
            CreateEmptyBasket(k);
        } else {
            printf("Uang kamu hanya %d, tidak cukup untuk membeli barang yang ada di keranjang!\n", *userMoney);
        }
    } else if (isWordEqualToString(&currentInput, "tidak") || isWordEqualToString(&currentInput, "Tidak")) {
        printf("Pembayaran dibatalkan.\n");
    } else {
        printf("Input tidak valid. Pembayaran dibatalkan.\n");
    }
}