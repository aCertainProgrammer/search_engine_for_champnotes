#include "draftnotessearch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputhandling.h"
#include "menu.h"
#include "settings.h"
#include "validation.h"
#include "constants.h"
#include "fileoperations.h"

void draftSearchManager(char * champion_to_draft, char * which_notes_to_display, char * draft_mode_input)
{
  char * draft_path = malloc(200 * sizeof(char));
  memoryCheck(draft_path);


  
  if (strcmp(which_notes_to_display, "e") == 0 || strcmp(which_notes_to_display, "a") == 0) {
    strcpy(draft_path, draftSearchPathMaker(which_notes_to_display, champion_to_draft));
    draftFileOpenOrDisplayManager(draft_path, draft_mode_input);
    printf("\n%s\n",draft_path);
  }
  else if (strcmp(draft_mode_input, "b") == 0) {
    printf("\ngew\n"); 
  }
   
  free(draft_path);
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
  draftSearchManager(champion_to_draft_input, which_notes_to_display_input, draft_mode_input);
  free(draft_mode_input);
  free(which_notes_to_display_input);
  free(champion_to_draft_input);
  mainMenu();
  return;
 
}

char * draftWhichNotesChecker(char * which_notes_to_display_input_to_check)
{
  char * string_to_return = malloc(sizeof(char)* 10);
  memoryCheck(string_to_return);

  if (strcmp(which_notes_to_display_input_to_check, "a") == 0) {
    strcpy(string_to_return, "ally");
    return string_to_return;
  }
  else if (strcmp(which_notes_to_display_input_to_check, "e") == 0) {
    strcpy(string_to_return, "enemy");
    return string_to_return;
  }
  else if (strcmp(which_notes_to_display_input_to_check, "b") == 0) {
    strcpy(string_to_return, "both");
    return string_to_return;
  }
  else {
    strcpy(string_to_return, "badinput");
    return string_to_return;
  }
}

char * draftSearchPathMaker(char * which_notes_to_display, char * champion_to_draft){

  char * draft_path_to_return = malloc(sizeof(char)* 200);
  memoryCheck(draft_path_to_return);

  if (strcmp(which_notes_to_display, "a") == 0) {
    snprintf(draft_path_to_return, 200, "%s%s%s%s%s", THE_DRAFT_PATH, champion_to_draft, THE_DRAFT_POSTFIX, "ally",THE_TXT_POSTFIX); 
  }
  else if (strcmp(which_notes_to_display, "e") == 0) {
    snprintf(draft_path_to_return, 200, "%s%s%s%s%s", THE_DRAFT_PATH, champion_to_draft, THE_DRAFT_POSTFIX, "enemy",THE_TXT_POSTFIX); 
  }
  printf("\ndebug path in the maker: %s\n", draft_path_to_return);
  return draft_path_to_return;
}

void draftFileOpenOrDisplayManager(char * draft_path_to_manage, char * draft_mode_to_manage){

  if (strcmp(draft_mode_to_manage, "d") == 0) {
    fileDisplay(draft_path_to_manage);
    return;
 } 
  else if (strcmp(draft_mode_to_manage, "o") == 0) {
    fileOpen(draft_path_to_manage);
    return;
  }
}
