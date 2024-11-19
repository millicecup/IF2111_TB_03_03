#ifndef USER_H
#define USER_H

#include "../Mesin_Kata/mesinkata.h"
#include "../boolean.h"
#include "../barang/barang.h"

#define MAX_LEN 50
#define MAX_USERS 100
#define IdxType int

/* User definition */
typedef struct {
    Word name;
    Word password;
    int money;
} User;

/* Array structure for Users (static array) */
typedef struct {
    User A[MAX_USERS];
    int Neff; // effective size
} ArrayUser;


/* Function prototypes */
ArrayUser MakeArrayUser();
/* 
{ I.S. : sembarang }
{ F.S. : Mengembalikan ArrayUser kosong dengan Neff = 0 }
*/

boolean IsEmptyUser(ArrayUser array);
/*
{ I.S. : ArrayUser terdefinisi }
{ F.S. : Mengembalikan true jika Neff = 0 }
*/

int LengthUser(ArrayUser array);
/*
{ I.S. : ArrayUser terdefinisi }
{ F.S. : Mengembalikan Neff }
*/

User GetUser(ArrayUser array, int i);
/*
{ I.S. : ArrayUser terdefinisi, i di antara 0..Neff-1 }
{ F.S. : Mengembalikan elemen ke-i dari array }
*/

int GetUserCapacity();
/*
{ I.S. : ArrayUser terdefinisi }
{ F.S. : Mengembalikan kapasitas array, yaitu MAX_USERS }
*/

void InsertAtUser(ArrayUser *array, User el, int i);
/*
{ I.S. : ArrayUser terdefinisi, i di antara 0..Neff }
{ F.S. : Menambahkan elemen el ke array pada posisi i }
*/

void InsertLastUser(ArrayUser *array, User el);
/*
{ I.S. : ArrayUser terdefinisi }
{ F.S. : Menambahkan elemen el di akhir array }
*/

void InsertFirstUser(ArrayUser *array, User el);
/*
{ I.S. : ArrayUser terdefinisi }
{ F.S. : Menambahkan elemen el di awal array }
*/

void DeleteAtUser(ArrayUser *array, int i);
/*
{ I.S. : ArrayUser terdefinisi, i di antara 0..Neff-1 }
{ F.S. : Menghapus elemen ke-i dari array }
*/

void DeleteLastUser(ArrayUser *array);
/*
{ I.S. : ArrayUser terdefinisi }
{ F.S. : Menghapus elemen terakhir dari array }
*/

void DeleteFirstUser(ArrayUser *array);
/*
{ I.S. : ArrayUser terdefinisi }
{ F.S. : Menghapus elemen pertama dari array }
*/

void PrintArrayUser(ArrayUser array);
/*
{ I.S. : ArrayUser terdefinisi }
{ F.S. : Menampilkan isi array ke layar }
*/

ArrayUser CopyArrayUser(ArrayUser array);
/*
{ I.S. : ArrayUser terdefinisi }
{ F.S. : Menghasilkan salinan array }
*/

int SearchArrayUser(ArrayUser array, Word name);
/*
{ I.S. : ArrayUser terdefinisi, name diberikan }
{ F.S. : Mengembalikan indeks pertama elemen dengan name tersebut, -1 jika tidak ditemukan }
*/

// User management functions
void initUser(User *user, const Word *name, const Word *password);
/*
{ I.S. : user sembarang }
{ F.S. : user terdefinisi dengan name = name dan password = password }
*/

void printUser(const User *user);
/*
{ I.S. : user terdefinisi }
{ F.S. : Menampilkan informasi user ke layar }
*/

void initializeUserArray();
/*
{ I.S. : User array belum terdefinisi }
{ F.S. : User array dinamis terinisialisasi }
*/

void addUser(ArrayUser *userArray, User *newUser) ;

void saveUsersToFile(ArrayUser *userArray) ;

/*
{ I.S. : User array terdefinisi, name dan password diberikan }
{ F.S. : User baru dengan name dan password ditambahkan ke array }
*/

boolean cariUser(const Word *name);
/*
{ I.S. : User array terdefinisi, name diberikan }
{ F.S. : Mengembalikan true jika user dengan name tersebut ditemukan, false jika tidak }
*/

// File persistence functions
//void saveUsersToFile();
/*
{ I.S. : User array terdefinisi }
{ F.S. : User array disimpan ke file users.txt }
*/
void loadUsersFromFile();
/*
{ I.S. : User array terdefinisi }
{ F.S. : User array diisi dengan data dari file users.txt }
*/

boolean validlogin(const Word *name, const Word *password);


#endif
