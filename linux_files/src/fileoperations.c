#include <main.h>
#include <menu.h>
#include <inputhandling.h>
#include <fileoperations.h>
#include <settings.h>
#include <constants.h>
#include <validation.h>

void fileSearchHandler(const char *enemy_path, const char *championToSearch, const char *enemyToSearch)
{
    char *toDisplayOrToOpen = NULL;
   

    if (settings.championNotesSearchFlavorText == 1)
    {
            printf("Do you want to display the contents, open the file, or search a VOD on Youtube? [d/o/s]?: ");

    }
    userStringInput(&toDisplayOrToOpen);
    if (toDisplayOrToOpen == NULL) memoryFail();

    quitCheck(toDisplayOrToOpen);
  
   

    if (strcmp(toDisplayOrToOpen, "back") == 0)
    {
        NotesChampionFolderSearch();
        free(toDisplayOrToOpen);
        return;
    }

    else if(strcmp(toDisplayOrToOpen, "d") == 0)
    {   
        fileDisplay(enemy_path);
        free(toDisplayOrToOpen);
    } 
    
    else if (strcmp(toDisplayOrToOpen, "o") == 0)
    {
        
        fileOpen(enemy_path);
        free(toDisplayOrToOpen);
        
    }
    
    else if(strcmp(toDisplayOrToOpen, "s") == 0)
    {
        
        youtubeSearchHandler(championToSearch, enemyToSearch);
        free(toDisplayOrToOpen);
    }
       
    NotesChampionFolderSearch();
    return;
}

void fileDisplay(const char *pathToDisplay) {
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

void fileOpen(const char *enemy_path) {
    char *fullFilePathToOpen = malloc(200 * sizeof(char));

    if (fullFilePathToOpen == NULL) memoryFail();

    snprintf(fullFilePathToOpen, 200, "xdg-open %s", enemy_path);

    if (settings.fileOpenFlavorText == 1) {
        printf("%s\n", fullFilePathToOpen);
    }

    int fileOpenStatus = system(fullFilePathToOpen);

    if (fileOpenStatus == -1) {
        perror("\nError executing the command!\n");
        free(fullFilePathToOpen);
        exit(1);
    } else if (fileOpenStatus != 0) {
        printf("\nCommand failed with exit status %d\n", fileOpenStatus);
        free(fullFilePathToOpen);
        return;
    }
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

void NotesChampionFolderSearch()
{
    if (settings.championNotesSearchFlavorText == 1)
    {
        printf("\nType the name of the champion: ");
    }
    char * champToSearch = NULL;
    userStringInput(&champToSearch);
    if (champToSearch == NULL) memoryFail();
    quitCheck(champToSearch);
    
    if (strcmp(champToSearch, "back") == 0)
    {
        mainMenu();
        free(champToSearch);
        return;
    }
    char *InitialChampionNotesSearchPath = malloc(100 * sizeof(char));
    if (InitialChampionNotesSearchPath == NULL) memoryFail();
    
    strcpy(InitialChampionNotesSearchPath, notesSearchPathMaker(champToSearch));
    
    if (settings.championNotesSearchFlavorText == 1)
    {
        printf("%s\n", InitialChampionNotesSearchPath);
    }
    
    DIR *directorypointerSearch;
    //struct dirent *entry;
    directorypointerSearch = opendir(InitialChampionNotesSearchPath);
        if (directorypointerSearch == NULL) 
        {
            printf("\nCannot open the directory!\n");
            mainMenu();
            free(champToSearch);
            free(InitialChampionNotesSearchPath);
            return;
        }

        if (directorypointerSearch != NULL)
        {
            enemyNotesSearch(InitialChampionNotesSearchPath, champToSearch);
            free(champToSearch);
            free(InitialChampionNotesSearchPath);
            return;
        }
    
}

void youtubeSearchHandler(const char *championToSearch, const char *enemyToSearch)
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
        return;
    
    
}

void enemyNotesSearch(const char *trueSearchPath, const char *champToSearch)
{
            
    char *enemyName = NULL;
    char *helperEnemySearchPath = malloc(200 * sizeof(char));
    char *noPostfixEnemySearchPath = malloc(250 * sizeof(char));
    char *trueEnemySearchPath = malloc(300 * sizeof(char));
    
    if (helperEnemySearchPath == NULL) memoryFail();
    if (noPostfixEnemySearchPath == NULL) memoryFail();
    if (trueEnemySearchPath == NULL) memoryFail();

    if (settings.championNotesSearchFlavorText == 1)
    {
        printf("\nType the name of the enemy champion: ");
    }
    
    userStringInput(&enemyName);
    if (enemyName == NULL) memoryFail();

    quitCheck(enemyName);
    
    snprintf(helperEnemySearchPath, 200, "%s%s%s", trueSearchPath, champToSearch, UNDERSCOREVSUNDERSCORE);
    snprintf(noPostfixEnemySearchPath, 250, "%s%s", helperEnemySearchPath, enemyName);
    snprintf(trueEnemySearchPath, 300, "%s%s", noPostfixEnemySearchPath, THE_TXT_POSTFIX);
    if (settings.championNotesSearchFlavorText == 1)
    {
        printf("\n%s\n", trueEnemySearchPath);
    }       
    fileSearchHandler(trueEnemySearchPath, champToSearch, enemyName);
    free(enemyName);
    free(helperEnemySearchPath);
    free(noPostfixEnemySearchPath);
    free(trueEnemySearchPath);
    
    return;

    //file name format : [champname]_vs_[enemychampname].txt            
}

char* notesSearchPathMaker(const char *firstChampionToSearch)
{
    char helperSearchPath[50];
    char *trueSearchPath = malloc(100 * sizeof(char));
    snprintf(helperSearchPath, 50, "%s%s", THE_MAIN_PATH, firstChampionToSearch);
    snprintf(trueSearchPath, 100, "%s%s", helperSearchPath, THE_NOTES_POSTFIX);
    return trueSearchPath;
}
