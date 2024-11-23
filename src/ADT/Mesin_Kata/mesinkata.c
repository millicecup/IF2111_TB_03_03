#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"
#include "mesinkarakterv2.h"

#define MAX_LEN 50

boolean EndWord;
Word currentWord;
Word currentInput;

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

void IgnoreNewLine()
    /* Mengabaikan newline*/
{
    while (currentChar == '\n' || currentChar == '\r')
    {
        ADV();
    }
}

void STARTWORD(FILE *input)
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START(input);
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
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
        EndWord = true;
    }
    else
    {
        EndWord = false;
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
    ResetWord();
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK && currentChar != '\n' )
    {
        if (currentWord.Length < NMax)
        { 
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

void ResetWord() //dibenerin
{  
    int i;
    currentWord.Length = 0;
    for (i = 0; i < NMax ; i++)
    {
        currentWord.TabWord[i] = '\0';
    }
}

boolean isEndWord() 
{
    return EndWord;
}

boolean IsWordEqual(Word w1, Word w2) 
{
    if (w1.Length != w2.Length) return false;

    for (int i = 0; i < w1.Length; i++) {
        if (w1.TabWord[i] != w2.TabWord[i]) return false;
    }

    return true;
}

void toWord(Word *w, const char *str) 
{
    int i = 0;
    while (str[i] != '\0') 
    {
        w->TabWord[i] = str[i];
        i++;
    }
    w->Length = i;
}

void printWord()
{
    for (int i = 0; i < currentWord.Length; i++)
    {
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n");
}

boolean isWordEqualToString(Word *w, char *str) 
{
    int i = 0;
    while (i < w->Length && str[i] != '\0') 
    {
        if (w->TabWord[i] != str[i]) 
        {
            return false;
        }
        i++;
    }
    return i == w->Length && str[i] == '\0';
}

boolean isEqualString(char *str1, char *str2) 
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i]) 
        {
            return false;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

void assignString(char *str1, char *str2) 
{
    int i = 0;
    while (str2[i] != '\0')  
    {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0'; 
}


void wordToString(Word *word, char *str) 
{
    int i;
    for (i = 0; i < word->Length && i < MAX_LEN - 1; i++) 
    {
        str[i] = word->TabWord[i];
    }
    str[i] = '\0';
}

void stringToWord(char *str, Word *word) 
{
    int i = 0;
    while (str[i] != '\0' && i < 100) {
        word->TabWord[i] = str[i];
        i++;
    }
    word->TabWord[i] = '\0'; // Menambahkan null terminator
    word->Length = i;         // Menyimpan panjang string
}

int WordToInt(Word *w) 
{
    int num = 0;
    for (int i = 0; i < w->Length; i++) 
    {
        if (w->TabWord[i] < '0' || w->TabWord[i] > '9') 
        {
            return -1;  // Return -1 for invalid input
        }
        num = num * 10 + (w->TabWord[i] - '0');
    }
    return num;
}

Word intToWord(int n) {
    Word num; num.Length = 0;
    if (n == 0) {
        num.TabWord[num.Length] = '0'; num.Length++;
    } else {
        while (n != 0) {
            for (int i = num.Length; i > 0; i--) {
                num.TabWord[i] = num.TabWord[i-1];
            }
            num.Length++;
            num.TabWord[0] = (n % 10) + '0';
            n = n / 10;
        }
    }
    return num;
}

void CopyWordToVar(Word *w1, Word w2)
{
    (*w1).Length = w2.Length; 
    for (int i = 0; i < (*w1).Length; i++)
    {
        (*w1).TabWord[i] = w2.TabWord[i];
    }
}

void TulisWord(Word w) 
{
    for (int i = 0; i < w.Length; i++) 
    {
        printf("%c", w.TabWord[i]);
    }
}


void STARTINPUT(FILE* input)
{
    START(input);
    if (currentChar == '\n')
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyInput();
    }
}

void CopyInput()
{
    ResetInput(); 
    int i = 0;
    while ((currentChar != '\n') && (currentChar != EOF))
    {
        currentWord.TabWord[i] = currentChar;
        i++;
        ADV();
        
    }
    currentWord.Length = i;
}

void GetInput()
{
    ResetInput();
    STARTINPUT(stdin);
    CopyWord(&currentWord, currentInput);
}

void ResetInput()
{
    int i;
    currentInput.Length = 0;
    for (int i = 0; i < sizeof(currentInput.TabWord) ; i++) {
        currentInput.TabWord[i] = '\0';
    }
}