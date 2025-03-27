#pragma once

// Ryan Hackabrt - CSCN7130_Section2_Group3 - ADT for Playable Character

#include <stdio.h>
#include "enemy.h"
#include "globals.h"
#include <string.h>

#define PLAYER_CLASSES	3

typedef enum type { ROG = 0, WAR = 1, MAG = 2 }TYPE;

typedef struct PlayerCharacter {
	char name[MAX_NAME];	// Warrior, Rogue, or Mage
	TYPE charclass;
	int stats[STATS_ARRAY];		// stored in order: Health, Energy (mana), Str, Int, Defence, Speed
	int playerCheckpoint;
}PC, * _PC;

// Character Selection Menu
PC characterSelectMenu();

// Character Creation

PC setCharacter(int c);

// Updating stats


PC updateStatsPC(PC player, int arr[]);
void increaseStatPC(PC* player, int type, int mod);


//// Combat Movesets
//int SelectPlayerMoveset(PC player);
//int rogueMovesetMenu();
//int warriorMovesetMenu();
//int mageMovesetMenu();
//
//double MovesetDamagePC(PC player, MOB enemy, int attackPC);
//double rogueAtkkDmg(PC player, int attack, int defense);
//double warriorAtkDmg(PC player, int attack, MOB enemy);
//double mageAtkDmg(PC player, int attack, int defense);
//
//double critHit(int chance, double multi);

//Other
void printCharacter(PC player);




