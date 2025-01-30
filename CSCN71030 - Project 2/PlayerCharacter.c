// Ryan Hackabrt - CSCN7130_Section2_Group3 - PlayerCharacter Implementation

#include "PlayerCharacter.h"
#include <stdio.h>


// Character Selection Menu
int CharacterSelectMenu() {	//TODO: UPDATE Visuals
	int selection = 0;
	printf("Please Pick a Character\n");
	printf("\nROGUE = 1\n\nWARRIOR = 2\n\nMAGE = 3\n\nEXIT TO MAIN MENU = 0");
	do {
		printf("SELECTION: ");
		scanf("%d", &selection);
		if (selection > 3 || selection < 0)								// input validation
			printf("\n\nINVALID INPUT, PLEASE ENTER NEW ");
	} while (selection > 3 || selection < 0);

	selection--;	//just to make enums and switch case easier to read, not necessary
	
	return selection;
}

// Character Creation

PC SetCharacter(int c) {
	PC newChar = { 0 };
	int rogue[STATS_ARRAY] = { 75, 50, 15, 10, 10, 20 };
	int warrior[STATS_ARRAY] = { 75, 50, 15, 10, 10, 20 }; 
	int mage[STATS_ARRAY] = { 75, 50, 15, 10, 10, 20 }; 

	switch (c) {
	case ROG:
		strncpy(newChar.name, "Rogue", MAX_NAME);	//TODO: Not finished
		UpdateStats(newChar, rogue);
	case WAR:
		strncpy(newChar.name, "Warrior", MAX_NAME);
		UpdateStats(newChar, warrior);
	case MAG:
		strncpy(newChar.name, "Mage", MAX_NAME);
		UpdateStats(newChar, mage);
	}
}

// Updating stats
bool UpdateStats(PC Player, int arr[]) {

}
bool TakeDamage(int dmg) {

}

// Combat Movesets


//Save/Load to/from file
