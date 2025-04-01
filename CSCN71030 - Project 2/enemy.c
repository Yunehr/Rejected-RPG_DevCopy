// Ryan Hackabrt - CSCN7130_Section2_Group3 - Enemy MOB Implementation

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "enemy.h"
#include "PlayerCharacter.h"
#include "combat.h"
#include "RNG.h"


// enemy creation Creation
MOB setEnemy(BOSS c) {		//these current stats are based on character stats since we do not have stats designed yet
	MOB newMOB = { 0 };
	int Enemies[ENEMY_TYPES][STATS_ARRAY] = { { 110, 25, 22, 5, 18, 5 }, { 50, 50, 12, 10, 10, 20} , { 75, 20, 18, 1, 12, 5 } };
	//Stats Order:		THIEF	FIN		BEAR
	//	Health			50,		110		75
	//	Mana			50,		25		20
	//	Strength		15,		25		18
	//	Intelligence	10,		5		1
	//  Defence			10,		15		12
	//	Speed			20,		5		5

	switch (c) {
		case FIN:
		strncpy(newMOB.name, "Boss Bunny", MAX_NAME);
		newMOB.type = FIN;
		return updateStatsMOB(newMOB, Enemies[c]);
	case THIEF:
		strncpy(newMOB.name, "Thief", MAX_NAME);
		newMOB.type = THIEF;
		return updateStatsMOB(newMOB, Enemies[c]);
	case BEAR:
		strncpy(newMOB.name, "Grizzly Bear", MAX_NAME);
		newMOB.type = BEAR;
		return updateStatsMOB(newMOB, Enemies[c]);

	}
	
	return newMOB;
}

// Updating stats
MOB updateStatsMOB(MOB enemy, int arr[]) {
	for (int i = 0; i < STATS_ARRAY; i++) {
		enemy.stats[i] = arr[i];
	}
	return enemy;
}

//Update stat function to increase/decrease individual stats easily
void increaseStatMOB(MOB* enemy, STAT type, int mod) {
	enemy->stats[type] += mod;
}

// Combat Integration

// Combat Movesets
int SelectMOBMoveset(MOB enemy, int combatRound) {
	switch (enemy.type) {
	case FIN:
		return FinalBossMoveset(combatRound);
	case THIEF:
		return thiefMoveset(combatRound);
	case BEAR:
		return bearMoveset(combatRound);
	}
}
int thiefMoveset(int combatRound) {	
	return 1;
}
int FinalBossMoveset(int combatRound) {	//TODO: change this to randomize attacks depending on combat round (something big attack on round 3, and 6) when other attacks get implemented
	return 1;
}
int bearMoveset(int combatRound) {
	return 1;
}



//Moveset Damage Calculations
int MovesetDamageMOB(MOB enemy, int defense, int attack) {
	switch (enemy.type) {
	case FIN:
		return finalBossAtkDmg(enemy, attack, defense);
	case THIEF:
		return thiefAtkkDmg(enemy, attack, defense);
	
	}
}
int thiefAtkkDmg(MOB enemy, int attack, int defense) {	
	double damage = 0;
	double critMod = 1;
	switch (attack) {

	case 1: // basic attack (stab)
		critMod = critHit(10, 2); //10% crit chance, multiplies damage by 2
		if (critMod > 1)
			printf("CRITICAL HIT!\n");
		damage = (enemy.stats[STR] * critMod) - defense;
		if (damage < 0)
			damage = 0;	//prevents negative numbers
		return damage;
	}
}
int finalBossAtkDmg(MOB enemy, int attack, int defense) {
	double damage = 0;
	double critMod = 1;
	switch (attack) {

	case 1: // basic attack (stab)
		critMod = critHit(10, 1.5); //10% crit chance, multiplies damage by 1.5
		if (critMod > 1)
			printf("CRITICAL HIT!\n");
		damage = (enemy.stats[STR] * critMod) - defense;
		if (damage < 0)
			damage = 0;	//prevents negative numbers
		return damage;
	}
}
double bearAtkDmg(MOB enemy, int attack, int defense) {
	double damage = 0;
	double critMod = 1;
	switch (attack) {

	case 1: // basic attack (stab)
		critMod = critHit(10, 1.5); //10% crit chance, multiplies damage by 1.5
		if (critMod > 1)
			printf("CRITICAL HIT!\n");
		damage = (enemy.stats[STR] * critMod) - defense;
		if (damage < 0)
			damage = 0;	//prevents negative numbers
		return damage;
	}
}
