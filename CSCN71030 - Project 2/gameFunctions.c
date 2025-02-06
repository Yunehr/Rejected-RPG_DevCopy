#define _CRT_SECURE_NO_WARNINGS
#include "gameFunctions.h"
#include <stdio.h>
#include <stdlib.h>

// Matthew Romano - CSCN71030_Section2_Group3 - Game Functions Implementation
// A bunch of useful functions needed in multipule places


// all this fucntion does is create the new file
void newGame() {
	// then sends the user to the character creation
	// thanks Ryan :)
	CharacterSelectMenu()

}

void saveGame() {
	FILE* newGameFile;							// creates new file pointer

	newGameFile = fopen("SaveGame.txt", "w");
	if (newGameFile == NULL) {					// checking for null
		printf("ERROR CREATING FILE");
		exit(EXIT_FAILURE);
	}

	// TODO: figure out how to send info here
	// character stats obv but how is the more important part

	fclose(newGameFile);
	// this isnt a final point, can return to the game after
}

// this function checks for file to load
void loadGame() {
	FILE* loadGameFile;						// creates new file

	loadGameFile = fopen("SaveGame.txt", "r");
	if (loadGameFile == NULL) {				// checking for null
		printf("EXISTING FILE NOT FOUND");
		exit(EXIT_FAILURE);
	}

	fclose(loadGameFile);

	// sends file to the load character function

}