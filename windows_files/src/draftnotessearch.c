#include "draftnotessearch.h"
#include "main.h"
#include "settings.h"
#include "constants.h"
#include "menu.h"
#include "validation.h"
#include "inputhandling.h"
#include "fileoperations.h"


void draftSearch() {
    if (settings.draftSearchFlavorText == 1) {
        printf("\nType the name of a champion you want to look up draft notes for: ");
    }

    char *championToDraft = NULL;
    userStringInput(&championToDraft);

    if (championToDraft == NULL) memoryFail();
    quitCheck(championToDraft);

    if (strcmp(championToDraft, "back") == 0) {
        mainMenu();
        free(championToDraft);
        return;
    }

    if (settings.draftSearchFlavorText == 1) {
        printf("\nDo you want to search for ally, enemy, or all draft notes? [a/e/all]: ");
    }

    char *draftModeInput = NULL;
    userStringInput(&draftModeInput);

    if (draftModeInput == NULL) memoryFail();
    quitCheck(draftModeInput);

    if (strcmp(draftModeInput, "back") == 0) {
        mainMenu();
        free(championToDraft);
        free(draftModeInput);
        return;
    }

    draftNotesHandler(championToDraft, draftModeInput);
}

void draftNotesHandler(const char *championToDraft, const char *draftModeInput) {
    char fullDraftPath[200];
    char helperDraftPathForDisplayingAllNotes[200];
    char draftMode[50];

    // path template: draft_notes_folder/[champion]_draft_notes_[side].txt
    if (strcmp(draftModeInput, "a") == 0)
        snprintf(draftMode, 50, "%s", "ally");
    else if (strcmp(draftModeInput, "e") == 0)
        snprintf(draftMode, 50, "%s", "enemy");
    else if (strcmp(draftModeInput, "all") == 0) {
        if (settings.draftSearchFlavorText == 1) {
            printf("\nDo you want to display the notes or open the file? [d/o]: ");
        }

        char *draftDisplayOrOpen = NULL;
        userStringInput(&draftDisplayOrOpen);

        if (draftDisplayOrOpen == NULL) memoryFail();
        quitCheck(draftDisplayOrOpen);

        if (strcmp(draftDisplayOrOpen, "back") == 0) {
            mainMenu();
            free(championToDraft);
            free(draftModeInput);
            free(draftDisplayOrOpen);
            return;
        }

        if (strcmp(draftDisplayOrOpen, "d") == 0) {
            snprintf(fullDraftPath, 200, "%s%s%s%s%s", THE_DRAFT_PATH, championToDraft, THE_DRAFT_POSTFIX, "ally", THE_TXT_POSTFIX);
            if (settings.draftSearchDisplayFormatting == 1) {
                printf("\nDisplaying %s ally notes:\n\n", championToDraft);
            }

            fileDisplay(fullDraftPath);
            snprintf(helperDraftPathForDisplayingAllNotes, 200, "%s%s%s%s%s", THE_DRAFT_PATH, championToDraft,
                     THE_DRAFT_POSTFIX, "enemy", THE_TXT_POSTFIX);

            if (settings.draftSearchDisplayFormatting == 1) {
                printf("\nDisplaying %s enemy notes:\n\n", championToDraft);
            }

            fileDisplay(helperDraftPathForDisplayingAllNotes);
            draftSearch();
            free(championToDraft);
            free(draftModeInput);
            free(draftDisplayOrOpen);
            return;
        }

        if (strcmp(draftDisplayOrOpen, "o") == 0) {
            snprintf(fullDraftPath, 200, "%s%s%s%s%s", THE_DRAFT_PATH, championToDraft, THE_DRAFT_POSTFIX, "ally",
                     THE_TXT_POSTFIX);
            fileOpen(fullDraftPath);
            snprintf(helperDraftPathForDisplayingAllNotes, 200, "%s%s%s%s%s", THE_DRAFT_PATH, championToDraft,
                     THE_DRAFT_POSTFIX, "enemy", THE_TXT_POSTFIX);
            fileOpen(helperDraftPathForDisplayingAllNotes);
            draftSearch();
            free(championToDraft);
            free(draftModeInput);
            free(draftDisplayOrOpen);
            return;
        }
    } else {
        printf("\nError: incorrect ally/enemy input\n");
        free(championToDraft);
        free(draftModeInput);
        return;
    }

    snprintf(fullDraftPath, 200, "%s%s%s%s%s", THE_DRAFT_PATH, championToDraft, THE_DRAFT_POSTFIX, draftMode,
             THE_TXT_POSTFIX);
    printf("%s\n\n", fullDraftPath);

    if (settings.draftSearchFlavorText == 1) {
        printf("\nDo you want to display the notes or open the file? [d/o]: ");
    }

    char *draftDisplayOrOpen = NULL;
    userStringInput(&draftDisplayOrOpen);

    if (draftDisplayOrOpen == NULL) memoryFail();
    quitCheck(draftDisplayOrOpen);

    if (strcmp(draftDisplayOrOpen, "back") == 0) {
        mainMenu();
        free(championToDraft);
        free(draftModeInput);
        free(draftDisplayOrOpen);
        return;
    }

    if (strcmp(draftDisplayOrOpen, "d") == 0)
        fileDisplay(fullDraftPath);
    if (strcmp(draftDisplayOrOpen, "o") == 0)
        fileOpen(fullDraftPath);

    draftSearch();
    free(championToDraft);
    free(draftModeInput);
    free(draftDisplayOrOpen);
}