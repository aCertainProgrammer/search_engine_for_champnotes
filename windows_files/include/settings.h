#ifndef SETTINGS_H
#define SETTINGS_H

struct settingsTable {
    int welcomeScreenFlavorText;
    int mainMenuFlavorText;
    int draftSearchFlavorText;
    int championNotesSearchFlavorText;
    int fileOpenFlavorText;
    int quitCheckFlavorText;
    int draftSearchDisplayFormatting;
};

extern struct settingsTable settings;

void settingsLoader();
int findSettingsValue(const char *settingToFind);

#endif
