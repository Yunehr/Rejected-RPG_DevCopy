#pragma once

// Ryan Hackabrt & Luis Changyuan Lu - CSCN7130_Section2_Group3 - Combat Module
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "PlayerCharacter.h"
#include "enemy.h"
#include "RNG.h"


int combatLoop(PC player, MOB enemy);

bool hitCheckPC(PC player);
bool hitCheckMOB(MOB enemy);


// Combat Movesets
int SelectPlayerMoveset(PC player);
int rogueMovesetMenu(PC player);
int warriorMovesetMenu(PC player);
int mageMovesetMenu(PC player);

double MovesetDamagePC(PC* player, MOB enemy, int attackPC);
double rogueAtkkDmg(PC* player, int attack, int defense);
double warriorAtkDmg(PC* player, int attack, MOB enemy);
double mageAtkDmg(PC* player, int attack, int defense);

double critHit(int chance, double multi);