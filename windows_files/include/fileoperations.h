#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H


void fileDisplay(const char *pathToDisplay);
void fileOpen(const char *enemy_path);
void youtubeSearchHandler(const char *championToSearch, const char *enemyToSearch);
void createRepo();
void NotesChampionFolderSearch();
void enemyNotesSearch(const char *trueSearchPath, const char *champToSearch);
char* notesSearchPathMaker(const char *firstChampionToSearch);
void fileSearchHandler(const char *enemy_path, const char *championToSearch, const char *enemyToSearch);


#endif