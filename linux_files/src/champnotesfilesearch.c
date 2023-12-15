#include "constants.h"
#include "fileoperations.h"
#include "validation.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "settings.h"
#include "champnotesfilesearch.h"
#include "menu.h"
#include "inputhandling.h"

void championNotesSearch(char * champion_to_search, char * enemy_to_search, char * notes_opening_mode)
{ //path template: main_notes_folder/[champion]_notes/[champion]_vs_[enemy].txt 
  
  char * search_path = malloc(sizeof(char) * 200);
  if (search_path == NULL) {
  memoryFail();
  }
  snprintf(search_path, 200,"%s%s%s%s%s%s%s", THE_MAIN_PATH, champion_to_search, THE_NOTES_POSTFIX, champion_to_search, "_vs_", enemy_to_search, THE_TXT_POSTFIX);
  printf("\n%s\n", search_path);
  
  if (strcmp(notes_opening_mode, "d") == 0) {
    fileDisplay(search_path);
    free(search_path);
    championNotesSearchInputReceiver();
    return;
  }
  else if (strcmp(notes_opening_mode, "o") == 0) {
    fileOpen(search_path);
    free(search_path);
    championNotesSearchInputReceiver();
    return;
  }
  else if (strcmp(notes_opening_mode, "s") == 0) {
    youtubeSearchHandler(champion_to_search, enemy_to_search);
    free(search_path);
    championNotesSearchInputReceiver();
    return;
  }
}
void championNotesSearchInputReceiver()
{
  char * champion_to_search_input = NULL;
  char * enemy_to_search_input = NULL;
  char * notes_opening_mode_input = NULL;

  if (settings.championNotesSearchFlavorText == 1){
    printf("\nChampion to search: ");
  } 
  userStringInput(&champion_to_search_input);
  quitCheck(champion_to_search_input);
  if (backCheck(champion_to_search_input) == 1) {
    free(champion_to_search_input);
    mainMenu();
    return;
  }
  if (settings.championNotesSearchFlavorText) {
    
    printf("\nEnemy to search: ");
  }
  userStringInput(&enemy_to_search_input);
  quitCheck(enemy_to_search_input);
  if (backCheck(enemy_to_search_input) == 1) {
    free(enemy_to_search_input);
    free(champion_to_search_input);
    mainMenu();
    return;
  }
 
  if (settings.championNotesSearchFlavorText == 1) {
  printf("\nDO you want to display the file, open it, or look up a VOD on YouTube?[d/o/s]: ");
  }
  userStringInput(&notes_opening_mode_input);
  quitCheck(notes_opening_mode_input);
  if (backCheck(notes_opening_mode_input) == 1) {
    free(notes_opening_mode_input);
    free(champion_to_search_input);
    free(enemy_to_search_input);
    mainMenu();
    return;
  }
  championNotesSearch(champion_to_search_input, enemy_to_search_input, notes_opening_mode_input);
  free(champion_to_search_input);
  free(enemy_to_search_input);
  free(notes_opening_mode_input);
  return;
}
