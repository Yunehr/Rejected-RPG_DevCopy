#define _CRT_SECURE_NO_WARNINGS
#include "gameFunctions.h"
#include <stdio.h>
#include <stdlib.h>

// Matthew Romano - CSCN71030_Section2_Group3 - Game Functions Implementation
// A bunch of useful functions needed in multipule places


// all this fucntion does is create the new file
void newGame() {
	FILE* newGameFile;							// creates new file pointer

	newGameFile = fopen("GameFile.txt", "w");				
	if (newGameFile == NULL) {					// checking for null
		printf("ERROR CREATING FILE");
		exit(EXIT_FAILURE);
	}

	fclose(newGameFile);

	// then sends the user to the character creation
	// createCharacter();

}

void saveGame() {
	FILE* newGameFile;							// creates new file pointer

	newGameFile = fopen("GameFile.txt", "w");
	if (newGameFile == NULL) {					// checking for null
		printf("ERROR CREATING FILE");
		exit(EXIT_FAILURE);
	}

	// we are gonna have to figure out what info to send here
	// character stats obv but how is the more important part

	fclose(newGameFile);
	// this isnt a final point, can return to the game after
}

// this function checks for file to load
void loadGame(char* fileName) {
	FILE* loadGameFile;						// creates new file

	loadGameFile = fopen(fileName, "r");
	if (loadGameFile == NULL) {				// checking for null
		printf("EXISTING FILE NOT FOUND");
		exit(EXIT_FAILURE);
	}

	fclose(loadGameFile);

	// sends file to the load character function
	// loadGameFromFile(laodGameFile);

}