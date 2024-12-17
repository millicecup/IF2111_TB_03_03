#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../boolean.h"
#include "../User_Barang/barang.h"

#define Nil NULL

typedef Barang infoBarang;

typedef struct tElmtlist *address;

typedef struct tElmtlist { 
	infoBarang info;
	address next;
} ElmtList;

typedef struct {
	address First;
} Wishlist;

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)
#define Item(P) (P)->info.name
#define Price(P) (P)->info.price

/**** PROTOTYPE ****/
boolean IsEmptyWishlist(Wishlist L);
/* Mengembalikan true jika Wishlist L kosong */

void CreateEmptyWishlist(Wishlist *L);
/* I.S. sembarang             */
/* F.S. Terbentuk Wishlist kosong */

address Alokasi(infoBarang X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi(address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

address Search (Wishlist L, infoBarang X);
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

boolean SearchX (Wishlist L, infoBarang X);
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan true. */


/**** PRIMITIF BERDASARKAN NILAI ****/
void InsVFirst(Wishlist *L, infoBarang X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLast(Wishlist *L, infoBarang X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen Wishlist di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void DelVFirst(Wishlist *L, infoBarang *X);
/* I.S. Wishist L tidak kosong  */
/* F.S. Elemen pertama Wishlist dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */

void DelVLast(Wishlist *L, infoBarang *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir Wishlist dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/**** PRIMITIF BERDASARKAN NILAI ****/
void InsertFirstW(Wishlist *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

void InsertAfterW(Wishlist *L, address P, address Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLastW(Wishlist *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

void DelFirst(Wishlist *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama L sebelum penghapusan */
/*      Elemen Wishlist berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelP (); ///ntar yak kalo butuh hehehe
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void DelAfter(Wishlist *L, address *Pdel, address Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

void DelLast(Wishlist *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */

/**** PROSES ELEMEN LIST ****/
void PrintList(Wishlist L);
/* Mencetak isi Wishlist L*/

int NbWishlist(Wishlist L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */


#endif