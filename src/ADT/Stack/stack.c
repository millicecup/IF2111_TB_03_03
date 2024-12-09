#include "../boolean.h"
#include "stack.h"
#include "../Mesin_Kata/mesinkata.h" 


/* KONSTRUKTOR */
void CreateEmptyStack(History *S)
/* Mwmbuat stack kosong dengan kapasitas MaxEl */
{
    Top(*S) = Nil;
}

/* PREDIKAT */
boolean IsEmptyStack(History S)
/* Mengembalikan true jika stack S kosong */
{
    return Top(S) == Nil;
}

boolean IsFullStack(History S)
/* Mengembalikan true jika stack S penuh */
{
    return Top(S) == MaxStack-1;
}

/* Menambahkan elemen ke Stack */
void PushStack(History *S, char item, int price, int quantity)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    if (IsEmptyStack(*S))
    {
        Top(*S) = 0;
        assignString(InfoTopItem(*S), item);
        InfoTopPrice(*S) = price;
        InfoTopQuantity(*S) = quantity;
    }
    else
    {
        Top(*S)++;
        assignString(InfoTopItem(*S), item);
        InfoTopPrice(*S) = price;
        InfoTopQuantity(*S) = quantity;
    }
}

/* Menghapus elemen dari Stack*/
void PopStack(History *S, char *item, int *price, int *quantity)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *item = InfoTopItem(*S);
    *price = InfoTopPrice(*S);
    *quantity = InfoTopQuantity(*S);
    if (Top(*S) == 0)
    {
        Top(*S) = Nil;
    }
    else
    {
        Top(*S)--;
    }
}

void DisplayStack(History S)
/* Menampilkan semua elemen dalam stack */
{
    History reverseStack;
    CreateEmptyStack(&reverseStack);

    char itemName;
    int itemPrice;
    int itemQuantity;

    while (!IsEmptyStack(S))
    {
        PopStack(&S, &itemName, &itemPrice, &itemQuantity);
        PushStack(&reverseStack, itemName, itemPrice, itemQuantity);
    }

    printf("[");
    while (!IsEmptyStack(reverseStack))
    {
        PopStack(&reverseStack, &itemName, &itemPrice, &itemQuantity);
        printf("{");
        printf("%s", itemName);
        printf(",");
        printf("%d", itemPrice);
        printf(",");
        printf("%d", itemQuantity);
        printf("}");
        if (Top(S) >= 0) 
        {
            printf(",");
        }
    }
    printf("]\n");

}

boolean IsMemberStack(History S, char *elmt)
/* Mengecek apakah elemen tertentu ada di dalam stack */


{
    if (IsEmptyStack(S)) 
    {
        return false;
    }

    for (int i = Top(S); i >= 0; i--) {
        if (isEqualString(InfoTopItem(S), elmt)) 
        { 
            return true;
        }
    }

    return false;
}

