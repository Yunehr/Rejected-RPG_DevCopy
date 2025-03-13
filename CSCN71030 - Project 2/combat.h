#pragma once

// Ryan Hackabrt & Luis Changyuan Lu - CSCN7130_Section2_Group3 - Combat Module
#include <stdio.h>
#include <stdbool.h>
#include "PlayerCharacter.h"
#include "enemy.h"


int combatLoop(PC player, MOB enemy);

bool hitCheckPC(PC player);
bool hitCheckMOB(MOB enemy);