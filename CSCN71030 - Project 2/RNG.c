// Ryan Hackabrt - CSCN7130_Section2_Group3 - RNG Events Implemetnation

#include "RNG.h"
#include <stdio.h>

// srand(time(NULL));	Must be input once game is started for RNG to work properly (otherwise will be the same set of numbers)


// this is the function to be used in any "random event" or "Dice Roll"
int RNG(int max, int min) {
	int val = rand() % (max - min + 1) + min;
	return val;
}