/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef _MESINKATA_H_
#define _MESINKATA_H_

#include "../boolean.h"
#include "mesinkarakterv2.h"

#define NMax 50
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
boolean EndWord;
Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void IgnoreNewLine();

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void ResetWord();

boolean isEndWord();


boolean IsWordEqual(Word word1, Word word2);


void toWord(Word *w, const char *str);


void printWord();

boolean isEqualString(char *str1, char *str2);

void assignString(char *str1, char *str2);

boolean isWordEqualToString(Word *w, char *str);


void wordToString(Word *word, char *str);


void stringToWord(char *str, Word *word);


int WordToInt(Word *w);


Word intToWord(int n);


void CopyWordToVar(Word *w1, Word w2);


void TulisWord(Word w);


void STARTINPUT(FILE* input);


void CopyInput();


void GetInput();


void ResetInput();


#endif