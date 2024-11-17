#include "../../ADT/user/user.h"
#include <stdio.h>
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/List/arrayuser.h"
#include "register/register.h"


int main(){
    registerUser();
    return 0;
}

/*
gcc -IADT -I../command/register -I../command Mesin_Kata/mesinkata.c Mesin_Kata/mesinkarakterv2.c user/user.c List/arrayuser.c ../command/register/register.c ../command/start.c -o program

*/