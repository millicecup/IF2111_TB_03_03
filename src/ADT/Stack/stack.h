#ifndef STACK_H
#define STACK_H

#include "../boolean.h"
#include "../User_Barang/barang.h" 

#define Niil -1
#define MaxStack 100
#define Max_Length 50

typedef struct {
    char item[MaxStack + 1][Max_Length]; 
    int price[MaxStack + 1];
    int quantity[MaxStack + 1];
    int cost[MaxStack + 1];
    int TOP;   
    int total;     
} History;

#define Top(S) (S).TOP
#define InfoTopItem(S) (S).item[(S).TOP]
#define InfoTopPrice(S) (S).price[(S).TOP]
#define InfoTopQuantity(S) (S).quantity[(S).TOP]
#define InfoTopCost(S) (S).cost[(S).TOP]
#define Total_Amount(S) (S).total


/* KONSTRUKTOR */
void CreateEmptyStack(History *S);
/* Mwmbuat stack kosong dengan kapasitas MaxEl */

/* PREDIKAT */
boolean IsEmptyStack(History S);
/* Mengembalikan true jika stack S kosong */

boolean IsFullStack(History S);
/* Mengembalikan true jika stack S penuh */

/* Menambahkan elemen ke Stack */
void PushStack(History *S, char *item, int price, int quantity);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* Menghapus elemen dari Stack*/
void PopStack(History *S, char *item, int *price, int *quantity);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void DisplayStack(History S);
/* Menampilkan semua elemen dalam stack */

boolean IsMemberStack(History S, char *elmt);
/* Mengecek apakah elemen tertentu ada di dalam stack */

#endif 
