#pragma once
#include <stdio.h>
#include "Windows.h" 
#include "gameFunctions.h"
#include "PlayerCharacter.h"
#include "RNG.h"

void storyBegins(PC *player);
void storyBeginsAgain(PC *player);
void actOne(PC *player);
void actTwo(PC *player);
void actThree();
void finalBoss();
int checkPoint(int newCheckpoint);
int getUserChoice(int min, int max);
int handleRandomEvent(int numEvents);