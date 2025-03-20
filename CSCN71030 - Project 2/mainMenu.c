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

	printf(" U   U  N   N  TTTTT  IIIII  TTTTT  L      EEEEE  DDDD     RRRR    PPPP    GGG \n");
	printf(" U   U  NN  N    T      I      T    L      E      D   D    R   R   P   P  G   \n");
	printf(" U   U  N N N    T      I      T    L      EEEE   D   D    RRRR    PPPP   G  GG\n");
	printf(" U   U  N  NN    T      I      T    L      E      D   D    R  R    P      G   G\n");
	printf("  UUU   N   N    T    IIIII    T    LLLLL  EEEEE  DDDD     R   R   P       GGG");
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