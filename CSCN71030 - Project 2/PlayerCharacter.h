#pragma once

// Ryan Hackabrt - CSCN7130_Section2_Group3 - ADT for Playable Character

#include <stdio.h>
#include <stdbool.h>
#define STATS_ARRAY 6
#define NAME_LENGTH	7

typedef enum type{ROG = 0, WAR = 1, MAG = 2}TYPE;

typedef struct PlayerCharacter {
	char* name[NAME_LENGTH];	// Warrior, Rogue, or Mage
	TYPE charclass;
	int stats[STATS_ARRAY];		// stored in order: Health, Energy (mana), Str, Int, Defence, Speed

}PC;


// Character Creation
int CharacterSelect();
PC SetCharacter(int Selection);

// Updating stats
bool UpdateStats(int arr[]);
bool TakeDamage(int dmg);

// Combat Movesets


//Save/Load to/from file




