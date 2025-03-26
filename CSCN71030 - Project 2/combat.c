// Ryan Hackabrt & Luis Changyuan Lu - CSCN7130_Section2_Group3 - Combat Module

#include "combat.h"

#define VICTORY 1
#define LOSER	2

int combatLoop(PC player, MOB enemy) {
	//Create a const multi-dimensional array to save the actions of three classes.
	const char* battleMoves[PLAYER_CLASSES][STATS_ARRAY] = {
		{ "You strike from the shadows and ", "You rapidly stab the enemy multiple times and ",
		"You attack with a venom-coated dagger and ","Rogue attack 4 and ","Rogue attack 5 and ","Rogue attack 6 and "},
		{ "You swing a greatsword with berserk force and ", "You slam the enemy with your shield and ",
		"You deliver a powerful strike that weakens the enemy¡¯s defense and ",
		"Warrior attack 4 and ","Warrior attack 5 and ","Warrior attack 6 and "},
		{ "You unleashe a fiery blast, scorching enemy and ",
		"You summon freezing frost, slowing the enemy¡¯s movement and ", "You call down lightning to strike the enemy and ",
		"Mage attack 4 and ","Mage attack 5 and ","Mage attack 6 and " }
	};
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
		if (hitCheckPC(player)) {
			//roll for damage
			int damagePC = MovesetDamagePC(player, enemy.stats[DEF], attackPC);
			//Choose an attack action of the 6 based on the player character.
			printf(battleMoves[player.charclass][RNG(5, 0)]);
			printf("deal %d damage!\n", damagePC);
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
		//Add an \n after each round over.
		printf("\n");
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
			printf("Player Attack missed!\n");
			return false;
		}
	case WAR:
		hit = player.stats[SPD] / 10 + RNG(100, 1);
		if (hit > 10) {
			return true;
		}
		else {
			printf("Player Attack missed!\n");
			return false;
		}
	case MAG:
		hit = 1 + RNG(100, 1);
		if (hit > 10) {
			return true;
		}
		else {
			printf("Player Attack missed!\n");
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
		printf("%s Attack missed!\n", enemy.name);
		return false;
	}
}