#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/**** PROTOTYPE ****/
boolean IsEmptyWishlist(Wishlist L)
/* Mengembalikan true jika Wishlist L kosong */
{
    return First(L) == Nill;
}

void CreateEmptyWishlist(Wishlist *L)
/* I.S. sembarang             */
/* F.S. Terbentuk Wishlist kosong */
{
    First(*L) = Nill;
}

address Alokasi(infoBarang X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nill */
/* Jika alokasi gagal, mengirimkan Nill */
{
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nill)
    {
        Info(P) = X;
        Next(P) = Nill;
    } 
    return P;
}

void Dealokasi(address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

address Search (Wishlist L, infoBarang X)
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nill */
{
    address P = First(L);

    if (IsEmptyWishlist(L))
    {
        return Nill;
    }
    else
    {
        while (P != Nill)
        {
            if ((isEqualString(Item(P), X.name) && (Price(P) == X.price)))
            {
                return P;
            }
            else
            {
                P = Next(P);
            }
        }
        return Nill;
    }
}

boolean SearchX(Wishlist L, infoBarang X) {
    address P = First(L);

    if (IsEmptyWishlist(L)) {
        return false;
    } else {
        while (P != Nill) {
            // printf("Checking item: %s, price: %d\n", Item(P), Price(P));
            if ((isEqualString(Item(P), X.name) && (Price(P) == X.price))) {
                return true;
            } else {
                P = Next(P);
            }
        }
        return false;
    }
}



/**** PRIMITIF BERDASARKAN NILAI ****/
void InsVFirst(Wishlist *L, infoBarang X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P = Alokasi(X);

    if (P !=  Nill)
    {
        InsertFirstW(L, P);
    }
}

void InsVLast(Wishlist *L, infoBarang X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen Wishlist di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P = Alokasi(X);

    if (P != Nill)
    {
        InsertLastW(L, P);
    }
}
void DelP(Wishlist *L, infoBarang X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address prev = NULL;
    address curr = First(*L);

    while (curr != Nill && !(isEqualString(Item(curr), X.name) && Price(curr) == X.price)) {
        prev = curr;         
        curr = Next(curr);   
    }

   
    if (curr != Nill) {
        if (prev == NULL) {

            DelFirst(L, &curr);  
        } else {
            DelAfter(L, &curr, prev); 
        }
        Dealokasi(&curr);  
    }
}


void DelVFirst(Wishlist *L, infoBarang *X)
/* I.S. Wishist L tidak kosong  */
/* F.S. Elemen pertama Wishlist dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

void DelVLast(Wishlist *L, infoBarang *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir Wishlist dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}


/**** PRIMITIF BERDASARKAN NILAI ****/
void InsertFirstW(Wishlist *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfterW(Wishlist *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLastW(Wishlist *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (IsEmptyWishlist(*L))
    {
        InsertFirstW(L, P);
    }
    else   
    {
        address p = First(*L);
        while (Next(p) != Nill)
        {
            p = Next(p);
        }
        Next(p) = P;
    }
}

void DelFirst(Wishlist *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama L sebelum penghapusan */
/*      Elemen Wishlist berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L) = Next(*P);
}

void DelAfter(Wishlist *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
}

void DelLast(Wishlist *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    *P = First(*L);

    if (Next(*P) == Nill)
    {
        First(*L) = Nill;
    }
    else
    {
        address Prev = *P;

        while (Next(Next(Prev)) != Nill)
        {
            Prev = Next(Prev);
        }
        DelAfter(L, P, Prev);
    }
}

/**** PROSES ELEMEN LIST ****/
void PrintList(Wishlist L)
/* Mencetak isi Wishlist L*/
{
    if (IsEmptyWishlist(L))
    {
        printf("[]");
        return;
    }

    printf("[");
    address P = First(L);
    while (P != Nill)
    {
        printf("{%s, %d}", Item(P), Price(P));
        P = Next(P);
        if (P != Nill)
        {
            printf(", ");
        }
    }
    printf("]");
}

int NbWishlist(Wishlist L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count = 0;
    address P = First(L);

    while (P != Nill)
    {
        count++;
        P = Next(P);
    }
    return count;
}

