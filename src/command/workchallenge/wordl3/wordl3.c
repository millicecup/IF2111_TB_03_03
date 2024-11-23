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
    for (int i = 0; i < WORD_LENGTH; i++) {
        boolean found = false;
        // Periksa apakah huruf ada di kata target
        for (int j = 0; j < WORD_LENGTH; j++) {
            if (GetList(*guess, i) == word[j]) {
                found = true;
                break;
            }
        }
        // Tentukan output berdasarkan kondisi
        if (GetList(*guess, i) == word[i]) {
            // Huruf benar dan posisi tepat
            printf("%c", GetList(*guess, i));
        } else if (found) {
            // Huruf benar tapi posisi salah
            printf("%c*", GetList(*guess, i));
        } else {
            // Huruf tidak ada sama sekali
            printf("%c%%", GetList(*guess, i));
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

void wordl3(User *currentUser) {
    // Deduct coins to play the game
    if (currentUser->money < 1500) {
        printf("Uang Anda tidak cukup untuk memainkan permainan ini.\n");
        return;
    }
    currentUser->money -= 1500;
    printf("1500 koin telah dikurangi. Sisa uang Anda: %d.\n", currentUser->money);

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
                    SetList(&guess, i, currentWord.TabWord[i]);
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

    printf("Sisa uang Anda: %d.\n", currentUser->money);
}
