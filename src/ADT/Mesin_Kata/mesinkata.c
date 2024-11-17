//mesinkata.c
#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakterv2.h"
#include "../user/user.h"
#include "../List/arrayuser.h"

boolean endWord;
Word currentWord;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void STARTWORD()
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK && currentChar != '\n')
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

boolean isEndWord() {
    return endWord;
}

boolean isKataEqual(const Word *w1, const Word *w2) {
    if (w1->Length != w2->Length) {
        return false;
    }
    for (int i = 0; i < w1->Length; i++) {
        if (w1->TabWord[i] != w2->TabWord[i]) {
            return false;
        }
    }
    return true;
}

void readLine(char *buffer, int maxLength) {
    int i = 0;
    char c;
    while (i < maxLength - 1 && (c = getchar()) != EOF && c != '\n') {
        buffer[i++] = c;
    }
    buffer[i] = '\0';  // Null-terminate the string
}
void toWord(Word *w, const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        w->TabWord[i] = str[i];
        i++;
    }
    w->Length = i;
}

void printWord(){
    for (int i = 0; i < currentWord.Length; i++)
    {
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n");
}

boolean isWordEqualToString(const Word *w, const char *str) {
    int i = 0;
    while (i < w->Length && str[i] != '\0') {
        if (w->TabWord[i] != str[i]) {
            return false;
        }
        i++;
    }
    return i == w->Length && str[i] == '\0';
}

// Helper function to convert Word to string (char array)
static void wordToString(const Word *word, char *str) {
    int i;
    for (i = 0; i < word->Length && i < MAX_LEN - 1; i++) {
        str[i] = word->TabWord[i];
    }
    str[i] = '\0';
}