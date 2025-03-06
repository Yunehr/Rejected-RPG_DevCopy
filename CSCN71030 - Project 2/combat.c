// Ryan Hackabrt & Luis Changyuan Lu - CSCN7130_Section2_Group3 - Combat Module

#include <stdio.h>
#include "combat.h"

#define VICTORY 1
#define LOSER	2

int combatLoop(PC player, MOB enemy) {

	while (player.stats[0] > 0 || enemy.stats[0] > 0) {
		//Moveset Selection
		
		//Player Moves First
		// 
		//roll for damage
		// 
		//deal damage

		if (enemy.stats[0] <= 0)
			return VICTORY;
		
		//enemy moves second
		// 
		//roll for damage
		// 
		//deal damage

		if (player.stats[0] <= 0)
			return LOSER;
		
	}

}