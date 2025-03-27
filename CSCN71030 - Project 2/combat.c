#define _CRT_SECURE_NO_WARNINGS
// Ryan Hackabrt & Luis Changyuan Lu - CSCN7130_Section2_Group3 - Combat Module

#include "combat.h"

#define VICTORY 0
#define LOSER	1

int combatLoop(PC* player, MOB enemy) {
	//Create a const multi-dimensional array to save the actions of three classes.
	/*const char* battleMoves[PLAYER_CLASSES][STATS_ARRAY] = {
		{ "You strike from the shadows and ", "You rapidly stab the enemy multiple times and ",
		"You attack with a venom-coated dagger and ","Rogue attack 4 and ","Rogue attack 5 and ","Rogue attack 6 and "},
		{ "You swing a greatsword with berserk force and ", "You slam the enemy with your shield and ",
		"You deliver a powerful strike that weakens the enemy's defense and ",
		"Warrior attack 4 and ","Warrior attack 5 and ","Warrior attack 6 and "},
		{ "You unleashe a fiery blast, scorching enemy and ",
		"You summon freezing frost, slowing the enemy's movement and ", "You call down lightning to strike the enemy and ",
		"Mage attack 4 and ","Mage attack 5 and ","Mage attack 6 and " }
	};*/
	int combatRound = 1;
	double playerHP = player->stats[0];
	double enemyHP = enemy.stats[0];
	printf("The Combat Begin!\n");
	Sleep(1000);
	while (combatRound <= 20) {
		//Moveset Selection
		int attackPC = SelectPlayerMoveset(*player);
		int attackMOB = SelectMOBMoveset(enemy, combatRound);
		
		//mage ultimate check
		if (player->charclass == MAG && attackPC == 4) {
			double missingHP = player->stats[HP] - playerHP;
			printf("Although you could only do it once... You used half your Mana and heal yourself by %f", (missingHP/2));
			playerHP += missingHP / 2;	// heal HP in combat by 50% missing hp
		}

		//Player Moves First
		if (hitCheckPC(*player)) {
			//roll for damage
			double damagePC = MovesetDamagePC(player, &enemy, attackPC);

			//Choose an attack action of the 6 based on the player character.
			//printf(battleMoves[player.charclass][RNG(5, 0)]);
			printf("deal %f damage!\n", damagePC);
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
			double damageMOB = MovesetDamageMOB(enemy, player->stats[DEF], attackMOB);
			printf("%s attack the %s, deal %f damage!\n", enemy.name, player->name, damageMOB);
			//deal damage
			playerHP = playerHP - damageMOB; //this replaced takeDamage()
			if (playerHP <= 0) {
				printf("The %s was defeated!\n", player->name);
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



// Combat Integration

//Moveset Menus
int SelectPlayerMoveset(PC player) {
	printf("Please Select an Attack Type:\n");
	switch (player.charclass) {
	case ROG:
		return rogueMovesetMenu(player);
	case WAR:
		return warriorMovesetMenu(player);
	case MAG:
		return mageMovesetMenu(player);
	}
}
int rogueMovesetMenu(PC player) {
	while (1) {
		int choice;
		printf("1 = Dagger Throw, 2 = Double Strike, 3 = Piercing Stab, 4 = Blade Dance\nEnter Your Choice: ");
		if (scanf("%d", &choice) == 1) { //valid input
			switch (choice) {
			case 1:
				return choice;
			case 2:
				if (player.stats[MP] > 5)
					return choice;
			case 3:
				if (player.stats[MP] > 5)
					return choice;
			case 4:
				if (player.stats[MP] > 25)
					return choice;
			}
		}
		// Flush invalid input
		printf("Invalid choice. Please enter a number that corresponds to the attack you want to use.\n");
		while (getchar() != '\n');
	}
	return 1; //default return, should never reach this
}
int warriorMovesetMenu(PC player) {
	while (1) {
		int choice;
		printf("1 = Shield Bash, 2 = Focus Strike, 3 = Guard Break, 4 = Berserk\nEnter Your Choice: ");
		if (scanf("%d", &choice) == 1) { //valid input
			switch (choice) {
			case 1:
				return choice;
			case 2:
				if (player.stats[MP] > 2)
					return choice;
			case 3:
				if (player.stats[MP] > 5)
					return choice;
			case 4:
				if (player.stats[MP] > 12)
					return choice;
			}
		}
		// Flush invalid input
		printf("Invalid choice. Please enter a number that corresponds to the attack you want to use.\n");
		while (getchar() != '\n');
	}
	return 1; //default return, should never reach this
}
int mageMovesetMenu(PC player) {
	while (1) {
		int choice;
		printf("1 = Magic Missile, 2 = Summon Lightning, 3 = Fireball, 4 = Healing Wave\nEnter Your Choice: ");
		if (scanf("%d", &choice) == 1) {
			switch (choice) { //valid input
			case 1:
				return choice;
			case 2:
				if (player.stats[MP] > 10)
					return choice;
			case 3:
				if (player.stats[MP] > 15)
					return choice;
			case 4:
				if (player.stats[MP] > 50)
					return choice;
			}
			printf("Not enough Mana!!\n");	//only arrive here if player does not have enough mna for that attak
		}
		// Flush invalid input
		printf("Invalid choice. Please enter a number that corresponds to the attack you want to use.\n");
		while (getchar() != '\n');
	}
	return 1; //default return, should never reach this
}

//Moveset Damage Calculations
double MovesetDamagePC(PC* player, MOB* enemy, int attack) {
	switch (player->charclass) {
	case ROG:
		return rogueAtkkDmg(player, attack, enemy->stats[DEF]);
	case WAR:
		return warriorAtkDmg(player, attack, enemy);
	case MAG:
		return mageAtkDmg(player, attack, enemy->stats[DEF]);
	}
}

double rogueAtkkDmg(PC* player, int attack, int defense) {
	double damage = 0;
	double critMod = 1;
	switch (attack) {

	case 1: // Dagger Throw -- basic attack
		critMod = critHit(10, 2); //10% crit chance, multiplies damage by 2
		if (critMod > 1)
			printf("CRITICAL HIT!\n");
		damage = (player->stats[STR] * critMod) - defense;
		return damage;

	case 2:	// Double strike
		for (int i = 0; i < 2; i++) {
			critMod = critHit(10, 2); //10% crit chance, multiplies damage by 2
			if (critMod > 1)
				printf("CRITICAL HIT!\n");
			damage += ((player->stats[STR]) * critMod) - defense;
		}
		increaseStatPC(player, MP, -5); // mana cost = 5 (might need adjusting)

		if (damage < 0)
			damage = 0;
		return damage;

	case 3:	// Piercing Stab
		critMod = critHit(10, 1.5); //10% crit chance, multiplies damage by 1.5
		if (critMod > 1)
			printf("CRITICAL HIT!\n");
		damage += (player->stats[STR] * critMod) - (defense / 2);
		increaseStatPC(player, MP, -5); // mana cost = 5 (might need adjusting)

		if (damage < 0)
			damage = 0;
		return damage;

	case 4: // Blade Dance
		for (int i = 0; i < RNG(6, 4); i++) {
			critMod = critHit(30, 2); //30% crit chance, multiplies damage by 1.5
			if (critMod > 1)
				printf("CRITICAL HIT!\n");
			damage += ((1.2 * player->stats[STR]) * critMod) - defense;
			defense--; //this is mainly to test, but ultimate is supposed to deal a ton of dmg
		}
		increaseStatPC(player, MP, -25); // mana cost of using ultimate is 1/2 starting mana

		if (damage < 0)
			damage = 0;
		return damage;
	}
}

double warriorAtkDmg(PC* player, int attack, MOB* enemy) {	//TODO: Implement more attacks
	double damage = 0;
	double critMod = 1;
	switch (attack) {

	case 1: // Shiels Bash
		critMod = critHit(10, 1.5); //10% crit chance, multiplies damage by 1.5
		if (critMod > 1)
			printf("CRITICAL HIT!\n");
		damage = (player->stats[STR] * critMod) - enemy->stats[DEF];

		if (damage < 0)
			damage = 0;
		return damage;

	case 2:	// Focus Strike
		critMod = critHit(10, 2); //10% crit chance, multiplies damage by 2
		if (critMod > 1)
			printf("CRITICAL HIT!\n");
		damage = ((1.5 * player->stats[STR]) * critMod) - enemy->stats[DEF];
		increaseStatPC(player, MP, -2); // mana cost = 2

		if (damage < 0)
			damage = 0;
		return damage;

	case 3:	// Guard Break
		critMod = critHit(15, 2); //15% crit chance, multiplies damage by 2
		if (critMod > 1)
			printf("CRITICAL HIT!\n");
		damage = ((0.5 * player->stats[STR]) * critMod) - enemy->stats[DEF];
		increaseStatPC(player, MP, -5); // mana cost = 5
		increaseStatMOB(enemy, DEF, -2); // retuce enemy dafense permanently

		if (damage < 0)
			damage = 0;
		return damage;

	case 4: // Berserk
		printf("You burn your life essence and fall into a berserk fury!\n unleashing an attack of unknown power at the %s\n", enemy->name);
		critMod = critHit(20, 2.5); //20% crit chance, multiplies damage by 2.5
		if (critMod > 1)
			printf("CRITICAL HIT!\n");
		damage = ((2 * player->stats[STR]) * critMod) - (enemy->stats[DEF] / 2);	// attack ignores some defense & max dmg output is 4.5 times original value

		increaseStatPC(player, MP, -12); // mana cost = 15
		printf("After the strike, clarity comes to your mind once more...\nBut in that moment you realise, you will not be able to do an attack like that again\n");

		if (damage < 0)
			damage = 0;
		return damage;
	}
}



double mageAtkDmg(PC* player, int attack, int defense) {	//TODO: Implement more attacks
	double damage = 0;
	double critMod = 1;
	switch (attack) {

	case 1: // Magic Missile
		critMod = critHit(8, 2); //8% crit chance, multiplies damage by 2
		if (critMod > 1)
			printf("CRITICAL HIT!\n");
		damage = (player->stats[INTEL] * critMod) - (0.7 * defense);

		if (damage < 0)
			damage = 0;
		return damage;

	case 2:	// Summon Lightning
		critMod = critHit(15, 2); //15% crit chance, multiplies damage by 2
		if (critMod > 1)
			printf("CRITICAL HIT!\n");
		damage = (player->stats[INTEL] * critMod) - (0.5 * defense);
		increaseStatPC(player, MP, -10); // mana cost = 10

		if (damage < 0)
			damage = 0;
		return damage;

	case 3:	// FIREBALL
		critMod = critHit(10, 2.5); //10% crit chance, multiplies damage by 2.5
		if (critMod > 1)
			printf("CRITICAL HIT!\n");
		damage = ((1.2 * player->stats[INTEL]) * critMod) - (defense);
		increaseStatPC(player, MP, -15); // mana cost = 15

		if (damage < 0)
			damage = 0;
		return damage;

	case 4: // Healing Wave
		//this does no dmg
		printf("You Healed yourself, you dealt no damage");
		increaseStatPC(player, MP, -50); // mana cost = 15
		if (damage < 0)
			damage = 0;
		return damage;
	}
}

double critHit(int chance, double multi) { //insert the % chance of a crit occuring and the resulting multiplier as an argument
	int crit = RNG(100, 1);
	if (crit > (100 - chance)) { //10% crit chance
		return 1 * multi;
	}
	else {
		return 1;
	}
}