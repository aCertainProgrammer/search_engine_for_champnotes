#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "validation.h"
#include "settings.h"

void memoryFail()
{
    printf("Memory failure!\nAborting\n");
    exit(EXIT_FAILURE);
}

void quitCheck(char* isQuit)
{
    
    if (strcmp(isQuit, "quit") == 0)
    {   
        if (settings.quitCheckFlavorText == 1)
        {
            printf("\nExiting program\n");
        }

        exit(0);
    }
   
}

int backCheck(char * isBack)
{
    if (strcmp(isBack, "back") == 0)
      return 1;
    else 
      return 0;
}

void memoryCheck(void * variable_to_check)
{
    if (variable_to_check == NULL) {
      memoryFail();
    }
    else {
      return;
    }
}
