#define _CRT_SECURE_NO_WARNINGS
#include "gameFunctions.h"
#include "PlayerCharacter.h"
#include "mainMenu.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


// Matthew Romano - CSCN71030_Section2_Group3 - Main Menu Implenentation

// starts the main menu and works as a hub for it
int mainMenuStart() {
	printf("  RRRRR   EEEEE   JJJJJ  EEEEE  CCCCC  TTTTT  EEEEE  DDDD     RRRRR   PPPP    GGG\n");
	printf("  R    R  E         J    E     C         T    E      D   D    R    R  P   P  G\n");
	printf("  RRRRR   EEEE      J    EEEE  C         T    EEEE   D   D    RRRRR   PPPP   G  GG\n");
	printf("  R   R   E      J  J    E     C         T    E      D   D    R   R   P      G   G\n");
	printf("  R    R  EEEEE   JJ     EEEEE  CCCCC    T    EEEEE  DDDD     R    R  P       GGG");
	printf("\n\nCreated by: Group 3");
	Sleep(3250);
	int arrowPos = 1;

	// clears window and calls menu for the first time
	system("cls");
	mainMenu(arrowPos);

	// infinite loop for now
	while (1) {
		int keyPressed = getch(); // takes input
		switch (keyPressed) {

		case 13: // enter key allows for selection
			if (arrowPos == 1)
				return 1;
			if (arrowPos == 2)
				return 2;
			if (arrowPos == 3)
				exit(EXIT_SUCCESS);
			mainMenu(arrowPos);
			break;

		case 27: // escape key quits
			exit(EXIT_SUCCESS);
			break;

		case 72: // up arrow
			if (arrowPos == 1) // loops back around
				arrowPos = MENU_OPTIONS + 1;
			mainMenu(--arrowPos);
			break;

		case 80: // down arrow
			if (arrowPos == 3) // loops back around also
				arrowPos = 0;
			mainMenu(++arrowPos);
			break;

		}
	}

	return 0;
}

// this is seperate so that the user can scroll though menu options
void mainMenu(int arrowPos) {
	system("cls");
	printf("Main Menu\n\n");

	// saves all menu options as an array of strings
	char options[][OPTION_NAME_LENGTH] = { "New Game", "Load Game", "Exit" };

	// prints out menu options 1 by 1
	for (int i = 0; i < MENU_OPTIONS; i++) {
		if (arrowPos == i + 1)  // print arrow if at that position
			printf("--> %s\n", options[i]);

		else
			printf("    %s\n", options[i]);
	}

	printf("\n"); // for better formatting

}