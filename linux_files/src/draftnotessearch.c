#include "draftnotessearch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputhandling.h"
#include "menu.h"
#include "settings.h"
#include "validation.h"


void draftSearch(char * champion_to_draft, char * which_notes_to_display, char * draft_mode_input)
{
  char * draft_path = malloc(200 * sizeof(char));
  char * draft_mode = NULL;

  memoryCheck(draft_path);

  draftModeChecker(draft_mode_input, &draft_mode);
  printf("\n%s\n", draft_mode);
  
  free(draft_path);
  free(draft_mode);
  mainMenu();
  return;
}

void draftSearchInputReceiver()
{
  char * champion_to_draft_input = NULL;
  char * which_notes_to_display_input = NULL;
  char * draft_mode_input = NULL;

  if (settings.draftSearchFlavorText == 1) {
    printf("\nChampion to draft search: ");
  }
  
  userStringInput(&champion_to_draft_input);
  quitCheck(champion_to_draft_input);
  if (backCheck(champion_to_draft_input) == 1) {
    free(champion_to_draft_input);
    mainMenu();
    return;
  }
 
  if (settings.draftSearchFlavorText == 1) {
    printf("\nAlly, enemy or both draft notes [a/e/b]: "); 
  }
  userStringInput(&which_notes_to_display_input);
  quitCheck(which_notes_to_display_input);
  if (backCheck(which_notes_to_display_input) == 1) {
    free(which_notes_to_display_input);
    free(champion_to_draft_input);
    mainMenu();
    return;
  }

  if (settings.draftSearchFlavorText == 1) {
    printf("\nDo you want to display or open the notes [d/o]: ");
  }
  userStringInput(&draft_mode_input);
  quitCheck(draft_mode_input);
  if (backCheck(draft_mode_input) == 1) {
    free(draft_mode_input);
    free(which_notes_to_display_input);
    free(champion_to_draft_input);
    mainMenu();
    return;
  }
  draftSearch(champion_to_draft_input, which_notes_to_display_input, draft_mode_input);
  free(draft_mode_input);
  free(which_notes_to_display_input);
  free(champion_to_draft_input);
  mainMenu();
  return;
 
}

void draftModeChecker(char * draft_mode_input_to_check, char ** draft_mode_to_change)
{
  if (*draft_mode_to_change != NULL) {
    free(*draft_mode_to_change);
    *draft_mode_to_change = NULL;
  }

  *draft_mode_to_change = malloc(sizeof(char) * 10);
  memoryCheck(*draft_mode_to_change);

  if (strcmp(draft_mode_input_to_check, "a") == 0) {
    strcpy(*draft_mode_to_change, "ally"); 
  }
  else if (strcmp(draft_mode_input_to_check, "e") == 0) {
    strcpy(*draft_mode_to_change, "enemy");
  }
  else if (strcmp(draft_mode_input_to_check, "b") == 0) {
    strcpy(*draft_mode_to_change, "both");
  }

  return;
}
