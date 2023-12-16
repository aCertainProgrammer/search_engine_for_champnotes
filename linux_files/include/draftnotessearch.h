
#ifndef DRAFTNOTESSEARCH_H
#define DRAFTNOTESSEARCH_H

void draftSearch(char * champion_to_draft, char * enemy_to_draft, char * draft_mode_input);

void draftSearchInputReceiver();
void draftModeChecker(char * draft_mode_input_to_check, char ** draft_mode_to_change);
#endif 
