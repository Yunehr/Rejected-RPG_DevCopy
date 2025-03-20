// Ryan Hackabrt & Luis Changyuan Lu - CSCN7130_Section2_Group3 - Combat Module

#include "combat.h"

#define VICTORY 1
#define LOSER	2

int combatLoop(PC player, MOB enemy) {
	int combatRound = 1;
	int playerHP = player.stats[0];
	int enemyHP = enemy.stats[0];
	printf("The Combat Begin!\n");
	Sleep(1000);
	while (combatRound <= 20) {
		//Moveset Selection
		int attackPC = SelectPlayerMoveset(player);
		int attackMOB = SelectMOBMoveset(enemy, combatRound);

		//Player Moves First
		if (hitcheckPC(player)) {
			//roll for damage
			int damagePC = MovesetDamagePC(player, enemy.stats[DEF], attackPC);
			printf("%s attack the %s, deal %d damage!\n", player.name, enemy.name, damagePC);
			//deal damage
			enemyHP = enemyHP - damagePC; //this replaced takeDamage()
			if (enemyHP <= 0) {
				printf("The %s was defeated!\n", enemy.name);
				return VICTORY;
			}
		}
		Sleep(1000);
		//enemy moves second
		if (hitCheckMOB(enemy)) {
			//roll for damage
			int damageMOB = MovesetDamageMOB(enemy, player.stats[DEF], attackMOB);
			printf("%s attack the %s, deal %d damage!\n", enemy.name, player.name, damageMOB);
			//deal damage
			playerHP = playerHP - damageMOB; //this replaced takeDamage()
			if (playerHP <= 0) {
				printf("The %s was defeated!\n", player.name);
				return LOSER;
			}
		}
		Sleep(1000);
		//if you get here, there is no victor or loser yet
		combatRound++;

	}
	printf("The %s was not defeated!\n", enemy.name);
	return LOSER;
}

bool hitCheckPC(PC player){
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
	int hit = enemy.stats[SPD] / 10 + RNG(100, 1); //roll for hit
	if (hit > 10) {
		return true;
	}
	else {
		return false;
	}
}