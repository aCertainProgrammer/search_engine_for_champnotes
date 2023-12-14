#include "constants.h"
#include "validation.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <inputhandling.h>
#include "settings.h"

void championNotesSearch(char * champion_to_search, char * enemy_to_search, char * notes_opening_mode)
{ //path template: main_notes_folder/[champion]_notes/[champion]_vs_[enemy].txt 
  
  char * folder_path = malloc(sizeof(char) * 256);
  if (folder_path == NULL) {
  memoryFail();
  }
  snprintf(folder_path, 256,"%s%s%s%s%s%s%s%s","xdg-open ", THE_MAIN_PATH, champion_to_search, THE_NOTES_POSTFIX, champion_to_search, "_vs_", enemy_to_search, THE_TXT_POSTFIX);
  printf("\n%s\n", folder_path);

  int system_status_check = system(folder_path);
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

  if (settings.championNotesSearchFlavorText) {
    
    printf("\nEnemy to search: ");
  }
  userStringInput(&enemy_to_search_input);

  if (settings.championNotesSearchFlavorText == 1) {
  printf("\nDO you want to display the file, open it, or look up a VOD on YouTube?[d/o/s]: ");
  }
  userStringInput(&notes_opening_mode_input);
  championNotesSearch(champion_to_search_input, enemy_to_search_input, notes_opening_mode_input);
  free(champion_to_search_input);
  free(enemy_to_search_input);
  free(notes_opening_mode_input);
  return;
}
