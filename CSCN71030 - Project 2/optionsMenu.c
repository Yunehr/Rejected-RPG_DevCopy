#include "optionsMenu.h"
#include "gameFunctions.h"
#include "mainMenu.h"
#include <stdio.h>
#include <stdlib.h>

// Matthew Romano - CSCN71030_Section2_Group3 - Options Menu Implementation

void optionsMenu(PC player) {
	int selection = 0;						// variable for selection
	// dis menu do be basic do
	printf("\n\n1 BACK TO GAME\n\n2 SAVE GAME\n\n3 LOAD GAME\n\n0 MAIN MENU");
	do {
		switch (selection) {
			case 1:
				// nothing to see here
				break;

			case 2:
				// saves player to file
				if (saveGame(&player) == 1)
				break;

			case 3:
				// saves file into player
				//TODO: this wont be here later, or at least not this exactally
				player = loadGame();
				break;

			case 0:
				mainMenu();
				break;

		}

	} while (selection > 3 || selection < 0);

}