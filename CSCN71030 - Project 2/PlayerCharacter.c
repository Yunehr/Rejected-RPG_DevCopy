// Ryan Hackabrt - CSCN7130_Section2_Group3 - PlayerCharacter Implementation

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "PlayerCharacter.h"
#include "enemy.h"
#include "RNG.h"


// Character Selection Menu
PC characterSelectMenu() {
	int selection = 0;
	printf("\nPlease Pick a Character\n");
	printf("Rogue:			Warrior:			Mage:\n");
	printf("HP:	75		HP:	100			HP:	50\n");
	printf("MP:	50		MP:	25			MP:	100\n");
	printf("STR:	15		STR:	20			STR:	10\n");
	printf("INT:	10		INT:	5			INT:	20\n");
	printf("DEF:	10		DEF:	15			DEF:	10\n");
	printf("SPD:	20		SPD:	5			SPD:	5\n");
	printf("\n1 FOR ROGUE		2 FOR WARRIOR			3 FOR MAGE\n\n");
	do {
		printf("SELECTION: ");
		scanf("%d", &selection);
		if (selection > 3 || selection < 0)								// input validation
			printf("\n\nINVALID INPUT, PLEASE ENTER NEW ");
	} while (selection > 3 || selection < 0);

	selection--;	//just to make enums and switch case easier to read, not necessary
	
	return setCharacter(selection);
}

// Character Creation

PC setCharacter(int c) {
	PC newChar = { 0 };
	int Classes[PLAYER_CLASSES][STATS_ARRAY] = { { 75, 50, 15, 10, 10, 20 }, 
		{ 100, 25, 20, 5, 15, 5 }, { 50, 100, 10, 20, 10, 5 } };
	//Stats Order:		ROG		WAR		MAG	
	//	Health			75,		100,	50
	//	Mana			50,		25,		100
	//	Strength		15,		20,		10
	//	Intelligence	10,		5,		20
	//  Defence			10,		15,		10
	//	Speed			20,		5,		5
		
	switch (c) {
	case ROG:
		strncpy(newChar.name, "Rogue", MAX_NAME);	
		newChar.charclass = ROG;
		return updateStatsPC(newChar, Classes[c]);
		//return newChar;
	case WAR:
		strncpy(newChar.name, "Warrior", MAX_NAME);
		newChar.charclass = WAR; 
		return updateStatsPC(newChar, Classes[c]);
		//return newChar;
	case MAG:
		strncpy(newChar.name, "Mage", MAX_NAME);
		newChar.charclass = MAG; 
		return updateStatsPC(newChar, Classes[c]);
		//return newChar;
	}
	return newChar;
}



// Updating stats

//resets stats to values in an array
PC updateStatsPC(PC player, int arr[]) {
	for (int i = 0; i < STATS_ARRAY; i++) {
		player.stats[i] = arr[i];
	}
	return player;
}


//Update stat function to increase/decrease individual stats easily
void increaseStatPC(PC* player, int type, int mod) {
	player->stats[type] += mod;
}



// Combat Integration

//Moveset Menus
//int SelectPlayerMoveset(PC player) {
//	printf("Please Select an Attack Type:\n");
//	switch (player.charclass){
//	case ROG:
//		return rogueMovesetMenu();
//	case WAR:
//		return warriorMovesetMenu();
//	case MAG:
//		return mageMovesetMenu();
//	}
//}
//int rogueMovesetMenu() {
//	while (1) {
//		int choice;
//        printf("1 = Dagger Throw, 2 = Double Strike, 3 = Piercing Stab, 4 = Blade Dance\nEnter Your Choice: ");
//        if (scanf("%d", &choice) == 1) {
//            return choice; // Valid input, return choice
//        }
//        // Flush invalid input
//        printf("Invalid choice. Please enter a number that corresponds to the attack you want to use.\n");
//        while (getchar() != '\n');
//    }
//	return 1; //default return, should never reach this
//}
//int warriorMovesetMenu() {
//	while (1) {
//		int choice;
//        printf("1 = Shield Bash, 2 = Focus Strike, 3 = Guard Break, 4 = Berserk\nEnter Your Choice: ");
//        if (scanf("%d", &choice) == 1) {
//            return choice; // Valid input, return choice
//        }
//        // Flush invalid input
//        printf("Invalid choice. Please enter a number that corresponds to the attack you want to use.\n");
//        while (getchar() != '\n');
//    }
//	return 1; //default return, should never reach this
//}
//int mageMovesetMenu() {
//	while (1) {
//		int choice;
//        printf("1 = Magic Missile, 2 = Summon Lightning, 3 = Fireball, 4 = Healing Wave\nEnter Your Choice: ");
//        if (scanf("%d", &choice) == 1) {
//            return choice; // Valid input, return choice
//        }
//        // Flush invalid input
//        printf("Invalid choice. Please enter a number that corresponds to the attack you want to use.\n");
//        while (getchar() != '\n');
//    }
//	return 1; //default return, should never reach this
//}
//
////Moveset Damage Calculations
//double MovesetDamagePC(PC player, MOB enemy, int attack) {
//	switch (player.charclass) {
//	case ROG:
//		return rogueAtkkDmg(player, attack, enemy.stats[DEF]);
//	case WAR:
//		return warriorAtkDmg(player, attack, enemy);
//	case MAG:
//		return mageAtkDmg(player, attack, enemy.stats[DEF]);
//	}
//}
//
//
//
//double rogueAtkkDmg(PC player, int attack, int defense) {
//	double damage = 0;
//	double critMod = 1;
//	switch (attack) {
//
//	case 1: // Dagger Throw -- basic attack
//		critMod = critHit(10, 2); //10% crit chance, multiplies damage by 2
//		if (critMod > 1)
//			printf("CRITICAL HIT!\n");
//		damage = (player.stats[STR] * critMod) - defense;
//		return damage;
//
//	case 2:	// Double strike
//		for (int i = 0; i < 2; i++) {
//			critMod = critHit(10, 2); //10% crit chance, multiplies damage by 2
//			if (critMod > 1)
//				printf("CRITICAL HIT!\n");
//			damage += ((0.9 * player.stats[STR]) * critMod) - defense;
//		}
//		increaseStatPC(&player, MP, -5); // mana cost = 5 (might need adjusting)
//		return damage;
//
//	case 3:	// Piercing Stab
//		critMod = critHit(10, 1.5); //10% crit chance, multiplies damage by 1.5
//		if (critMod > 1)
//			printf("CRITICAL HIT!\n");
//		damage += (player.stats[STR] * critMod) - (defense/2);	
//		increaseStatPC(&player, MP, -5); // mana cost = 5 (might need adjusting)
//		return damage;
//
//	case 4: // Blade Dance
//		for (int i = 0; i < RNG(6, 4); i++) {
//			critMod = critHit(30, 1.5); //30% crit chance, multiplies damage by 1.5
//			if (critMod > 1)
//				printf("CRITICAL HIT!\n");
//			damage += (player.stats[STR] * critMod) - defense; 
//			defense--; //this is mainly to test, but ultimate is supposed to deal a ton of dmg
//		}
//		increaseStatPC(&player, MP, -25); // mana cost of using ultimate is 1/2 starting mana
//		return damage;
//	}
//}
//
//
//
//double warriorAtkDmg(PC player, int attack, MOB enemy) {	//TODO: Implement more attacks
//	double damage = 0;
//	double critMod = 1;
//	switch (attack) {
//
//	case 1: // Shiels Bash
//		critMod = critHit(10, 1.5); //10% crit chance, multiplies damage by 1.5
//		if (critMod > 1)
//			printf("CRITICAL HIT!\n");
//		damage = (player.stats[STR] * critMod) - enemy.stats[DEF];
//		return damage;
//
//	case 2:	// Focus Strike
//		critMod = critHit(10, 2); //10% crit chance, multiplies damage by 2
//		if (critMod > 1)
//			printf("CRITICAL HIT!\n");
//		damage = ((1.5 * player.stats[STR]) * critMod) - enemy.stats[DEF];
//		increaseStatPC(&player, MP, -2); // mana cost = 2
//		return damage;
//
//	case 3:	// Guard Break
//		critMod = critHit(15, 2); //15% crit chance, multiplies damage by 2
//		if (critMod > 1)
//			printf("CRITICAL HIT!\n");
//		damage = ((0.5 * player.stats[STR]) * critMod) - enemy.stats[DEF];
//		increaseStatPC(&player, MP, -5); // mana cost = 5
//		increaseStatMOB(&enemy, DEF, 2); // retuce enemy dafense permanently
//		return damage;
//
//	case 4: // Berserk
//		printf("You burn your life essence and fall into a berserk fury!\n unleashing an attack of unknown power at the %s\n", enemy.name);
//		critMod = critHit(20, 2.5); //20% crit chance, multiplies damage by 2.5
//		if (critMod > 1)
//			printf("CRITICAL HIT!\n");
//		damage = ((2 * player.stats[STR]) * critMod) - (enemy.stats[DEF]/2);	// attack ignores some defense & max dmg output is 4.5 times original value
//
//		increaseStatPC(&player, MP, -12); // mana cost = 15
//		printf("After the strike, clarity comes to your mind once more...\nBut in that moment you realise, you will not be able to do an attack like that again\n");
//		return damage;
//	}
//}
//
//
//
//double mageAtkDmg(PC player, int attack, int defense) {	//TODO: Implement more attacks
//	double damage = 0;
//	double critMod = 1;
//	switch (attack) {
//
//	case 1: // Magic Missile
//		critMod = critHit(8, 2); //8% crit chance, multiplies damage by 2
//		if (critMod > 1)
//			printf("CRITICAL HIT!\n");
//		damage = (player.stats[INTEL] * critMod) - (0.7 * defense);
//		return damage;
//
//	case 2:	// Summon Lightning
//		critMod = critHit(15, 2); //15% crit chance, multiplies damage by 2
//		if (critMod > 1)
//			printf("CRITICAL HIT!\n");
//		damage = (player.stats[INTEL] * critMod) - (0.5 * defense);
//		increaseStatPC(&player, MP, -10); // mana cost = 10
//		return damage;
//
//	case 3:	// FIREBALL
//		critMod = critHit(10, 2.5); //10% crit chance, multiplies damage by 2.5
//		if (critMod > 1)
//			printf("CRITICAL HIT!\n");
//		damage = ((1.2 * player.stats[INTEL]) * critMod) - (defense);
//		increaseStatPC(&player, MP, -15); // mana cost = 15
//		return damage;
//
//	case 4: // Healing Wave
//		//this does no dmg
//		printf("You Healed yourself, you dealt no damage");
//		return damage;
//	}
//}
//
//double critHit(int chance, double multi) { //insert the % chance of a crit occuring and the resulting multiplier as an argument
//	int crit = RNG(100, 1);
//	if (crit > (100-chance)) { //10% crit chance
//		return 1*multi;
//	}
//	else {
//		return 1;
//	}
//}

//Other

//Display Current Character Stats on Screen
void printCharacter(PC player) {	
	printf("\n%s\n", player.name);
	printf("Hp:	%d\nMp:	%d\nStr:	%d\nInt:	%d\nDef:	%d\nSpd:	%d\n",
		player.stats[0], player.stats[1], player.stats[2], player.stats[3], player.stats[4], player.stats[5]);
}
