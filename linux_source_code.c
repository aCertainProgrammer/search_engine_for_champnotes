#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void mainMenu();
void commandInputHandler(char command[100]);
void fileDisplay(const char* PathToDisplay);
void search();
void helpCommand();
void fileSearchHandler(const char *enemy_path, const char *championToSearch, const char *enemyToSearch);
void fileOpen(const char *enemy_path);
void youtubeSearchHandler(const char *championToSearch, const char *enemyToSearch);
void createRepo();
void enemyNotesSearch(const char *trueSearchPath, const char *champToSearch);
void draftSearch();
void quitCheck(const char *isQuit);

const int CURRENT_CHAMPION_AMOUNT = 166;
const char THE_MAIN_PATH[] = "main_notes_folder/";
const char THE_NOTES_POSTFIX[] = "_notes/";
const char THE_TXT_POSTFIX[] = ".txt";
const char UNDERSCOREVSUNDERSCORE[] = "_vs_";
const char YT_SEARCH_QUERY[] = "https://www.youtube.com/results?search_query=";
const char THE_DRAFT_PATH[] = "draft_notes_folder/";
const char THE_DRAFT_POSTFIX[] = "_draft_notes_";

int main(){

printf("Program start successful\n");
printf("Type \"help\" for the command list\n");
printf("Make sure you read the manual for a good experience\n");
mainMenu();

return 0;
}

void mainMenu()
{
    char command[100];
    printf("\nYou are in the main menu\n");
    printf("Enter a command: ");
    return commandInputHandler(command);
}

void commandInputHandler(char command[100])
{
    scanf("%s", command);
    if (strcmp(command, "search") == 0)
    {
        search();
        return;
    }
    else if (strcmp(command, "help") == 0)
    {
        helpCommand();
        return;
    }
    else if (strcmp(command, "quit") == 0)
    {
        printf("\nExiting program\n");
        return;
    }
    else if (strcmp(command, "createrepo") == 0)
    {
        createRepo();
        return;
    }
    else if (strcmp(command, "draft") == 0)
    {
        draftSearch();
        return;
    }
    else
    {
        printf("\nNot a known command! Type \"help\" to see the command list!\n");
        mainMenu();
        return;
    }
}

void helpCommand()
{
    printf("\"createrepo\" \n");
    printf("\"search\" \n");
    printf("\"back\"\n");
    printf("\"quit\"\n");
    mainMenu();
    return;
}

void search()
{
    char champToSearch[20];
    
    printf("\nType the name of the champion: ");
    scanf("%s", champToSearch);
    quitCheck(champToSearch);
    
    if (strcmp(champToSearch, "back") == 0)
    {
        mainMenu();
        return;
    }

    char helperSearchPath[50];
    char trueSearchPath[100];
    snprintf(helperSearchPath, 50, "%s%s", THE_MAIN_PATH, champToSearch);
    snprintf(trueSearchPath, 100, "%s%s", helperSearchPath, THE_NOTES_POSTFIX);
    printf("%s\n", trueSearchPath);
    DIR *directorypointerSearch;
    struct dirent *entry;
    directorypointerSearch = opendir(trueSearchPath);
        if (directorypointerSearch == NULL) 
        {
            printf("\nCannot open the directory!\n");
            mainMenu();
            return;
        }

        if (directorypointerSearch != NULL)
        {
            enemyNotesSearch(trueSearchPath, champToSearch);
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

void enemyNotesSearch(const char *trueSearchPath, const char *champToSearch)
{
            
    char enemyName[50];
    char helperEnemySearchPath[200];
    char noPostfixEnemySearchPath[250];
    char trueEnemySearchPath[300];
    printf("\nType the name of the enemy champion: ");
    scanf("%s", enemyName);
    quitCheck(enemyName);
    
    snprintf(helperEnemySearchPath, 200, "%s%s%s", trueSearchPath, champToSearch, UNDERSCOREVSUNDERSCORE);
    snprintf(noPostfixEnemySearchPath, 250, "%s%s", helperEnemySearchPath, enemyName);
    snprintf(trueEnemySearchPath, 300, "%s%s", noPostfixEnemySearchPath, THE_TXT_POSTFIX);
    printf("\n%s\n", trueEnemySearchPath);
            
    fileSearchHandler(trueEnemySearchPath, champToSearch, enemyName);
    return;

    //file name format : [champname]_vs_[enemychampname].txt            
}

void fileSearchHandler(const char *enemy_path, const char *championToSearch, const char *enemyToSearch)
{
   
    
    char toDisplayOrToOpen[10];
    printf("Do you want to display the contents, open the file, or search a VOD on Youtube? [d/o/s]?: ");
    scanf("%s", toDisplayOrToOpen);
    quitCheck(toDisplayOrToOpen);

    if (strcmp(toDisplayOrToOpen, "back") == 0)
    {
        search();
        return;
    }

    else if(strcmp(toDisplayOrToOpen, "d") == 0)
    {   
        fileDisplay(enemy_path);
    } 
    
    else if (strcmp(toDisplayOrToOpen, "o") == 0)
    {
        
        fileOpen(enemy_path);
        
    }
    
    else if(strcmp(toDisplayOrToOpen, "s") == 0)
    {
        
        youtubeSearchHandler(championToSearch, enemyToSearch);
    }
       
    search();
    return;
}

void fileOpen(const char *enemy_path)
{
    
    char fullFilePathToOpen[200];

    snprintf(fullFilePathToOpen, 200, "xdg-open %s", enemy_path);
    printf("%s\n", fullFilePathToOpen);
    int fileOpenStatus = system(fullFilePathToOpen);

    if (fileOpenStatus == -1)
        perror("\nError executing the command!\n");
    else if (fileOpenStatus != 0)
    {
        printf("\nCommand failed with exit status %d\n", fileOpenStatus);
        return;
    }
   
}

void youtubeSearchHandler(const char *championToSearch, const char *enemyToSearch)
{
    
    {
        char youtubeSearchPath[100];
        snprintf(youtubeSearchPath, 100, "%s%s%s%s%s%s", "xdg-open ", YT_SEARCH_QUERY, championToSearch, "+vs+", enemyToSearch, "+challenger+grandmaster");
        int ytSearchStatus = system(youtubeSearchPath);
        freopen("/dev/null", "w", stderr);

        if (ytSearchStatus == -1)
            perror("\nError executing the command!\n");
        else if (ytSearchStatus != 0)
        {
            printf("\nCommand failed with exit status %d\n", ytSearchStatus);
            exit(0);
        }
    }
    
}

void draftSearch()
{
   printf("\nType the name of a champion you want to look up draft notes for: ");
    
    char championToDraft[50];
    char helperDraftPathForDisplayingAllNotes[200];
    char fullDraftPath[200];
    char draftModeInput[50];
    char draftDisplayOrOpen[50] ;
    char draftMode[50];

    scanf("%s", championToDraft);
    quitCheck(championToDraft);
    
    printf("\nDo you want to seach for ally or enemy draft notes? [a/e]: ");
    scanf("%s", draftModeInput);
    quitCheck(draftModeInput);

    //path template: draft_notes_folder/[champion]_draft_notes_[side].txt
    if (strcmp(draftModeInput, "a") == 0)
        snprintf(draftMode, 50, "%s", "ally");
    else if (strcmp(draftModeInput, "e") == 0)
        snprintf(draftMode, 50, "%s", "enemy");
    else if (strcmp(draftModeInput, "all") == 0)
    {
        
        printf("\nDo you want to display the notes or open the file?[d/o]: ");
        scanf("%s", draftDisplayOrOpen);
        if(strcmp(draftDisplayOrOpen, "d") == 0)
        {
            snprintf(fullDraftPath, 200, "%s%s%s%s%s", THE_DRAFT_PATH, championToDraft, THE_DRAFT_POSTFIX, "ally", THE_TXT_POSTFIX);
            printf("\nDisplaying %s ally notes:\n\n", championToDraft);
            fileDisplay(fullDraftPath);
            snprintf(helperDraftPathForDisplayingAllNotes, 200, "%s%s%s%s%s", THE_DRAFT_PATH, championToDraft, THE_DRAFT_POSTFIX, "enemy", THE_TXT_POSTFIX);
            printf("\nDisplaying %s enemy notes:\n\n", championToDraft);
            fileDisplay(helperDraftPathForDisplayingAllNotes);
            draftSearch();
            return;
        }
    if(strcmp(draftDisplayOrOpen, "o") == 0)    
        {
            snprintf(fullDraftPath, 200, "%s%s%s%s%s", THE_DRAFT_PATH, championToDraft, THE_DRAFT_POSTFIX, "ally", THE_TXT_POSTFIX);
            fileOpen(fullDraftPath);
            snprintf(helperDraftPathForDisplayingAllNotes, 200, "%s%s%s%s%s", THE_DRAFT_PATH, championToDraft, THE_DRAFT_POSTFIX, "enemy", THE_TXT_POSTFIX);
            fileOpen(helperDraftPathForDisplayingAllNotes);
            draftSearch();
            return;
        }
        
    }
        
    else 
        {
            printf("\nError: incorrect ally/enemy input\n");
            return;
        }

    snprintf(fullDraftPath, 200, "%s%s%s%s%s", THE_DRAFT_PATH, championToDraft, THE_DRAFT_POSTFIX, draftMode, THE_TXT_POSTFIX);
    printf("%s\n\n", fullDraftPath);
    
    printf("\nDo you want to display the notes or open the file?[d/o]: ");
    scanf("%s", draftDisplayOrOpen);

    if(strcmp(draftDisplayOrOpen, "d") == 0)
        fileDisplay(fullDraftPath);
    if(strcmp(draftDisplayOrOpen, "o") == 0)    
        fileOpen(fullDraftPath);
    
    draftSearch();
    return;
}

void quitCheck(const char* isQuit)
{
    
    if (strcmp(isQuit, "quit") == 0)
    {
        printf("\nExiting program\n");
        exit(0);
    }
   
}

void fileDisplay(const char* pathToDisplay)
{
    FILE *readerPointer;
    char fileReader[10000];
    readerPointer = fopen(pathToDisplay, "r");
    if (readerPointer == NULL)
        {
            perror("\nError opening file");
            return;
        }
    while(fgets(fileReader, 10000, readerPointer) != NULL)
        {
            printf("%s", fileReader);
        }
    
      return;
}