#define _CRT_SECURE_NO_WARNINGS
#include "gameFunctions.h"
#include "PlayerCharacter.h"
#include "mainMenu.h"
#include <stdio.h>
#include <stdlib.h>


// Matthew Romano - CSCN71030_Section2_Group3 - Main Menu Implenentation

// so far not returning anything (should be fine)
int mainMenu() { 
	// needs three options Exit Game (0), Create New Save File (1), Load Save File (2)
	int selection = 0;

	printf("  RRRRR   EEEEE   JJJJJ  EEEEE  CCCCC  TTTTT  EEEEE  DDDD     RRRRR   PPPP    GGG\n");
	printf("  R    R  E         J    E     C         T    E      D   D    R    R  P   P  G\n");
	printf("  RRRRR   EEEE      J    EEEE  C         T    EEEE   D   D    RRRRR   PPPP   G  GG\n");
	printf("  R   R   E      J  J    E     C         T    E      D   D    R   R   P      G   G\n");
	printf("  R    R  EEEEE   JJ     EEEEE  CCCCC    T    EEEEE  DDDD     R    R  P       GGG");
	printf("\n\n1 FOR NEW GAME\n\n2 TO LOAD GAME\n\n0 TO EXIT GAME\n\n");
	do {
		// all scanfs are giving warnings but whatever
		printf("SELECTION: ");
		scanf("%d", &selection);
		while (selection > 2 || selection < 0) {								// input validation
			printf("\n\nINVALID INPUT, PLEASE ENTER NEW SELECTION: ");
			scanf("%d", &selection);
		}
	
	switch (selection) {
	case 1:
		return 1;	// new game
		break;
	case 2:
		return 2;	// load game
		break;
	case 0:
		return 0;	// exit game
		break;
	}
	} while (selection > 2 || selection < 0);
}