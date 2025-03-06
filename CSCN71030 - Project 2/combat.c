// Ryan Hackabrt & Luis Changyuan Lu - CSCN7130_Section2_Group3 - Combat Module

#include <stdio.h>
#include "combat.h"

#define VICTORY 1
#define LOSER	2

int combatLoop(PC player, MOB enemy) {
	int combatRound = 1;

	while (player.stats[0] > 0 || enemy.stats[0] > 0) {
		//Moveset Selection
		int attackPC = SelectPlayerMoveset(player);
		int attackMOB = SelectMOBMoveset(enemy, combatRound);
		
		//Player Moves First
		if (hitCheckPC(player)) {
			//roll for damage
			int damagePC = MovesetDamagePC(player, attackPC);
			//deal damage
			if (takeDamageMOB(&enemy, damagePC) = 0)
				return VICTORY;
		}

		//enemy moves second
		if (hitCheckMOB(enemy)) {
			//roll for damage
			int damageMOB = MovesetDamageMOB(enemy, attackMOB);
			//deal damage
			if (takeDamagePC(&player, damageMOB) = 0)
				return LOSER;
		}

		//if you get here, there is no victor or loser yet
		combatRound++;
	}

}

//bool hitcheckPC{
//	switch (switch_on)
//	{
//		default:
//	break;
//	}
//}

//bool attackHitCheck(int speed) {
//	int hit = speed / PHYSICALHITCOEFFICIENT + rand() % (MAXPROBILITY + ONE);
//	if (hit > DEFAULTMISS) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//bool magicHitCheck(int magichit) {
//	int hit = magichit + rand() % (MAXPROBILITY + ONE);
//	if (hit > DEFAULTMISS) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}