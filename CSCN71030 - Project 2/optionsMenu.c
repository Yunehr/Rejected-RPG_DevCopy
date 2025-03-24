#include "optionsMenu.h"
#include "gameFunctions.h"
#include "mainMenu.h"
#include <stdio.h>
#include <stdlib.h>

// Matthew Romano - CSCN71030_Section2_Group3 - Options Menu Implementation

int optionsMenu(PC player) {
	int selection = 0;						// variable for selection
	// dis menu do be basic do
	printCharacter(player); // shows ur stats
	printf("\n\n1 BACK TO GAME\n\n2 SAVE GAME\n\n0 EXIT GAME");
	do {
		switch (selection) {
			case 1:
				return 1; // now returns a value to test
				break;
			case 2:
				if (saveGame(&player) == 1)		// saves player to file
				break;
			case 0:
				exit(EXIT_SUCCESS);				// exits game
				break;
		}

	} while (selection > 2 || selection < 0);

}