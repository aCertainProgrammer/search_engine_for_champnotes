#include "inputhandling.h"
#include "validation.h"
#include <stdlib.h>
#include <stdio.h>
void userStringInput(char **inputString)
{
    
    if (*inputString != NULL) {
        free(*inputString);
        *inputString = NULL;
    }
    
    *inputString = malloc(50 * sizeof(char));
    if (*inputString == NULL)
    {
        memoryFail();
    }
    scanf("%49s", *inputString);
}
