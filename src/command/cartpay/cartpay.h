#ifndef CARTPAY_H
#define CARTPAY_H

#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../ADT/User_Barang/barang.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/SetMap/setmap.h"
#include "../ADT/Stack/stack.h"
#include "../command/cartshow/cartshow.h"

/* Function Prototype */
int calculateTotalBasketCost(Keranjang k);

void findHighestTotalItem(Keranjang k, char* maxName, int* maxPrice, int* maxQuantity);

void cartPay(Keranjang *k, int *userMoney, History *h);

#endif