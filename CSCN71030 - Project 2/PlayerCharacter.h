#pragma once

// Ryan Hackabrt - CSCN7130_Section2_Group3 - ADT for Playable Character

#include <stdio.h>
#include <stdbool.h>
#define STATS_ARRAY		6
#define PLAYER_CLASSES	3
#define MAX_NAME		7

typedef enum type{ROG = 0, WAR = 1, MAG = 2}TYPE;

typedef struct PlayerCharacter {
	char name[MAX_NAME];	// Warrior, Rogue, or Mage
	TYPE charclass;
	int stats[STATS_ARRAY];		// stored in order: Health, Energy (mana), Str, Int, Defence, Speed

}PC, * _PC;

// Character Selection Menu
PC characterSelectMenu();

// Character Creation

PC setCharacter(int c);

// Updating stats
PC updateStats(PC player, int arr[]);


// Combat Movesets
int SelectPlayerMoveset(PC player);
int MovesetDamagePC(PC player, int attackPC);
int takeDamagePC(_PC player, int damage);

//Other
void printCharacter(PC player);



