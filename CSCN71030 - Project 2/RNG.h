#pragma once

// Ryan Hackabrt - CSCN7130_Section2_Group3 - RNG Events ADT

// srand(time(NULL));	Must be input once game is started for RNG to work properly (otherwise will be the same set of numbers)

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// random number generator function
int RNG(int max, int min);