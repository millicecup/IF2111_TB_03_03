#include "../../ADT/user/user.h"
#include <stdio.h>
#include "../../ADT/Mesin_Kata/mesinkata.h"

#include "register/register.h"


int main(){
    registerUser();
    return 0;
}

/*
/*
kalo mau simpen di ADT :
gcc -IADT -I../command/register -I../command Mesin_Kata/mesinkata.c Mesin_Kata/mesinkarakterv2.c user/user.c ../command/register/register.c ../command/start.c -o program
kalo mau simpen di command register :
gcc -Icommand -I../ADT Mesin_Kata/mesinkata.c Mesin_Kata/mesinkarakterv2.c user/user.c register/register.c main.c -o program
*/