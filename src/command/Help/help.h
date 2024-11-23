#ifndef HELP_H
#define HELP_H

#include <stdio.h>

// struck for help
typedef enum {
    menuforwelcome,
    menuforlogin,
    menuutama,
    menustore,
    menuwork,
    menuworkchallenge,
} MenuState;


void help(MenuState *current_menu);
void update_menu(MenuState *current_menu, MenuState menu_updated);

#endif // HELP_H
