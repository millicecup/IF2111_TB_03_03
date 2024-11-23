#include <stdio.h>
#include "mesinbaris.h"

/*
gcc mesinbaris.c ../Mesin_Kata/mesinkata.c ../Mesin_Karakter/mesinkarakter.c driver.c -o driver
*/

int main() {
    // Test STARTFILE
    printf("Testing STARTFILE (Enter a single line of input):\n");
    STARTFILE(stdin);
    printf("Initial line: ");
    TulisKalimat(currentLine);
    printf("\n");

    // Test ADVLINE
    printf("Testing ADVLINE (Enter another line of input):\n");
    ADVLINE();
    if (!endLine) {
        printf("Next line: ");
        TulisKalimat(currentLine);
    } else {
        printf("End of line reached.\n");
    }

    // Test GetCommand
    printf("\nTesting GetCommand (Enter a command ending with ';'):\n");
    GetCommand();
    printf("Command: ");
    for (int i = 0; i < currentWord.Length; i++) {
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n");

    // Test ADVCOMM
    printf("\nTesting ADVCOMM (Enter another command ending with ';'):\n");
    ADVCOMM();
    if (!endWord) {
        printf("Next command: ");
        for (int i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        printf("\n");
    } else {
        printf("End of commands.\n");
    }

    // Test ADVSENTENCE
    printf("\nTesting ADVSENTENCE (Enter a sentence ending with ';'):\n");
    ADVSENTENCE();
    if (!EndSentence) {
        printf("Sentence: ");
        TulisKalimat(currentLine);
    } else {
        printf("End of sentence reached.\n");
    }

    // Test ADVRECORD
    printf("\nTesting ADVRECORD (Enter a record ending with ';'):\n");
    ADVRECORD();
    if (!EndSentence) {
        printf("Record: ");
        TulisKalimat(currentLine);
    } else {
        printf("End of record reached.\n");
    }

    // Test ResetKalimat
    printf("\nTesting ResetKalimat:\n");
    printf("Before ResetKalimat, currentLine: ");
    TulisKalimat(currentLine);
    ResetKalimat();
    printf("After ResetKalimat, currentLine: ");
    TulisKalimat(currentLine);

    printf("\nAll functions tested successfully.\n");
    return 0;
}
