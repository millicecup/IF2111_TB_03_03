#include "../../ADT/User_Barang/user.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include <stdio.h>
#include "../save/save.h" 

boolean isUsernameTaken(const UserList *userArray, const Word *username) {
    for (int i = 0; i < userArray->count; i++) {
        if (isWordEqualToString(username, userArray->users[i].name)) {
            return true;
        }
    }
    return false;
}

void saveuser(const char *filename, User *newUser) {
    FILE *file = fopen(filename, "a"); // Buka file dengan append mode
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    // Append hanya data user baru
    fprintf(file, "%d %s %s\n", newUser->money, newUser->name, newUser->password);

    fclose(file);
}


void registerUser(UserList *userArray) {
    Word password, name;
    boolean validInput = false;
    User newUser;

    while (!validInput) {
        printf("Enter username: ");
        STARTINPUT(stdin);
        if (currentInput.Length == 0) {
            printf("Username cannot be empty. Please try again.\n");
            continue;
        } else if (isUsernameTaken(userArray, &currentInput)) {
            printf("Username is already taken. Please try again.\n");
            continue;
        }

        name = currentInput;

        printf("Enter password: ");
        STARTINPUT(stdin);
        if (currentInput.Length == 0) {
            printf("Password cannot be empty. Please try again.\n");
            continue;
        }

        password = currentInput;

        printf("Enter initial money (or press Enter for default 0): ");
        STARTINPUT(stdin);
        int money = WordToInt(&currentInput);
        if (currentInput.Length == 0) {
            newUser.money = 0; // Default money
        } else {
            newUser.money = money;
            if (money < 0) {
                printf("Money cannot be negative. Please try again.\n");
                continue;
            }
        }

        validInput = true;
    }

    printf("Username: %s\n", name.TabWord);
    printf("Password: %s\n", password.TabWord);

    // Copy strings into `newUser` struct
    for (int i = 0; i < name.Length && i < MAX_LEN - 1; i++) {
        newUser.name[i] = name.TabWord[i];
    }
    newUser.name[name.Length] = '\0';

    for (int i = 0; i < password.Length && i < MAX_LEN - 1; i++) {
        newUser.password[i] = password.TabWord[i];
    }
    newUser.password[password.Length] = '\0';

    // Add user to `userArray`
    AddUser(userArray, newUser.name, newUser.password, newUser.money);

    // Save only the new user
    saveuser("Data/dummy.txt", &newUser);
    

    printf("Registration successful! User '%s' has been registered.\n", name.TabWord);
}
