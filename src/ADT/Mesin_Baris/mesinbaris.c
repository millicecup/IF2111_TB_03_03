#include <stdio.h>
#include "mesinbaris.h"

boolean endLine;
boolean EndSentence;

Sentence currentLine;

void STARTFILE(FILE* input)
{
    printf("tes");
    START(input);
    IgnoreNewLine();
    if (currentChar == '\0')
    {
        endWord = true;
        printf("tes3");
    }
    else
    {
        endWord = false;
        printf("tes2");
        CopyLine();
    }
}
void STARTINPCOMMAND(FILE* input)
{
    START(input);
    IgnoreNewLine();
    if (currentChar == '\n')
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyCommand();
    }
}

void ResetCommand() {
    for (int i = 0; i < sizeof(currentWord.TabWord); i++) {
        currentWord.TabWord[i] = '\0';
        currentWord.Length = 0;
    }
}

void CopyCommand() {
    ResetCommand();
    int i = 0;
    while ((currentChar != '\n') && (currentChar != ' ') && (currentChar != EOF))
    {
        currentWord.TabWord[i] = currentChar;
        i++;
        ADV();
        
    }
    currentWord.Length = i;
}

void ADVCOMM() {
    IgnoreBlanks();
    if (currentChar != '\n')
    {
        endWord = false;
        CopyCommand();
    } 
    else
    {
        endWord = true;
    }
}

void CopyLine() {
    ResetKalimat();  // Reset buffer
    int i = 0;
    while (currentChar != '\n' && currentChar != EOF && currentChar != ';') {
        //printf("Menyalin karakter: %c\n", currentChar);
        currentLine.kalimat[i] = currentChar;  // Salin karakter
        i++;
        ADV();  // Memajukan pembaca karakter ke karakter berikutnya
    }  
    // Menambahkan null terminator pada akhir kalimat
    currentLine.lengthsentence = i;  // Menyimpan panjang kalimat
}


void ADVLINE()
{
    IgnoreBlanks();
    if (currentChar != '\n')
    {
        endLine = false;
        CopyLine();
    } 
    else
    {
        endLine = true;
    }
}

void ADVSENTENCE(){
    IgnoreBlanks();
    IgnoreNewLine();
    if (currentChar == '\n'){
        EndSentence = true;
    } 
    else
    {
        EndSentence = false;
        CopyLine();
    }
}

void ADVRECORD() {
    IgnoreBlanks();
    IgnoreNewLine();
    IgnoreTK();
    if (currentChar == ';') {
        EndSentence = true;
    }
    else {
        EndSentence = false;
        CopyLine();
    }
}

void GetCommand()
{
    currentWord.Length = 0;
    STARTINPCOMMAND(stdin);
}
    // STARTLINE(stdin); << awalnya


// nambah fungsi TulisKalimat
void TulisKalimat(Sentence currentLine) {
    for (int i = 0; i < currentLine.lengthsentence; i++) {
        if (currentLine.kalimat[i]!= '\n'){
            printf("%c", currentLine.kalimat[i]);
        }
    }
    printf("\n");
}

boolean isInputEqual(Sentence Input, Word Kata)
{   
    boolean equal = true;
    if (Input.lengthsentence == Kata.Length)
    {
        int i = 0;
        while (i < Input.lengthsentence && equal)
        {
            if (Input.kalimat[i] != Kata.TabWord[i])
            {
                equal = false;
            }
            else
            {
                i++;
            }
        }
        return equal;
    }
    else
    {
        return false;
    }
}

void ResetKalimat(){ // dibenerin 
    int i;
    currentWord.Length = 0;
    currentLine.lengthsentence = 0;
    
    for (i = 0; i < NMax ; i++)
    {
        currentWord.TabWord[i] = '\0';
        currentLine.kalimat[i] = '\0';
    }
}

