#include "PlayerCharacter.h"
#include "gameFunctions.h"
#include "gameFunction-Tests.h"
#include <stdio.h>

// mattr - group3 - project2
// intergration tests for the game funcitons

// Tests are split up into: (what they test, the perams, expected return)

// runs new game, no perams, expected true
bool newGameTest() {
	if (newGame() == true)
		return true;

	return false;
}

// runs save game, sends defined PC struct, expected true
bool saveGameTest() {
	// setup a character
	PC testPlayer;
	testPlayer = setCharacter(0);
	if (saveGame(&testPlayer) == true)
		return true;

	return false;
}

// runs load game, no perams, expected PC struct
bool loadGameTest() {
	// MAKE SURE THERE IS A PLAYER IN FILE
	PC tempPlayer;
	tempPlayer = loadGame();
	if (tempPlayer.charclass != NULL)
		return true;

	return false;
}

// general function to call all tests
void gameFunctionTests() {
	// checks new game
	if (newGameTests() == true)
		printf("\nnewGame() Test: PASSED\n");
	else 
		printf("\nnewGame() Test: FAILED\n");

	// checks save game
	if (saveGameTests() == true)
		printf("\nsaveGame() Test: PASSED\n");
	else
		printf("\nsaveGame() Test: FAILED\n");

	// checks load game
	if (loadGameTests() == true)
		printf("\nloadeGame() Test: PASSED\n");
	else
		printf("\nloadGame() Test: FAILED\n");

}
