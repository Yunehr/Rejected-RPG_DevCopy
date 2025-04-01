#define _CRT_SECURE_NO_WARNINGS
#include "optionsMenu.h"
#include "gameFunctions.h"
#include "mainMenu.h"
#include <stdio.h>
#include <stdlib.h>

// Matthew Romano - CSCN71030_Section2_Group3 - Options Menu Implementation

int optionsMenu(PC player) {
	int selection = 0;							// variable for selection

	// message to make menu look better
	printf("\n\n\nYour journey is far from over, but even the greatest of heros must rest.\n\n");
	printf("Your Character\n");
	printCharacter(player);						// shows ur stats

	printf("\n1 CONTINUE STORY\n\n2 SAVE GAME\n\n0 EXIT GAME\n\n");
	do {
		scanf("%d", &selection);
		switch (selection) {
			case 1:
				return 1;						// now returns a value to test
				break;
			case 2:
				if (saveGame(&player) == 1)		// saves player to file
				break;
			case 0:
				exit(EXIT_SUCCESS);				// exit game = 0
				break;
		}

	} while (selection > 2 || selection < 0);

	return -1;
}