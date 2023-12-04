#include "main.h"
#include "settings.h"
#include "fileoperations.h"
#include "constants.h"

struct settingsTable settings;

int findSettingsValue(const char *settingToFind) {
    FILE *settingsSearchPointer;
    char settingsFileReader[10000];
    settingsSearchPointer = fopen("settings.txt", "r");
    char settingName[100];
    int settingValue = 1;

    if (settingsSearchPointer == NULL) {
        perror("\nError opening file");
        return -1;
    }

    while (fgets(settingsFileReader, 10000, settingsSearchPointer) != NULL) {
        sscanf(settingsFileReader, "%s = %d", settingName, &settingValue);
        if (strcmp(settingName, settingToFind) == 0) {
            fclose(settingsSearchPointer);
            return settingValue;
        }
    }

    fclose(settingsSearchPointer);
    return -2;
}

void settingsLoader() {
    settings.welcomeScreenFlavorText = findSettingsValue("welcomeScreenFlavorText");
    settings.mainMenuFlavorText = findSettingsValue("mainMenuFlavorText");
    settings.draftSearchFlavorText = findSettingsValue("draftSearchFlavorText");
    settings.championNotesSearchFlavorText = findSettingsValue("championNotesSearchFlavorText");
    settings.fileOpenFlavorText = findSettingsValue("fileOpenFlavorText");
    settings.quitCheckFlavorText = findSettingsValue("quitCheckFlavorText");
    settings.draftSearchDisplayFormatting = findSettingsValue("draftSearchDisplayFormatting");
}

