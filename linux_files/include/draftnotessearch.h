
#ifndef DRAFTNOTESSEARCH_H
#define DRAFTNOTESSEARCH_H

void draftSearchManager(char * champion_to_draft, char * enemy_to_draft, char * draft_mode_input);

void draftFileOpenOrDisplayManager(char * draft_path_to_manage, char * draft_mode_to_manage);
char * draftSearchPathMaker(char * which_notes_to_display, char * champion_to_draft);
void draftSearchInputReceiver();
char * draftWhichNotesChecker(char * which_notes_to_display_input_to_check);
#endif 
