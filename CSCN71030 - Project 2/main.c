#define _CRT_SECURE_NO_WARNINGS
#include "mainMenu.h"
#include "PlayerCharacter.h"
#include "gameFunctions.h"
#include "RNG.h"
#include "screens.h"
#include <stdio.h>
#include <stdlib.h>

// CSCN71030_Section2_Group3 - Main class
// main menu is the start function
// might add a start() function to make it look better
int main(int argc, char* argv[]) {
	FILE* saveFile;
	PC mc;
	
	/* THE FILE NAME FOR SAVING AND LOADING IS "SaveGame.txt"
	if (argc == 2)
		saveFile = fopen(argv[1], "w");
	else
		saveFile = NULL;

	if (saveFile == NULL) {
		printf("Error opening file");
		exit(EXIT_FAILURE);
	} */

	// setup for character
	mc = characterSelectMenu();

	// starting the game
	int startCheck = mainMenu(mc);

	// checks for main menu selection
	if (startCheck == 1)
		newGame();
	else if (startCheck == 2) {
		mc = loadGame("SaveGame.txt");
		checkPoint(mc.playerCheckpoint);
	}
	else if (startCheck = 0) {
		exit(EXIT_SUCCESS);
	}

	//fclose(saveFile);

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