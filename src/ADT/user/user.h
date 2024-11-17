#ifndef USER_H
#define USER_H

#include "../Mesin_Kata/mesinkata.h"
#include "../boolean.h"

#define MAX_LEN 50

/* User definition */
typedef struct {
    Word name;
    Word password;
    int money;
} User;


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

void addUser(const User *user);
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
void saveUsersToFile();
/*
{ I.S. : User array terdefinisi }
{ F.S. : User array disimpan ke file users.txt }
*/
void loadUsersFromFile();
/*
{ I.S. : User array terdefinisi }
{ F.S. : User array diisi dengan data dari file users.txt }
*/
#endif