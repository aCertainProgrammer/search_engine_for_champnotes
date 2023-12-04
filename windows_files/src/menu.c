// menu.c
#include "menu.h"
#include "main.h"
#include "settings.h"
#include "fileoperations.h"
#include "champnotessearch.h"
#include "draftnotessearch.h"
#include "constants.h"
#include "validation.h"
#include "inputhandling.h"

void mainMenu() {
    if (settings.mainMenuFlavorText == 1) {
        printf("\nYou are in the main menu\n");
        printf("Enter a command: ");
    }
    commandInputHandler();
}

void commandInputHandler() {
    char *command = NULL;
    userStringInput(&command);

    if (command == NULL) memoryFail();

    if (strcmp(command, "search") == 0) {
        NotesChampionFolderSearch();
        free(command);
        return;
    } else if (strcmp(command, "help") == 0) {
        helpCommand();
        free(command);
        return;
    } else if (strcmp(command, "quit") == 0) {
        quitCheck(command);
        free(command);
        return;
    } else if (strcmp(command, "createrepo") == 0) {
        createRepo();
        free(command);
        return;
    } else if (strcmp(command, "draft") == 0) {
        draftSearch();
        free(command);
        return;
    } else {
        printf("\nNot a known command! Type \"help\" to see the command list!\n");
        mainMenu();
        free(command);
        return;
    }
}

void helpCommand()
{
    printf("\"createrepo\" \n");
    printf("\"search\" \n");
    printf("\"draft\" \n");
    printf("\"back\"\n");
    printf("\"quit\"\n");
    mainMenu();
    return;
}