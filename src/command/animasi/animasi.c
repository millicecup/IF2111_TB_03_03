#include "animasi.h"
#include "../work/work.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printImage(FILE *fascii)
{
    char read[MAX_LENGTH];
    while(fgets(read,sizeof(read),fascii) != NULL)
    printf("%s",read);
    printf("\n");   
}

void animasiMainMenu()
{
    FILE *fascii;
    system("cls || clear");
    fascii = NULL;
    fascii = fopen("animasi/run.txt","r");
    if(fascii  == NULL)
    {
        printf("error opening file\n");
    } 
    else 
    {
        system("cls || clear");
        printImage(fascii);
        fclose(fascii);
    }
    printf("\n\n\n"); 
}

void animasiStore()
{
    FILE *fascii;
    fascii = NULL;
    fascii = fopen("animasi/store.txt","r");
    if(fascii  == NULL)
    {
        printf("error opening file\n");
    } 
    else 
    {
        printImage(fascii);
        fclose(fascii);
    }
    printf("\n\n\n"); 
}

void animasiMenu()
{
    FILE *fascii;
    fascii = NULL;
    fascii = fopen("animasi/menu.txt","r");
    if(fascii  == NULL)
    {
        printf("error opening file\n");
    } 
    else 
    {
        printImage(fascii);
        fclose(fascii);
    }
    printf("\n\n\n"); 
}

void animasiLogin()
{
    FILE *fascii;
    fascii = NULL;
    fascii = fopen("animasi/login.txt","r");
    if(fascii  == NULL)
    {
        printf("error opening file\n");
    } 
    else 
    {
        printImage(fascii);
        fclose(fascii);
    }
    printf("\n\n\n"); 
}

void animasiQuit()
{
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i <4; i++)
    {
        if (i == 0)
        {
            filename = "animasi/quit1.txt";
        }
        else if (i == 1)
        {
            filename = "animasi/quit2.txt";
        }
        else if (i == 2)
        {
            filename = "animasi/quit3.txt";
        }
        else if (i == 3)
        {
            filename = "animasi/quit4.txt";
        }

        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL)
        {
            printf("error opening file\n");
        } 
        else 
        {
            system("cls || clear");
            printImage(fascii);
            fclose(fascii);
        } 
        tunggu(1);
    }
}

void animasiProfile()
{
    FILE *fascii;
    fascii = NULL;
    fascii = fopen("animasi/profile.txt","r");
    if(fascii  == NULL)
    {
        printf("error opening file\n");
    } 
    else 
    {
        printImage(fascii);
        fclose(fascii);
    } 
}

void animasiChallenge(){
    FILE *fascii;
    fascii = NULL;
    fascii = fopen("animasi/workchallenge.txt","r");
    if(fascii  == NULL)
    {
        printf("error opening file\n");
    } 
    else 
    {
        printImage(fascii);
        fclose(fascii);
    }
    printf("\n\n\n"); 
}

void animasiWork(){
    FILE *fascii;
    fascii = NULL;
    fascii = fopen("animasi/work.txt","r");
    if(fascii  == NULL)
    {
        printf("error opening file\n");
    } 
    else 
    {
        printImage(fascii);
        fclose(fascii);
    }
    printf("\n\n\n"); 
}

void animasiCart()
{
    FILE *fascii;
    fascii = NULL;
    fascii = fopen("animasi/cart.txt","r");
    if(fascii  == NULL)
    {
        printf("error opening file\n");
    } 
    else 
    {
        printImage(fascii);
        fclose(fascii);
    }
    printf("\n\n\n"); 
}

void animasiWishlist()
{
    FILE *fascii;
    fascii = NULL;
    fascii = fopen("animasi/wishlist.txt","r");
    if(fascii  == NULL)
    {
        printf("error opening file\n");
    } 
    else 
    {
        printImage(fascii);
        fclose(fascii);
    }
    printf("\n\n\n"); 
}

void animasiHistory(){
    FILE *fascii;
    fascii = NULL;
    fascii = fopen("animasi/history.txt","r");
    if(fascii  == NULL)
    {
        printf("error opening file\n");
    } 
    else 
    {
        printImage(fascii);
        fclose(fascii);
    }
    printf("\n\n\n"); 
}

void printMainMenu() {
    printf("=========================================\n");
    printf("Welcome to PURRMART Main Menu!\n");
    printf("Available Commands:\n");
    printf("- START  : Load default configuration\n");
    printf("- LOAD   : Load from a saved file\n");
    printf("- HELP   : Show available commands\n");
    printf("- QUIT   : Exit the program\n");
    printf("=========================================\n");
    printf("Enter your command: ");
}

void printLoginMenu() {
    printf("=========================================\n");
    printf("Welcome to PURRMART Login Menu!\n");
    printf("Available Commands:\n");
    printf("- LOGIN    : Log in to your account\n");
    printf("- REGISTER : Register a new account\n");
    printf("- HELP     : Show available commands\n");
    printf("- SAVE     : Save current state to a specific file\n");
    printf("- QUIT     : Quit the application\n");
    printf("- MAIN     : Return to Main Menu\n");
    printf("=========================================\n");
    printf("Enter your command: ");
}

void printInsideMenu() {
    printf("=========================================\n");
    printf("Welcome to PURRMART!\n");
    printf("Available Commands:\n");
    printf("- STORE    : Seeing store\n");
    printf("- WORK     : Gain money\n");
    printf("- HELP     : Show available commands\n");
    printf("- LOGOUT   : Log out from your account\n");
    printf("=========================================\n");
    printf("Enter your command: ");
}


void printStoreMenu(){
    printf("=========================================\n");
    printf("Welcome to PURRMART!\n");
    printf("Available Commands:\n");
    printf("- STORE LIST        : Display store\n");
    printf("- STORE REQUEST     : Request item\n");
    printf("- STORE REMOVE      : Remove item from store\n");
    printf("- STORE SUPPLY      : Add barang from request to store\n");
    printf("- MENU              : Return to Inside Menu\n");
    printf("=========================================\n");
    printf("Enter your command: ");
}