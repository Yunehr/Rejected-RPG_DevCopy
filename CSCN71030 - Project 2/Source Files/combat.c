// Ryan Hackabrt & Luis Changyuan Lu - CSCN7130_Section2_Group3 - Combat Module

#include <stdio.h>
#include "combat.h"

#define VICTORY 1
#define LOSER	2

int combatLoop(PC player, MOB enemy) {
	int combatRound = 1;
	int playerHP = player.stats[0];
	int enemyHP = enemy.stats[0];

	//Combat Loop
	while (combatRound <= 20) {		//while neither player nor enemy is dead (HP > 0) && combatRound <= 20
		//Moveset Selection
		int attackPC = SelectPlayerMoveset(player);
		int attackMOB = SelectMOBMoveset(enemy, combatRound);
		
		//Player Moves First
		if (hitCheckPC(player)) {
			//roll for damage
			int damagePC = MovesetDamagePC(player, enemy.stats[DEF], attackPC);
			//deal damage
			enemyHP = enemyHP - damagePC; //this replaced takeDamage()
			if ( enemyHP <= 0)
				return VICTORY;
		}

		//enemy moves second
		if (hitCheckMOB(enemy)) {
			//roll for damage
			int damageMOB = MovesetDamageMOB(enemy, player.stats[DEF], attackMOB);
			//deal damage
			playerHP = playerHP - damageMOB; //this replaced takeDamage()
			if (playerHP <= 0)
				return LOSER;
		}

		//if you get here, there is no victor or loser yet
		combatRound++;
	}

}

bool hitcheckPC(PC player){
	int hit;
	switch (player.charclass)
	{
	case ROG:
		hit = player.stats[SPD] / 10 + RNG(100, 1);
		if (hit > 10) {
			return true;
		}
		else {
			return false;
		}
	case WAR:
		hit = player.stats[SPD] / 10 + RNG(100, 1);
		if (hit > 10) {
			return true;
		}
		else {
			return false;
		}
	case MAG:
		hit = 1 + RNG(100, 1);
		if (hit > 10) {
			return true;
		}
		else {
			return false;
		}
		default:
	break;
	}
}

bool hitCheckMOB(MOB enemy) {
	int hit;
	switch (enemy.type)
	{
	case FIN:
		hit = 5 + RNG(100, 1);	//Final Boss has a 5% chance to miss
		if (hit > 10) {
			return true;
		}
		else {
			return false;
		}
	case THIEF:
		hit = 1 + RNG(100, 1); //Thief has a 10% chance to miss
		if (hit > 10) {
			return true;
		}
		else {
			return false;
		}
	default:
		break;
	}
}
