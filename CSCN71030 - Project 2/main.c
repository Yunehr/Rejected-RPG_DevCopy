#include "mainMenu.h"
#include "PlayerCharacter.h"
#include "RNG.h"
#include <stdio.h>
#include <stdlib.h>

// CSCN71030_Section2_Group3 - Main class

int main(void) {
	srand(time(NULL));	// need this here while testing RNG

	//mainMenu();	// calls main menu function

	printf("Testing Random Number Generator:\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ",RNG(100, 0));
	}

	printf("\n\nTesting Player Creation Menu:\n");
	CharacterSelect();

	return 0;
}