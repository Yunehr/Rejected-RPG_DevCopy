#define _CRT_SECURE_NO_WARNINGS
#include "gameFunctions.h"
#include "mainMenu.h"
#include <stdio.h>
#include <stdlib.h>


// Matthew Romano - CSCN71030_Section2_Group3 - Main Menu Implenentation

// so far not returning anything (should be fine)
void mainMenu() {
	// needs three options Exit Game (0), Create New Save File (1), Load Save File (2)
	int selection = 0;

	printf("THIS IS THE MAIN MENU");
	printf("\n\nNEW GAME = 1\n\nLOAD GAME = 2\n\nEXIT GAME = 0\n\n");			// base for the menu options
	do {
		printf("SELECTION: ");
		scanf("%d", &selection);

		while (selection > 2 || selection < 0) {								// input validation
			printf("\n\nINVALID INPUT, PLEASE ENTER NEW SELECTION: ");
			scanf("%d", &selection);
		}
	
	switch (selection) {
	case 1:
		// overwrites the old file name if one is present
		printf("THIS WILL OVERWRITE OLD SAVE FILES,"); 
		printf("CONTINUE ? (1 = YES, Other Input = NO): ");
		scanf("%d", &selection);											// selection is good to use again 
			if (selection == 1)							
				newGame();	// creates a new game file

		break;
	case 2:
		loadGame("TempFileName.txt");	// loads old file
		break;
	case 0:
		// clean exit with no error
		exit(EXIT_SUCCESS);
		break;
	}
	} while (selection > 2 || selection < 0);
}