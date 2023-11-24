#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void mainMenu();
void fileSystemCheck();
void search();
void helpCommand();
void enemyFileSearchHandler(const char *enemy_path, const char *championToSearch, const char *enemyToSearch);
void createRepo();
const int CURRENT_CHAMPION_AMOUNT = 166;

const char THE_MAIN_PATH[] = "main_notes_folder/";
const char THE_NOTES_POSTFIX[] = "_notes/";
const char THE_TXT_POSTFIX[] = ".txt";
const char UNDERSCOREVSUNDERSCORE[] = "_vs_";
const char YT_SEARCH_QUERY[] = "https://www.youtube.com/results?search_query=";

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
    else 
    {
        printf("\nNot a known command! Type \"help\" to see the command list!\n");
        mainMenu();
        return;
    }
}
void search()
{
    char champToSearch[20];
    
    printf("Type the name of the champion: ");
    scanf("%s", champToSearch);
    if (strcmp(champToSearch, "quit") == 0)
    {
        printf("\nExiting program\n");
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
            printf("\nCannot open the directory!\n");
            mainMenu();
            return;
        }

        if (directorypointerSearch != NULL)
        {
            
            char enemyName[50];
            char helperEnemySearchPath[200];
            char noPostfixEnemySearchPath[250];
            char trueEnemySearchPath[300];
            printf("\nType the name of the enemy champion: ");
            scanf("%s", enemyName);
            if (strcmp(enemyName, "quit") == 0)
            {
                printf("\nExiting program\n");
                return;
            }
            snprintf(helperEnemySearchPath, 200, "%s%s%s", trueSearchPath, champToSearch, UNDERSCOREVSUNDERSCORE);
            snprintf(noPostfixEnemySearchPath, 250, "%s%s", helperEnemySearchPath, enemyName);
            snprintf(trueEnemySearchPath, 300, "%s%s", noPostfixEnemySearchPath, THE_TXT_POSTFIX);
            printf("\n%s\n", trueEnemySearchPath);
            
            enemyFileSearchHandler(trueEnemySearchPath, champToSearch, enemyName);
            return;

            //file name format : [champname]_vs_[enemychampname].txt            
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


void enemyFileSearchHandler(const char *enemy_path, const char *championToSearch, const char *enemyToSearch)
{
    FILE *enemypointer;
    
    char toDisplayOrToOpen[10];
    char enemyFileReader[10000];
    printf("Do you want to display the contents, open the file, or search a VOD on Youtube? [d/o/s]? ");
    scanf("%9s", toDisplayOrToOpen);
    if (strcmp(toDisplayOrToOpen, "quit") == 0)
    {
        printf("\nExiting program\n");
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
            perror("\nError opening file");
            exit(EXIT_FAILURE);
        }
        while(fgets(enemyFileReader, 10000, enemypointer) != NULL)
        {
            printf("%s", enemyFileReader);
        }
        printf("\nSearch successful, returning to the search menu\n");
        search();
        return;
    } 
    
    else if (strcmp(toDisplayOrToOpen, "o") == 0)
    {
        char fullFilePathToOpen[200];
        
        snprintf(fullFilePathToOpen, 200, "xdg-open %s", enemy_path);

        int fileOpenStatus = system(fullFilePathToOpen);

        if (fileOpenStatus == -1)
            perror("\nError executing the command!\n");
        else if (fileOpenStatus != 0)
        {
            printf("\nCommand failed with exit status %d\n", fileOpenStatus);
            return;
        }
    }
    
    else if(strcmp(toDisplayOrToOpen, "s") == 0)
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
            return;
        }

    }
    search();
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
