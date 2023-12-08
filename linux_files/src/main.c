#include "menu.h"
#include "settings.h"
#include <stdio.h>


int main() {
    
    settingsLoader();
    if (settings.welcomeScreenFlavorText == 1) {
        printf("Program start successful\n");
        printf("Type \"help\" for the command list\n");
        printf("Make sure you read the manual for a good experience\n");
    }
    mainMenu();
    return 0;
}
