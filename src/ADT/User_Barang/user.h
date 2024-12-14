#ifndef __USER_H_
#define __USER_H_


#define MAX_USERS 100 // Maksimum jumlah pengguna
#define MAX_LEN 100   // Panjang maksimum nama/password

#include "../SetMap/setmap.h"
#include "../Stack/stack.h"
#include "../LinkedList/linkedlist.h"

typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
    Keranjang keranjang;        //map
    History riwayat_pembelian;  //stack
    Wishlist wishlist;          //linkedlist
} User;

typedef struct {
    User users[MAX_USERS];
    int count; // Jumlah pengguna saat ini
    int currentUserIndex;
} UserList;

void CreateUserList(UserList *list);

int IsUserListFull(UserList *list);

int IsUserListEmpty(UserList *list);

void ManualStringCopy(char *dest, const char *src);

void AddUser(UserList *list, char *name, char *password, int money);

void PrintUsers(UserList *list);

void InsertLastUser(UserList *array, User el) ;

void addUser(UserList *userArray, User *newUser);

void ModifyUserMoney(UserList *list, char *name, int newMoney);
#endif