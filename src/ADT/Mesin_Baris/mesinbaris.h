#ifndef __MESINBARIS_H__
#define __MESINBARIS_H__

#include "../boolean.h"
#include "../Mesin_Karakter/mesinkarakter.h"
#include "../Mesin_Kata/mesinkata.h"

#define NewLine '\n'
#define Nmax 50
typedef struct 
{
    char kalimat[Nmax];
    int lengthsentence;
} Sentence;

extern Sentence currentLine;

/*  Kebanyakan fungsi mesinbaris digunakan atau diimplementasikan untuk
    bagian masukan dari pengguna atau pada terminal */

void STARTFILE(FILE* input);
/* Mesin membaca file dari inputan */

void STARTINPCOMMAND(FILE* input);
/* Mesin membaca masukan dari pengguna */

void ResetCommand();
/* Mesin akan mengulangi indeks dari sebuah inputan kembali ke 0 */

void ADVCOMM();
/* Mesin akan menyimpan masukan kata kedua dari pengguna */

void ADVLINE();
/* Pita akan maju satu baris atau turun ke baris selanjutnya */

void ADVSENTENCE();
/* Pita akan maju satu kalimat */

void ADVRECORD();
/* Pita akan maju jika menemukan semicolon */

void GetCommand();

void TulisKalimat(Sentence currentLine);
/* Mesin akan mengembalikan kalimat */
/* I.S. : currentLine adalah kalimat pertama kata yang akan diakuisisi
   F.S. : currentLine adalah kalimat terakhir yang sudah diakuisisi,
          currentLine adalah kalimat pertama dari kalimat berikutnya, mungkin NEWLINE
          Jika currentLine = NEWLINE, EndSentence = true. */

void CopyCommand();
/* Mesin mengakuisisi dan menduplikasi masukan dari pengguna */

void CopyLine();
/* */

// boolean isInputEqual(Sentence Input, Word Kata);

void GetInput();

void ResetKalimat();

// Word AccessCommand(Sentence comm, int Idx);

Sentence tokalimat (Sentence kata);

int SentenceLength(Sentence kata);

#endif