#ifndef CARTPAY_H
#define CARTPAY_H

#include "user.h"          // Menggunakan ADT User
#include "mesinkata.h"     // Mesin kata untuk input Ya/Tidak
#include "cartshow.h"      // Untuk menampilkan isi keranjang

// Fungsi utama untuk melakukan pembayaran
void cartPay(User *currentUser);

#endif