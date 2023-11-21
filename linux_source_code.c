#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void mainMenu();
void fileSystemCheck();
void search();
void helpCommand();

const int CURRENT_CHAMPION_AMOUNT = 166;
int main(){

printf("Program start successfull\n");
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
        DIR *directorypointer;
        struct dirent *entry;
        directorypointer = opendir("/main_notes_folder");
        if (directorypointer == NULL) 
        {
            printf("Cannot open the main_notes_folder directory!\n");
            mainMenu();
        }

        if (directorypointer != NULL)
        {
            while((entry = readdir(directorypointer)) != NULL)
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
    if (command == "search")
        search();
    if (command == "check")
        fileSystemCheck();
    if (strcmp(command, "help") == 0)
        helpCommand();
    printf("Not a known command! Type \"help\" to see the command list!\n");
}
void search()
{
    printf("Type the name of the champion\n");
}

void helpCommand()
{
    printf("\"champsearch\" \n");
    printf("\"fullsearch\" \n");
    mainMenu();
}
