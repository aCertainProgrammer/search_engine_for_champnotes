#include <main.h>
#include <menu.h>
#include <inputhandling.h>
#include <fileoperations.h>
#include <settings.h>
#include <constants.h>
#include <stdio.h>
#include <stdlib.h>
#include <validation.h>

void fileDisplay(char *pathToDisplay) {
    FILE *readerPointer;
    char *fileReader = malloc(10000 * sizeof(char));

    if (fileReader == NULL) memoryFail();

    readerPointer = fopen(pathToDisplay, "r");

    if (readerPointer == NULL) {
        perror("\nError opening file");
        free(fileReader);
        return;
    }

    while (fgets(fileReader, 10000, readerPointer) != NULL) {
        printf("%s", fileReader);
    }

    free(fileReader);
    fclose(readerPointer);
    return;
}

void fileOpen(char * path_to_open) {
    
    char * final_command = malloc(256 * sizeof(char));
    snprintf(final_command, 256, "%s%s", "xdg-open ", path_to_open);

    if (settings.fileOpenFlavorText == 1) {
        printf("%s\n", final_command);
    }

    int fileOpenStatus = system(final_command);

    if (fileOpenStatus == -1) {
        perror("\nError executing the command!\n");
        exit(1);
    } else if (fileOpenStatus != 0) {
        printf("\nCommand failed with exit status %d\n", fileOpenStatus);
        return;
    }
    free(final_command);
    return;
}

void createRepo()
{
    printf("\nCreating the repository, do not close the program\n");
    int status = system("scripts/createRepo.sh");
    if (status == -1)
    {
        perror("\nError creating the repo\n");
    }
    else if (status != 0)
    {
        printf("\nCommand failed with exit status %d\n", status);
    }
    mainMenu();
    return;
}

void youtubeSearchHandler(char *championToSearch, char *enemyToSearch)
{
    

        char *youtubeSearchPath = malloc(100 * sizeof(char));
        if (youtubeSearchPath == NULL) memoryFail();

        snprintf(youtubeSearchPath, 100, "%s%s%s%s%s%s", "xdg-open ", YT_SEARCH_QUERY, championToSearch, "+vs+", enemyToSearch, "+challenger+grandmaster");
        int ytSearchStatus = system(youtubeSearchPath);
        freopen("/dev/null", "w", stderr);

        if (ytSearchStatus == -1)
            perror("\nError executing the command!\n");
        else if (ytSearchStatus != 0)
        {
            printf("\nCommand failed with exit status %d\n", ytSearchStatus);
            free(youtubeSearchPath);
            exit(0);
        }
        
        free(youtubeSearchPath);
}

