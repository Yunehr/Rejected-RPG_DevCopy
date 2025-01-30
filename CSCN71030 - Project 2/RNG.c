// Ryan Hackabrt - CSCN7130_Section2_Group3 - RNG Events Implemetnation

#include "RNG.h"
#include <stdio.h>

#define ONE	1

// srand(time(NULL));	Must be input once game is started for RNG to work properly (otherwise will be the same set of numbers)


// this is the function to be used in any "random event" or "Dice Roll"
int RNG(int maxVal, int mod) {
	int val = rand() % (maxVal + ONE);
	return val + mod;
}