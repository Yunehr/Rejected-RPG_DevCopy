#pragma once

// Ryan Hackabrt - CSCN7130_Section2_Group3 - Enemy MOB ADT

#include <stdio.h>
#include <stdbool.h>
#include "PlayerCharacter.h"
#include "globals.h"


#define ENEMY_TYPES		3


typedef enum boss { FIN = 0, THIEF = 1, BEAR = 2 }BOSS;
typedef enum stat { HP = 0, MP = 1, STR = 2, INTEL = 3, DEF = 4, SPD = 5 }STAT;		//redefinition but it works for some reason

typedef struct enemy {
	char name[MAX_NAME];	// Boss Bunny, thief
	BOSS type;
	int stats[STATS_ARRAY];		// stored in order: Health, Energy (mana), Str, Int, Defence, Speed

}MOB, * _MOB;

// enemy creation Creation
MOB setEnemy(BOSS c);

// Updating stats
MOB updateStatsMOB(MOB enemy, int arr[]);
void increaseStatMOB(MOB* enemy, STAT type, int mod);

// Combat Movesets
int SelectMOBMoveset(MOB enemy, int combatRound); 
int thiefMoveset(int combatRound);
int FinalBossMoveset(int combatRound);
int bearMoveset(int combatRound);

int MovesetDamageMOB(MOB enemy, int defense, int attack);
int thiefAtkkDmg(MOB enemy, int attack, int defense); 
int finalBossAtkDmg(MOB enemy, int attack, int defense);
double bearAtkDmg(MOB enemy, int attack, int defense);
