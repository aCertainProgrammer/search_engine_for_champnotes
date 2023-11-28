/* #include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <windows.h>

void mainMenu();
void fileSystemCheck();
void search();
void helpCommand();
void enemyFileSearchHandler(const char *enemy_path);
const int CURRENT_CHAMPION_AMOUNT = 166;

const char THE_MAIN_PATH[] = "main_notes_folder\\";
const char THE_NOTES_POSTFIX[] = "_notes\\";
const char THE_TXT_POSTFIX[] = ".txt";
const char UNDERSCOREVSUNDERSCORE[] = "_vs_";

int main(){

printf("Program start successful\n");
printf("Type \"help\" for the command list\n");
mainMenu();

return 0;
}

void fileSystemCheck()
{
FILE *filepointer;
filepointer = fopen("champ_list.txt", "r");
    
    if (filepointer == NULL)
    {
        printf("Failed to open the champ_list file!\n");
        printf("Check if the file is in the program's directory.\n");
        printf("If not, run the createChampList command in the main menu.\n");
        printf("If it is in the directory, reopen the program and try again.\n");
        printf("If this fails, submit a ticket on Github, at https://github.com/Rycerzklanu/search_engine_for_champnotes");

        mainMenu();
        return;
    }
    if (filepointer != NULL)
    {
        printf("Opened the champ_list file successfully...\n");
        char champToCheck[50];
        char helperCheckPath[300];
        char trueCheckPath[400];
        FILE *champnotespointer; 
        DIR *directorypointerFileSystemCheck;
        struct dirent *entry;
        directorypointerFileSystemCheck = opendir("\\main_notes_folder");
        if (directorypointerFileSystemCheck == NULL) 
        {
            printf("Cannot open the main_notes_folder directory!\n");
            mainMenu();
            return;
        }

        if (directorypointerFileSystemCheck != NULL)
        {
            while((entry = readdir(directorypointerFileSystemCheck)) != NULL)
            {
                fgets(champToCheck, 50, filepointer);
                //the quit function functionality
                if (strcmp(champToCheck, "quit") == 0)
                {
                    printf("Exiting program\n");
                    return;
                }
 
                else if (strcmp(champToCheck, "back") == 0)
                {
                    mainMenu();
                    return;
                }
                snprintf(helperCheckPath, 300, "%s%s", THE_MAIN_PATH, champToCheck);
                snprintf(trueCheckPath, 400, "%s%s", helperCheckPath, THE_NOTES_POSTFIX);
                printf("%s\n", trueCheckPath);


    
        
            }
            mainMenu();
            return;
        }
        

    }
    

}

void mainMenu()
{
    char command[100];
    printf("You are in the main menu\n");
    printf("Enter a command:\n");
    scanf("%s", command);
    if (strcmp(command, "search") == 0)
    {
        search();
        return;
    }    
    else if (strcmp(command, "check") == 0)
    {
        fileSystemCheck();
        return;
    }
    else if (strcmp(command, "help") == 0)
    { 
        helpCommand();
        return;
    }
    else if (strcmp(command, "quit") == 0)
    {
        printf("Exiting program\n");
        return;
    }
    else 
    {
        printf("Not a known command! Type \"help\" to see the command list!\n");
        mainMenu();
        return;
    }
}
void search()
{
    char champToSearch[20];
    
    printf("Type the name of the champion\n");
    scanf("%s", champToSearch);
    if (strcmp(champToSearch, "quit") == 0)
    {
        printf("Exiting program\n");
        return;
    }
    
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
            printf("Cannot open the directory!\n");
            mainMenu();
            return;
        }

        if (directorypointerSearch != NULL)
        {
            
            char enemyName[50];
            char helperEnemySearchPath[200];
            char noPostfixEnemySearchPath[250];
            char trueEnemySearchPath[300];
            printf("Directory opened successfully\n");
            printf("Type the name of the enemy champion:\n");
            scanf("%s", enemyName);
            if (strcmp(enemyName, "quit") == 0)
            {
                printf("Exiting program\n");
                return;
            }
            snprintf(helperEnemySearchPath, 200, "%s%s%s", trueSearchPath, champToSearch, UNDERSCOREVSUNDERSCORE);
            snprintf(noPostfixEnemySearchPath, 250, "%s%s", helperEnemySearchPath, enemyName);
            snprintf(trueEnemySearchPath, 300, "%s%s", noPostfixEnemySearchPath, THE_TXT_POSTFIX);
            printf("%s\n", trueEnemySearchPath);
            
            enemyFileSearchHandler(trueEnemySearchPath);
            return;

            //file name format : [champname]_vs_[enemychampname].txt            
        }
    
}

void helpCommand()
{
    printf("\"champsearch\" \n");
    printf("\"fullsearch\" \n");
    printf("\"search\"\n");
    mainMenu();
    return;
}


void enemyFileSearchHandler(const char *enemy_path)
{
    FILE *enemypointer;
    
    char toDisplayOrToOpen[10];
    char enemyFileReader[10000];
    printf("Do you want to display the contents or open the file in the default editor [d/o]?\n");
    scanf("%9s", toDisplayOrToOpen);
    if (strcmp(toDisplayOrToOpen, "quit") == 0)
    {
        printf("Exiting program\n");
        return;
    }
    else if (strcmp(toDisplayOrToOpen, "back") == 0)
    {
        search();
        return;
    }

    else if(strcmp(toDisplayOrToOpen, "d") == 0)
    {   
        
        enemypointer = fopen(enemy_path, "r");
        if (enemypointer == NULL)
        {
            perror("Error opening file\n");
            exit(EXIT_FAILURE);
        }
        while(fgets(enemyFileReader, 10000, enemypointer) != NULL)
        {
            printf("%s", enemyFileReader);
        }
        printf("Search successful, returning to the search menu\n");
        search();
        return;
    } 
    
    else if (strcmp(toDisplayOrToOpen, "o") == 0)
    {
        char fullFilePathToOpen[200];
        
        
	HINSTANCE result = ShellExecute(NULL, "open", enemy_path, NULL, NULL, SW_SHOWNORMAL);

	if ((intptr_t)result <= 32)
	{
		perror("Error opening file \n");
		exit(EXIT_FAILURE);
	}
   }


    search();
    return;

}
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <windows.h>

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
const char THE_MAIN_PATH[] = "main_notes_folder\\";
const char THE_NOTES_POSTFIX[] = "_notes\\";
const char THE_TXT_POSTFIX[] = ".txt";
const char UNDERSCOREVSUNDERSCORE[] = "_vs_";
const char YT_SEARCH_QUERY[] = "https://www.youtube.com/results?search_query=";
const char THE_DRAFT_PATH[] = "draft_notes_folder\\";
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
        quitCheck(command);
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
    int status = system("scripts\\createRepoWindows.bat");
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
    
    HINSTANCE result = ShellExecute(NULL, "open", enemy_path, NULL, NULL, SW_SHOWNORMAL);
    if ((intptr_t)result <= 32)
	{
		perror("Error opening file \n");
		exit(EXIT_FAILURE);
    }
}

void youtubeSearchHandler(const char *championToSearch, const char *enemyToSearch)
{
    
    {
        char youtubeSearchPath[100];
        snprintf(youtubeSearchPath, 100, "%s%s%s%s%s", YT_SEARCH_QUERY, championToSearch, "+vs+", enemyToSearch, "+challenger+grandmaster");
        ShellExecute(NULL, "open", youtubeSearchPath, NULL, NULL, SW_SHOWNORMAL);
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
    
    printf("\nDo you want to seach for ally, enemy or all draft notes? [a/e/all]: ");
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