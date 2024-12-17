#include <stdio.h>
#include "help.h"

int main() {
    printf("=== Testing Help Function ===\n");

    MenuState currentMenu;

    // Test Welcome Menu Help
    printf("\nTesting Welcome Menu Help...\n");
    currentMenu = menuforwelcome;  // Set menu state
    help(&currentMenu);  // Display help for the welcome menu

    // Test Login Menu Help
    printf("\nTesting Login Menu Help...\n");
    currentMenu = menuforlogin;  // Set menu state
    help(&currentMenu);  // Display help for the login menu

    // Test Main Menu Help
    printf("\nTesting Main Menu Help...\n");
    currentMenu = menuutama;  // Set menu state
    help(&currentMenu);  // Display help for the main menu

    // Test Menu State Update
    printf("\nTesting Menu State Update...\n");
    currentMenu = menuforwelcome;
    printf("Initial menu state: Welcome Menu\n");
    update_menu(&currentMenu, menuforlogin);  // Update to login menu
    printf("Updated to: Login Menu\n");
    help(&currentMenu);  // Verify the updated menu state

    return 0;
}
