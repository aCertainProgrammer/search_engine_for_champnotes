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

void quitCheck(const char* isQuit)
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

