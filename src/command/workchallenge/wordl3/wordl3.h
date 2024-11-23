#ifndef WORLD3_H
#define WORLD3_H

#include "../../../ADT/boolean.h"
#include "../../../ADT/Mesin_Kata/mesinkata.h"
#include "../../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../../ADT/List/list.h"
#include "wordl3.h"


void displayResult(List *guess, char *word) ;
boolean isWordCorrect(List *guess, char *word) ;

boolean isValidInput(Word *input, int requiredLength) ;

void wordl3();

#endif