#pragma once
#include <stdbool.h>

// mattr - group3 - project2
// intergration tests for the game funcitons

// test for bool newGame()
bool newGameTest();

// test for bool saveGame(PC toSave);
bool saveGameTest();

// test for PC loadGame();
bool loadGameTest();

// calls all tests
void gameFunctionTests();