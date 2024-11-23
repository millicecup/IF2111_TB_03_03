#include <stdio.h>
#include "mesinkata.h"
#include <stdlib.h>

boolean endWord;
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

void IgnoreNewLine(){
    while (currentChar == NewLine){
        ADV();
        
    }
}

void STARTWORD(FILE* input)
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START(input);
    IgnoreBlanks();
    if (feof(input) || currentChar == '.' )
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
        
    }
}

void RemoveNewLineWord(Word kata)
{ 
    int length = kata.Length;
    for (int i = 0; i < length; i++)
    {
        if (kata.TabWord[i] == '\n')
        {
            kata.TabWord[i] = '\0';
            break;
        }
    }
}

// void READWORD()
// {
//     /* I.S. : currentChar sembarang
//        F.S. : endWord = true, dan currentChar = MARK;
//               atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
//               currentChar karakter pertama sesudah karakter terakhir kata */
//     STARTV2();
//     IgnoreBlanks();
//     if (currentChar == MARK)
//     {
//         endWord = true;
//     }
//     else
//     {
//         endWord = false;
//         CopyWord();
//     }
// }

void ADVWORD()
{
    IgnoreBlanks();
    IgnoreNewLine();
    if (currentChar == ' ')
    {
        endWord = false;
    }
    else
    {
        endWord= true;
        CopyWord();
    }
}



// void ADVLine(){
//     IgnoreBlanks();
//     if (currentChar == BLANK){
//         endWord = true;
//     } else{
//         endWord = false;
//         CopyWord();
//         IgnoreBlanks();
//     }
// }

void CopyWord()
{
    ResetWord();
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != '\n'){
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        } else {
            break;
        }        
    }
}

void ResetWord(){ // dibenerin 
    int i;
    currentWord.Length = 0;
    for (i = 0; i < NMax ; i++)
    {
        currentWord.TabWord[i] = '\0';
    }
}

boolean isEndWord() {
    return endWord;
}

// void GetCommand() {
//     currentWord.Length = 0;
//     STARTWORD(stdin);
// }

// Word AccessCommand(Word comm, int Idx) {
//     int count = 0, i = 0;
//     Word out;
//     out.Length = 0;

//     while (i < comm.Length && count <= Idx) {
//         out.TabWord[out.Length] = comm.TabWord[i];
//         if (comm.TabWord[i] != ' ') {
//             out.Length++;
//         }
//         if (comm.TabWord[i] == ' ') {
//             if (count < Idx) {
//                 out.Length = 0;
//             }
//             count++;
//         }
//         i++;
//     }
//     return out;
// }
    
void CopyWordToVar(Word *kata1, Word kata2)
{
    (*kata1).Length = kata2.Length; 
    for (int i = 0; i < (*kata1).Length; i++)
    {
        (*kata1).TabWord[i] = kata2.TabWord[i];
    }
}


void TulisWord(Word kata) {
    for (int i = 0; i < kata.Length && kata.TabWord[i] != '\0'; i++) {
        printf("%c", kata.TabWord[i]);
    }
    printf("\n");
}

void TulisWordNoNL(Word kata) {
    for (int i = 0; i < kata.Length && kata.TabWord[i] != '\0'; i++) {
        printf("%c", kata.TabWord[i]);
    }
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

// MASIH SALAH
boolean IsWordEq (Word kata1, Word kata2) {
    if (kata1.Length == kata2.Length) {
        for (int i = 0; i < kata1.Length; i++) {
            if (kata1.TabWord[i] != kata2.TabWord[i]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
    
}

boolean IsWordEqual(Word w1, Word w2) 
{
    if (w1.Length != w2.Length) return false;

    for (int i = 0; i < w1.Length; i++) {
        if (w1.TabWord[i] != w2.TabWord[i]) return false;
    }

    return true;
}

void STARTINPUT(FILE* input)
{
    START(input);
    IgnoreNewLine();
    if (currentChar == ';')
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyInput();
    }
}

void CopyInput()
{
    ResetInput();  // Reset array
    int i = 0;
    while ((currentChar != '\n') && (currentChar != EOF))
    {
        currentInput.TabWord[i] = currentChar;
        // printf("%c", CC);
        i++;
        ADV();
        
    }
    currentInput.Length = i;
}

void GetInput()
{
    currentInput.Length = 0;
    STARTINPUT(stdin);
}

void ResetInput(){
    int i;
    currentWord.Length = 0;
    currentLine.lengthsentence = 0;
    currentInput.Length = 0;
    for (int i = 0; i < sizeof(currentInput.TabWord) ; i++) {
        currentInput.TabWord[i] = '\0';
        currentInput.Length = 0;
    }
}


// boolean IsWordNumber (Word kata) {
//     for (int i = 0; i < kata.Length; i++) {
//         if (kata.TabWord[i] - '0' < 0 || kata.TabWord[i] - '0' > 9) return false;
//     }
//     return kata.Length > 0;
// }

int WordtoNum(const Word currentWord) {
    int result = 0;
    result = strtol(currentWord.TabWord, NULL, 10);

    return result;
}


Word toKata(char *str) {
/*  Fungsi yang menerima sebuah paramater str bertipe string
    Kemudian mengembalikan elemen bertipe Word yang merupakan hasil transformasi string str */
    Word kata;
    kata.Length = stringLength(str);
    for (int i = 0; i < kata.Length; i++) {
        kata.TabWord[i] = str[i];
    }
    return kata;
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
  
void IgnoreTK() {
    while (currentChar == ';') {
        ADV();
    }
}

// MASIH SALAH
int stringLength(char *str) {
/*  Fungsi yang menerima sebuah parameter str bertipe string
    Kemudian mengembalikan panjang dari string tersebut */
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}


void chartoWord(Word *w, char *str) {
    int i = 0;
    while (str[i] != '\0') {
        w->TabWord[i] = str[i];
        i++;
    }
    w->Length = i;
}

int WordToInt(Word *w) {
    int num = 0;
    for (int i = 0; i < w->Length; i++) {
        if (w->TabWord[i] < '0' || w->TabWord[i] > '9') {
            return -1;  // Return -1 for invalid input
        }
        num = num * 10 + (w->TabWord[i] - '0');
    }
    return num;
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

void WordToChar(const Word *word, char *output) {
    for (int i = 0; i < word->Length; i++) {
        output[i] = word->TabWord[i]; // Copy each character
    }
    output[word->Length] = '\0'; // Add null terminator at the end
}

boolean compareStringsManual(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        char ch1 = str1[i];
        char ch2 = str2[i];

        // Normalize characters to the same case manually
        if (ch1 >= 'A' && ch1 <= 'Z') {
            ch1 += ('a' - 'A'); // Convert uppercase to lowercase
        }
        if (ch2 >= 'A' && ch2 <= 'Z') {
            ch2 += ('a' - 'A'); // Convert uppercase to lowercase
        }

        if (ch1 != ch2) {
            return false; // Characters are different
        }

        i++;
    }
    // Ensure both strings end at the same length
    return (str1[i] == '\0' && str2[i] == '\0');
}
