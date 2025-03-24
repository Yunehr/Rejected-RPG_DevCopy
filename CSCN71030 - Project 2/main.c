#define _CRT_SECURE_NO_WARNINGS
#include "mainMenu.h"
#include "PlayerCharacter.h"
#include "gameFunctions.h"
#include "RNG.h"
#include "screens.h"
#include "Storyline.h"
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_ACTS		4	// this can change

// CSCN71030_Section2_Group3 - Main class
// main menu is the start function
// might add a start() function to make it look better
int main(int argc, char* argv[]) {
	FILE* saveFile;
	PC mc;
	int startCheck;

	// checks for CLA
	if (argc != 2) {
		printf("Missing command line arg");
		exit(EXIT_FAILURE);
	}

	// read file from CLA
	saveFile = fopen(argv[1], "r");

	// now if the file doesnt exist it makes a new one
	if (saveFile == NULL) {
		printf("No save file present, new file created");
		saveFile = fopen(argv[1], "w");
		if (saveFile == NULL) {
			printf("Error creating new file");
			exit(EXIT_FAILURE);
		}
	}

	fclose(saveFile);

	// starting the game
	startCheck = mainMenu();

	// checks for main menu selection
	if (startCheck == 1) {
		if (newGame()) {
			// setup for character
			mc = characterSelectMenu();
			printf("\n\n\n\n\n\n"); // makes it look nicer
			storyBegins(&mc);
		}
	}
	else if (startCheck == 2) {
		printf("\n\n\n\n\n\n");		// makes it look nicer also
		mc = loadGame("SaveGame.txt");
		int checkCheck = mc.playerCheckpoint;
		switch (checkCheck) {
		case 1:
			storyBegins(&mc);	// load start of game
			break;
		case 2:
			actOne(&mc);		// load act one
			break;
		case 3:
			actTwo(&mc);		// load act two
			break;
		case 4:
			actThree(&mc);		// load act three
			break;
		default:
			exit(EXIT_FAILURE); // exit due to error
			break;
		}
	}
	else if (startCheck = 0) {
		exit(EXIT_SUCCESS);
	}

	// do, while loop to go throgh the story
	do {
		if (checkPoint(0) == 1) {
			actOne(&mc);
		}
		else if (checkPoint(0) == 2) {
			actTwo(&mc);
		}
		else if (checkPoint(0) == 3) {
			actThree(&mc);
		}
	} while (checkPoint(0) <= NUMBER_OF_ACTS);

	//personal tests
	//printf("Testing Random Number Generator:\n");
	//for (int i = 0; i < 10; i++) {
	//	printf("%d ",RNG(100, 0));
	//}

	//printf("\n\nTesting Player Creation Menu:\n");
	//PC temp = setCharacter(characterSelectMenu()); //temp to test player menu and setCharacter
	//printf("Player class num type is: %d\n", temp.charclass);

	return 0;
}