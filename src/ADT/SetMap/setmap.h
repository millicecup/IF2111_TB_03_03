#ifndef _SETMAP_H_
#define _SETMAP_H_

#include <stdio.h>
#include "../boolean.h"
#include "../Mesin_Kata/mesinkata.h"
#include "../User_Barang/barang.h"

#define Nil 0
#define MaxBasket 30
#define undefined -999

typedef struct
{
    Barang item[MaxBasket];
    int quantity[MaxBasket];
    int count;
} Keranjang;


void CreateEmptyBasket(Keranjang *k);
/* membuat Keranjang k kosong dengan kapasitas MaxBasket */
/* semua elemen nama berupa mark dan harga 0 */

boolean IsEmptyBasket(Keranjang k);
/* mengembalikan true jika Keranjang k kosong */

boolean IsFullBasket(Keranjang k);
/* mengembalikan true jika Keranjang k penuh */

int TotalBasket(Keranjang k);
/* mengembalikan jumlah Keranjang K */

int indeksBasket(Keranjang k, char *Elmt);
/* Mengembalikan atau mengirimkan indeks nilai item yang ada dalam Keranjang k*/

boolean IsMemberBasket(Keranjang k, char *Elmt);
/* mengembalikan true jika Elmt terdapat pada Keranjang k */

void AddBasket(Keranjang *k, Barang item, int qty);
/* menambah item ke dalam Keranjang s */

void DelBasket(Keranjang *k, Barang item, int qty);
/* menghapus item dari Keranjang k */

void DisplayBasket(Keranjang k);
/* menampilkan nama dan kuantitas barang yang terdapat pada SetOfBarang s */

#endif
