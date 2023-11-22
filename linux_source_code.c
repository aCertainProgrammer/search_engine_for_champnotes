#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void mainMenu();
void fileSystemCheck();
void search();
void helpCommand();

const int CURRENT_CHAMPION_AMOUNT = 166;

const char THE_MAIN_PATH[] = "main_notes_folder/";
const char THE_NOTES_POSTFIX[] = "_notes/";
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
    }
    if (filepointer != NULL)
    {
        printf("Opened the champ_list file successfully...\n");
        char champName[50];
        int champ_counter = 0;
        DIR *directorypointerFileSystemCheck;
        struct dirent *entry;
        directorypointerFileSystemCheck = opendir("/main_notes_folder");
        if (directorypointerFileSystemCheck == NULL) 
        {
            printf("Cannot open the main_notes_folder directory!\n");
            mainMenu();
        }

        if (directorypointerFileSystemCheck != NULL)
        {
            while((entry = readdir(directorypointerFileSystemCheck)) != NULL)
            {
                break; //iterating through the directory and files will be added here
            }
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
    else 
    {
        printf("Not a known command! Type \"help\" to see the command list!\n");
    }
}
void search()
{
    char champToSearch[90]; 
    printf("Type the name of the champion\n");
    scanf("%s", champToSearch);
    char helperSearchPath[300];
    char trueSearchPath[400];
    snprintf(helperSearchPath, 300, "%s%s", THE_MAIN_PATH, champToSearch);
    snprintf(trueSearchPath, 400, "%s%s", helperSearchPath, THE_NOTES_POSTFIX);
    printf("%s\n", trueSearchPath);
    DIR *directorypointerSearch;
    struct dirent *entry;
    directorypointerSearch = opendir(trueSearchPath);
        if (directorypointerSearch == NULL) 
        {
            printf("Cannot open the directory!\n");
            mainMenu();
        }

        if (directorypointerSearch != NULL)
        {
            printf("Directory opened successfully\n");
            while((entry = readdir(directorypointerSearch)) != NULL)
            {
                break; //iterating through the directory and files will be added here
            }
        }
    
}

void helpCommand()
{
    printf("\"champsearch\" \n");
    printf("\"fullsearch\" \n");
    printf("\"search\"\n");
    mainMenu();
}
