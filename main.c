#include <stdio.h>
#include <stdlib.h>

void mainMenu();
void fileSystemCheck();

int main(){


printf("If this fails, submit a ticket on Github, at https://github.com/Rycerzklanu/search_engine_for_champnotes\n");

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
        }
}
