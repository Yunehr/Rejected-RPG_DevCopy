#pragma once
#include <stdio.h>
#include "windows.h" 
#include "gameFunctions.h"
#include "PlayerCharacter.h"
#include "RNG.h"

void storyBegins(PC *player);
void storyBeginsAgain(PC *player);
void actOne(PC *player);
void actTwo(PC *player);
void actThree(PC *player);
void finalBoss(PC *player);
int checkPoint(int newCheckpoint);
int getUserChoice(int min, int max);
int handleRandomEvent(int numEvents);