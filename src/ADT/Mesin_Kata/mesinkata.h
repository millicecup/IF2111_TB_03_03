/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

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
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

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

boolean isEndWord();
/* Mengembalikan true jika EndWord = true */

boolean isKataEqual(const Word *w1, const Word *w2);
/* Mengembalikan true jika w1 = w2; dua kata dikatakan sama jika panjangnya sama dan urutan karakter yang menyusun kata juga sama 
   w1.Length = w2.Length dan untuk setiap i = 1, ..., w1.Length, w1.TabWord[i] = w2.TabWord[i] 
*/
void readLine(char *buffer, int maxLength);
/* Membaca sebuah baris dari input user dan menyimpannya dalam buffer
   I.S. : buffer sembarang, maxLength adalah panjang maksimal baris yang dapat dibaca
   F.S. : buffer berisi baris input pengguna, tidak termasuk karakter newline '\n'
          atau buffer kosong jika tidak ada input pengguna */

void toWord(Word *w, const char *str);
/* Mengubah string menjadi Word
   I.S. : w sembarang, str adalah string yang valid
   F.S. : w berisi string str */


void printWord();
/* Menampilkan currentWord 
   I.S. : currentWord terdefinisi
   F.S. : Menampilkan currentWord ke layar */


boolean isWordEqualToString(const Word *w, const char *str);
/* mengembalikan true jika w sama dengan str
   I.S. : w dan str terdefinisi
   F.S. : mengembalikan true jika w sama dengan str */

static void wordToString(const Word *word, char *str);
/* mengubah Word menjadi string
   I.S. : word terdefinisi
   F.S. : str berisi word */

#endif