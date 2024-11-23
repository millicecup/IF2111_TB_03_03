#include <stdio.h>
#include <stdbool.h>
#include "mesinkata.h"

/*
gcc mesinkata.c driver.c ../Mesin_Karakter/mesinkarakter.c ../Mesin_Baris/mesinbaris.c 

*/

int main() {
    // Tes IgnoreBlanks and IgnoreNewLine
    printf("\nTesting IgnoreBlanks and IgnoreNewLine...\n");
    FILE *input = fopen("test_input.txt", "w");
    fprintf(input, "   \n\n   Hello world!");
    fclose(input);
    input = fopen("test_input.txt", "r");
    START(input);
    IgnoreBlanks();
    printf("First non-blank character: '%c'\n", currentChar);
    IgnoreNewLine();
    printf("First non-newline character: '%c'\n", currentChar);
    fclose(input);

    // Tes STARTWORD, ADVWORD, and CopyWord
    printf("\nTesting STARTWORD and ADVWORD...\n");
    input = fopen("test_startword.txt", "w");
    fprintf(input, "Hello world!");
    fclose(input);
    input = fopen("test_startword.txt", "r");
    STARTWORD(input);
    while (!endWord) {
        printf("Word: ");
        TulisWord(currentWord);
        ADVWORD();
    }
    fclose(input);

    // Tes CopyWordToVar and ResetWord
    printf("\nTesting CopyWordToVar and ResetWord...\n");
    Word word1, word2;
    stringToWord("CopyThis", &word2);
    CopyWordToVar(&word1, word2);
    printf("Word1 after copying Word2: ");
    TulisWord(word1);
    ResetWord();
    printf("Word1 after ResetWord: ");
    TulisWord(word1);

    // Tes RemoveNewLineWord
    printf("\nTesting RemoveNewLineWord...\n");
    Word testWord;
    stringToWord("Hello\nWorld", &testWord);
    printf("Before RemoveNewLineWord: ");
    TulisWord(testWord);
    RemoveNewLineWord(testWord);
    printf("After RemoveNewLineWord: ");
    TulisWord(testWord);

    // Tes WordToInt and intToWord
    printf("\nTesting WordToInt and intToWord...\n");
    stringToWord("12345", &testWord);
    printf("Word: ");
    TulisWord(testWord);
    int num = WordToInt(&testWord);
    printf("Converted to int: %d\n", num);
    Word convertedWord = intToWord(num);
    printf("Converted back to Word: ");
    TulisWord(convertedWord);

    // Tes stringToWord and WordToChar
    printf("\nTesting stringToWord and WordToChar...\n");
    char testString[] = "ConvertMe";
    Word newWord;
    stringToWord(testString, &newWord);
    printf("Converted to Word: ");
    TulisWord(newWord);
    char output[100];
    WordToChar(&newWord, output);
    printf("Converted back to string: %s\n", output);

    // Tes IsWordEqual
    printf("\nTesting IsWordEqual...\n");
    Word word3, word4;
    stringToWord("Equal", &word3);
    stringToWord("Equal", &word4);
    printf("Word3 == Word4: %s\n", IsWordEqual(word3, word4) ? "True" : "False");

    // Tes IsEqualString
    printf("\nTesting isEqualString...\n");
    char str1[] = "Match";
    char str2[] = "Match";
    char str3[] = "Mismatch";
    printf("str1 == str2: %s\n", isEqualString(str1, str2) ? "True" : "False");
    printf("str1 == str3: %s\n", isEqualString(str1, str3) ? "True" : "False");

    // Tes compareStringsManual
    printf("\nTesting compareStringsManual...\n");
    char caseStr1[] = "CaseInsensitive";
    char caseStr2[] = "caseinsensitive";
    char caseStr3[] = "Different";
    printf("caseStr1 == caseStr2: %s\n", compareStringsManual(caseStr1, caseStr2) ? "True" : "False");
    printf("caseStr1 == caseStr3: %s\n", compareStringsManual(caseStr1, caseStr3) ? "True" : "False");

    // Tes isWordEqualToString
    printf("\nTesting isWordEqualToString...\n");
    Word compareWord;
    stringToWord("CompareThis", &compareWord);
    printf("Word == 'CompareThis': %s\n", isWordEqualToString(&compareWord, "CompareThis") ? "True" : "False");
    printf("Word == 'Mismatch': %s\n", isWordEqualToString(&compareWord, "Mismatch") ? "True" : "False");

    // Tes IgnoreTK
    printf("\nTesting IgnoreTK...\n");
    input = fopen("test_ignore_tk.txt", "w");
    fprintf(input, ";;;;Hello");
    fclose(input);
    input = fopen("test_ignore_tk.txt", "r");
    START(input);
    IgnoreTK();
    printf("First non-TK character: '%c'\n", currentChar);
    fclose(input);

    // Tes input
    printf("\nTesting input...\n");
    Word outputget, outputstart;
    GetInput();
    printf("Input: \n");
    TulisWord(currentInput);
    STARTINPUT(stdin);
    printf("Input: \n");
    TulisWord(currentInput);
    printf("All tests completed.\n");
    return 0;
}
