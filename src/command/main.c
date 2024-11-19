#include "../../ADT/user/user.h"
#include <stdio.h>
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Kata/utils.h"
#include "../../ADT/boolean.h"
#include "../../ADT/barang/barang.h"

#include "register/register.h"
#include "start/start.h"
#include "login/login.h"
#include "load/load.h"

int main(){
    char input[MAX_LEN];
    Word command;
    Word registerCommand, loginCommand;  // Declare Word variables for the commands
    toWord(&registerCommand, "register");  // Convert "register" to Word
    toWord(&loginCommand, "login");  // Convert "login" to Word
    
    printf("Enter a command : ");
    readLine(input, MAX_LEN);
    toWord(&command, input);  // Convert input to Word
    
    if (isKataEqual(&command, &registerCommand)) {  // Compare Word types
        registerUser();
    }
    else if (isKataEqual(&command, &loginCommand)) {  // Compare Word types
        login();
    }
    else{
        printf("Invalid command\n");
    }

    return 0;
}

// gcc -IADT -I../command/register -I../command Mesin_Kata/mesinkata.c Mesin_Kata/utils.c Mesin_Kata/mesinkarakterv2.c user/user.c ../command/register/register.c ../command/main.c ../command/login/login.c -o program