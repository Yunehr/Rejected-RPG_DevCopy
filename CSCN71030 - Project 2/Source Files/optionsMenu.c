#include "optionsMenu.h"
#include "gameFunctions.h"
#include <stdio.h>
#include <stdlib.h>

// Matthew Romano - CSCN71030_Section2_Group3 - Options Menu Implementation

void optionsMenu() {
	int selection = 0;						// variable for selection
	// dis menu do be basic do
	printf("\n\n1 BACK TO GAME\n\n2 SAVE GAME\n\n3 LOAD GAME\n\n0 MAIN MENU");
	do {
		switch (selection) {
			case 1:
				// nothing to see here
				break;

			case 2:
				// TODO: make file pass into optionsMenu() to pass here, as well as story point
				// saveGame(player);
				break;

			case 3:
				// TODO: either make the file pass here somehow or...
				// have the user input filename to load from :)
				// loadGame(fileName);
				break;

			case 0:
				mainMenu();
				break;

		}

	} while (selection > 3 || selection < 0);

}