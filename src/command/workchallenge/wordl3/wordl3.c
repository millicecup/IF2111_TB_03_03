#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../../ADT/boolean.h"
#include "../../../ADT/Mesin_Kata/mesinkata.h"
#include "../../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../../ADT/List/list.h"
#include "../../../ADT/User_Barang/user.h"
#include "wordl3.h"


#define MAX_CHANCES 6
#define WORD_LENGTH 5

void displayResult(List *guess, char *word) {
    boolean usedTarget[WORD_LENGTH] = {false}; // Tracks used letters in the target word
    boolean usedGuess[WORD_LENGTH] = {false};  // Tracks used letters in the guess

    // First Pass: Mark exact matches
    for (int i = 0; i < WORD_LENGTH; i++) {
        char guessChar = GetList(*guess, i);
        char targetChar = word[i];

        if (compareStringsManual(&guessChar, &targetChar)) {
            usedTarget[i] = true; // Mark exact match as used
            usedGuess[i] = true;  // Mark guess letter as used
        }
    }

    // Second Pass: Mark misplaced matches
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (!usedGuess[i]) { // Only process unused guess letters
            char guessChar = GetList(*guess, i);
            for (int j = 0; j < WORD_LENGTH; j++) {
                if (!usedTarget[j] && compareStringsManual(&guessChar, &word[j])) {
                    usedTarget[j] = true; // Mark this target letter as used
                    usedGuess[i] = true;  // Mark this guess letter as used
                    break;
                }
            }
        }
    }

    // Display results
    for (int i = 0; i < WORD_LENGTH; i++) {
        char guessChar = GetList(*guess, i);

        if (compareStringsManual(&guessChar, &word[i])) {
            // Exact match: Correct letter and position
            printf("%c ", guessChar);
        } else if (usedGuess[i]) {
            // Correct letter but wrong position
            printf("%c* ", guessChar);
        } else {
            // Incorrect letter
            printf("%c%% ", guessChar);
        }
    }
    printf("\n");
}



boolean isWordCorrect(List *guess, char *word) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (GetList(*guess, i) != word[i]) {
            return false;
        }
    }
    return true;
}

boolean isValidInput(Word *input, int requiredLength) {
    return input->Length == requiredLength;
}

void wordl3(UserList *userList) {
    User *currentUser = &userList->users[userList->currentUserIndex];
    // Deduct coins to play the game
    if (currentUser->money < 500) {
        printf("Uang Anda tidak cukup untuk memainkan permainan ini.\n");
        return;
    }
    currentUser->money -= 500;
    printf("500 koin telah dikurangi. Sisa uang Anda: %d.\n", currentUser->money);
    printf("Selamat datang di permainan W0RDL3!\n");
    printf("ATTENTION! : \n");
    printf("Apabila huruf yang ditebak benar dan posisinya benar, maka akan ditandai dengan huruf tersebut.\n");
    printf("Apabila huruf yang ditebak benar, tapi posisinya salah, maka akan ditandai dengan huruf tersebut diikuti dengan tanda '*'.\n");
    printf("Apabila huruf yang ditebak salah, maka akan ditandai dengan huruf tersebut diikuti dengan tanda '%%'.\n");

    // Target word setup
    char *wordBank[] = {
        "APPLE", "GRAPE", "PEACH", "MANGO", "LEMON",
        "BANJO", "CHILI", "DONUT", "FERAL", "GUAVA",
        "HOTEL", "IGLOO", "JUMPY", "KNEAD", "LLAMA",
        "MORPH", "NOBLE", "OCEAN", "PENNY", "QUILT",
        "RAVEN", "SNAKE", "TULIP", "URBAN", "START",
        "WHIRL", "BEAST", "YEARN", "ZEBRA", "VIPER",
        "CLOVE", "DEATH", "ALIVE", "CRAZY", "QUAKE",
        "DAZED", "FACTS", "MYTHS", "EQUIP", "CHEWY",
        "BRAVE", "SHINE", "DREAM", "FLARE", "BLISS",
        "TRAIL", "BLINK", "FLOUR", "SPICE", "GLIDE",
        "TABLE", "CHAIR", "CLOSE", "DINER", "PANTS",
        "YUMMY", "FRESH", "INPUT", "NOMAD", "QUICK",
        "STAMP", "PLANE", "CRANE", "DRIFT", "FLEET",
        "GRACE", "PRIDE", "SHORE", "SCALE", "VIVID",
        "FIELD", "ZESTY", "JOKER", "PEACE", "PRIZE",
        "TOPAZ", "YACHT", "TIGER", "GREEN", "FUNKY",
        "STONE", "SMILE", "NIGHT", "BRICK", "WATER",
        "CLOUD", "EARTH", "BREAD", "FLUID", "QUEST",
        "SHAPE", "SHINY", "CLEAN", "THINK", "POWER",
        "ROUND", "MAGIC", "GRASP", "NOISE", "VOICE"
    };
    int wordBankSize = 100;
    srand(time(NULL));
    char *targetWord = wordBank[rand() % wordBankSize];

    printf("Selamat datang di permainan W0RDL3!\n");
    printf("Tebak kata berjumlah %d huruf dalam %d kesempatan.\n", WORD_LENGTH, MAX_CHANCES);

    List guess;
    int attempt = 0;
    boolean guessed = false;

    while (attempt < MAX_CHANCES && !guessed) {
        printf("\nTebakan ke-%d: ", attempt + 1);

        boolean validInput = false;
        while (!validInput) {
            STARTINPUT(stdin);
            if (isValidInput(&currentInput, WORD_LENGTH)) {
                validInput = true;
                CreateList(&guess, WORD_LENGTH);
                for (int i = 0; i < WORD_LENGTH; i++) {
                    SetList(&guess, i, currentInput.TabWord[i]);
                }
            } else {
                printf("Inputan harus %d huruf!\n", WORD_LENGTH);
            }
        }

        displayResult(&guess, targetWord);
        
        if (isWordCorrect(&guess, targetWord)) {
            guessed = true;
        } else {
            attempt++;
        }
    }

    if (guessed) {
        printf("\nSelamat! Anda berhasil menebak kata: %s\n", targetWord);
        printf("Anda mendapatkan 1500 koin!\n");
        currentUser->money += 1500;
    } else {
        printf("\nKesempatan habis. Kata yang benar adalah: %s\n", targetWord);
    }

    printf("Uang Anda saat ini: %d.\n", currentUser->money);
}
