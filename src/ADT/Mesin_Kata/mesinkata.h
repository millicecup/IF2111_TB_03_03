/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include <stdio.h>
#include "../boolean.h"
#include "../Mesin_Karakter/mesinkarakter.h"
#include "../Mesin_Baris/mesinbaris.h"


#define NMax 100
#define BLANK ' '
#define NewLine '\n'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean endWord;
extern Word currentWord;
extern Word currentInput;

void IgnoreBlanks();

void STARTWORD(FILE* input);

void assignString(char *str1, char *str2) ;

void ADVWORD();

void CopyWord();

boolean isEqualString(char *str1, char *str2) ;

boolean isEndWord();

void GetCommand();

void IgnoreNewLine();

void CopyWordToVar(Word *kata1, Word kata2);

void TulisWord(Word kata);

void GetInput();

void TulisWordNoNL(Word kata);

boolean IsWordEq (Word kata1, Word kata2);

int WordtoNum (Word kata);

void ResetKalimat();

void ResetWord();

void STARTINPUT(FILE* input);

void CopyInput();

void ResetInput();

Word toKata(char *str); 
/*  Fungsi yang menerima sebuah paramater str bertipe string
    Kemudian mengembalikan elemen bertipe Word yang merupakan hasil transformasi string str */

Word intToWord(int n);

void chartoWord(Word *w, char *str) ;
void WordToChar(const Word *word, char *output);
void IgnoreTK();
int WordToInt(Word *w) ;
int stringLength(char *str);
/*  Fungsi yang menerima sebuah parameter str bertipe string
    Kemudian mengembalikan panjang dari string tersebut */

boolean isWordEqualToString(const Word *w, const char *str);
void READWORD();
boolean compareStringsManual(const char *str1, const char *str2);

void stringToWord(char *str, Word *word);
boolean IsWordEqual(Word w1, Word w2) ;

#endif