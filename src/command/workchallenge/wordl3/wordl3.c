#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "list.h"
#include "mesinkar.h"
#include "mesinkata.h"

#define MAX_CHANCES 6
#define WORD_LENGTH 5

void displayResult(List *guess, char *word) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        boolean found = false;
        // Periksa apakah huruf ada di kata target
        for (int j = 0; j < WORD_LENGTH; j++) {
            if (ELMT(*guess, i) == word[j]) {
                found = true;
                break;
            }
        }
        // Tentukan output berdasarkan kondisi
        if (ELMT(*guess, i) == word[i]) {
            // Huruf benar dan posisi tepat
            printf("%c", ELMT(*guess, i));
        } else if (found) {
            // Huruf benar tapi posisi salah
            printf("%c*", ELMT(*guess, i));
        } else {
            // Huruf tidak ada sama sekali
            printf("%c%%", ELMT(*guess, i));
        }
    }
    printf("\n");
}

boolean isWordCorrect(List *guess, char *word) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (ELMT(*guess, i) != word[i]) {
            return false;
        }
    }
    return true;
}

boolean isValidInput(Kata *input, int requiredLength) {
    return input->Length == requiredLength;
}

int main() {
    // Daftar kata target
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


    // Pilih kata secara acak
    srand(time(NULL));
    char *targetWord = wordBank[rand() % wordBankSize];

    // Inisialisasi permainan
    printf("Selamat datang di permainan W0RDL3!\n");
    printf("Tebak kata berjumlah %d huruf dalam %d kesempatan.\n", WORD_LENGTH, MAX_CHANCES);

    List guess;
    int attempt = 0;
    boolean guessed = false;

    while (attempt < MAX_CHANCES && !guessed) {
        printf("\nTebakan ke-%d: ", attempt + 1);

        boolean validInput = false;
        while (!validInput) {
            // Baca input kata
            MULAIKATA();

            if (isValidInput(&CKata, WORD_LENGTH)) {
                validInput = true;
                CreateList(&guess, WORD_LENGTH);
                for (int i = 0; i < WORD_LENGTH; i++) {
                    SetELMT(&guess, i, CKata.TabKata[i]);
                }
            } else {
                printf("Inputan harus %d huruf!\n"); 
                printf("Silakan masukkan lagi: ", WORD_LENGTH);
            }
        }

        // Tampilkan hasil tebakan
        displayResult(&guess, targetWord);

        // Cek apakah benar
        if (isWordCorrect(&guess, targetWord)) {
            guessed = true;
        } else {
            attempt++;
        }
    }

    // Hasil akhir
    if (guessed) {
        printf("\nSelamat! Anda berhasil menebak kata: %s\n", targetWord);
    } else {
        printf("\nKesempatan habis. Kata yang benar adalah: %s\n", targetWord);
    }

    return 0;
}
