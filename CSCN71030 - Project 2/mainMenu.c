#define _CRT_SECURE_NO_WARNINGS
#include "mainMenu.h"
#include <stdio.h>
#include <stdlib.h>

// Matthew Romano - CSCN71030_Section2_Group3 - Main Menu Implenentation

// so far not returning anything (should be fine)
void mainMenu() {
	// needs three options Exit Game (0), Create New Save File (1), Load Save File (2)
	int selection = 0;

	printf("THIS IS THE MAIN MENU");
	printf("\n\nNEW GAME = 1\n\nLOAD GAME = 2\n\nEXIT GAME = 0\n\n");	// base for the menu options
	do {
		printf("SELECTION: ");
		scanf("%d", &selection);
		if (selection > 2 || selection < 0)								// input validation
			printf("\n\nINVALID INPUT, PLEASE ENTER NEW ");
	} while (selection > 2 || selection < 0);

	switch (selection) {
	case 1:
		// start new game function here
		break;
	case 2:
		// load game function here
		break;
	case 0:
		// exit game function here
		break;
	}
}