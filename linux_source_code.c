#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void mainMenu();
void fileSystemCheck();
void search();
void helpCommand();
void enemyFileSearchHandler(const char *enemy_path);
const int CURRENT_CHAMPION_AMOUNT = 166;

const char THE_MAIN_PATH[] = "main_notes_folder/";
const char THE_NOTES_POSTFIX[] = "_notes/";
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
        directorypointerFileSystemCheck = opendir("/main_notes_folder");
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
            perror("Error opening file");
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
        
        snprintf(fullFilePathToOpen, 200, "xdg-open %s", enemy_path);

        int fileOpenStatus = system(fullFilePathToOpen);

        if (fileOpenStatus == -1)
            perror("Error executing the command!\n");
        else if (fileOpenStatus != 0)
        {
            printf("Command failed with exit status %d\n", fileOpenStatus);
            return;
        }
    }

    search();
    return;

}
