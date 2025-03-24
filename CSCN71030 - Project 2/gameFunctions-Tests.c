#include "gameFunctions.h"
#include "gameFunctions-Tests.h"
#include "mainMenu.h"
#include "optionsMenu.h"
#include <stdbool.h>
#include <stdio.h>

// mattr - group3 - project2
// intergration tests for the game funcitons and menus

// Tests are split up into: (what they test, the perams, expected return)

// choses new game option within main menu, none, return 1
bool mainMenuNewGame() {
	int result = mainMenu();
	if (result == 1) // upon new game selection return value is 1
		return true;
	
	return false;
}

// choses load game option within main menu, none, return 2
bool mainMenuLoadGame() {
	int result = mainMenu();
	if (result == 2) // upon load game selection return value is 1
		return true;

	return false;
}

// choses exit option within main menu, none, return 0
bool mainMenuExit() {
	int result = mainMenu();
	if (result == 0) // upon exit selection value is 0
		return true;

	return false;
}

// runs options menu, none, return 1
bool optionsMenuTest() {
	int result = optionsMenu(setCharacter(WAR));
	if (result == 1) // upon successful process return value is 1
		return true;

	return false;
}

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
	if (newGameTest() == true)
		printf("\nnewGame() Test: PASSED\n");
	else 
		printf("\nnewGame() Test: FAILED\n");

	// checks save game
	if (saveGameTest() == true)
		printf("\nsaveGame() Test: PASSED\n");
	else
		printf("\nsaveGame() Test: FAILED\n");

	// checks load game
	if (loadGameTest() == true)
		printf("\nloadeGame() Test: PASSED\n");
	else
		printf("\nloadGame() Test: FAILED\n");

	// checks main menu's new game option
	if (mainMenuNewGame() == true)
		printf("\nloadeGame() Test: PASSED\n");
	else
		printf("\nloadGame() Test: FAILED\n");

	// checks main menu's load game option
	if (mainMenuLoadGame() == true)
		printf("\nloadeGame() Test: PASSED\n");
	else
		printf("\nloadGame() Test: FAILED\n");

	// checks main menu's exit option
	if (mainMenuExit() == true)
		printf("\nloadeGame() Test: PASSED\n");
	else
		printf("\nloadGame() Test: FAILED\n");

	// checks main menu's exit option
	if (optionsMenuTest() == true)
		printf("\nloadeGame() Test: PASSED\n");
	else
		printf("\nloadGame() Test: FAILED\n");

}
