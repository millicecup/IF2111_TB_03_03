#include <stdio.h>
#include "../boolean.h"
#include "../Mesin_Kata/mesinkata.h"
#include "../User_Barang/barang.h"
#include "setmap.h"

void CreateEmptyBasket(Keranjang *k)
/* membuat Keranjang k kosong dengan kapasitas MaxBasket */
/* semua elemen nama berupa mark dan harga 0 */
{
    (*k).count = Nils;
}

boolean IsEmptyBasket(Keranjang k)
/* mengembalikan true jika Keranjang k kosong */
{
    return k.count == Nils;
}

boolean IsFullBasket(Keranjang k)
/* mengembalikan true jika Keranjang k penuh */
{
    return k.count == MaxBasket;
}

int TotalBasket(Keranjang k)
/* mengembalikan jumlah Keranjang K */
{
    return k.count;
}

int indeksBasket(Keranjang k, char *Elmt)
/* Mengembalikan atau mengirimkan indeks nilai item yang ada dalam Keranjang k*/
{
    int idx = 0;
    for (int i = 0; i < MaxBasket; i++)
    {
        if (isEqualString(Elmt, k.item[i].name))
        {
            return idx;
        }
        idx++;
    }
    return undefined;
}

boolean IsMemberBasket(Keranjang k, char *Elmt)
/* mengembalikan true jika Elmt terdapat pada Keranjang k */
{
    for (int i = 0; i < TotalBasket(k); i++)
    {
        if (isEqualString(Elmt, k.item[i].name))
        {
            return true;
        }
    }
    return false;
}

void AddBasket(Keranjang *k, Barang item, int qty)
/* menambah item ke dalam Keranjang s */
{
    for (int i = 0; i < TotalBasket(*k); i++) 
    {
        if (isEqualString((*k).item[i].name, item.name)) 
        {
            (*k).quantity[i] += qty;
            return;
        }
    }

    if (!IsFullBasket(*k)) 
    {
        (*k).item[(*k).count] = item;
        (*k).quantity[(*k).count] = qty;
        (*k).count++;
    } 
}


void DelBasket(Keranjang *k, Barang item, int qty)
/* menghapus item dari Keranjang k */
{
    for (int i = 0; i < TotalBasket(*k); i++) 
    {
        if (isEqualString((*k).item[i].name, item.name)) 
        {
            if ((*k).quantity[i] > qty) 
            {
                (*k).quantity[i] -= qty;
            } 
            else 
            {
                for (int j = i; j < TotalBasket(*k) - 1; j++) 
                {
                    (*k).item[j] = (*k).item[j + 1];
                    (*k).quantity[j] = (*k).quantity[j + 1];
                }
                (*k).count--; 
            }
            return;
        }
    }
}

void DisplayBasket(Keranjang k)
/* menampilkan nama dan kuantitas barang yang terdapat pada Keranjang k */
{
    if (IsEmptyBasket(k))
    {
        printf("Keranjang kosong.\n");
    }
    else
    {
        // printf("====================================================\n");
        printf("+--------------------------------------------------+\n");
        printf("|Kuantitas   | Nama                    | Total     |\n");
        printf("+--------------------------------------------------+\n");
        // printf("====================================================\n");
        for(int i = 0; i < TotalBasket(k); i++)
        {
            printf("|%-12d| %-24s| %-10d|\n", k.quantity[i], k.item[i].name, (k.quantity[i] * k.item[i].price));
        }
        printf("+--------------------------------------------------+\n");
        // printf("====================================================\n");
    }
}
