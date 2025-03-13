#pragma once
#include "PlayerCharacter.h"
#include <stdbool.h>

// Matthew Romano - CSCN71030_Section2_Group3 - Load/Start game header file

// starts a new game
bool newGame();

// saves the game
bool saveGame(PC toSave);

// loads a game
PC loadGame();