#include "Storyline.h"
#include "Windows.h"

void storyBegins() {
    int userInput;
        printf("          # #### ####  \n");
        printf("       ### \/#|### |/####\n");
        printf("      ##\/#/ \||/##/_/##/_#\n");
        printf("    ###  \/###|/ \/ # ##_###\n");
        printf("  ##_\_#\_\## | #/###_/_####?#\n");
        printf(" ## #### # \ #| /  #### ## / ##\n");
        printf("  __#_--###`  |{,###---###-~\n");
        printf("            \ }{\n");
        printf("             }}{\n");
        printf("             }}{\n");
        printf("             {{}\n");
        printf("        , -=-~{ .-^- _\n");
        Sleep(1000);
        printf("You wake up in the middle of the woods, with your head pounding.\n");
        Sleep(2000);
        printf("The damp earth clings to your clothes, and the scent of pine and decay lingers in the air.\n");
        Sleep(2000);
        printf("Shadows stretch between the trees as a cold breeze cuts through the silence.\n");
        Sleep(2000);
        printf("Your body aches, but nothing seems broken. Your weapons and supplies are gone, but your gear remains.\n");
        Sleep(2000);
        printf("It's as if someone wanted you alive, but defenseless...\n");
        Sleep(2000);
        printf("You have no memory of how you got here. \n");
        Sleep(2000);
        printf("Through the trees to your right, you see the distant glow of lanterns.\n");
        Sleep(2000);
        printf("It is a small village, quiet but eerily familiar.\n");
        Sleep(2000);
        printf("To your left, the woods grow darker and denser, the path uncertain.\n");
        Sleep(2000);
        printf("Which way do you go?");
        printf("(1) To the forest! or (2) To the Village: ");
        scanf("%d", &userInput);
        if (userInput == 1) {
            printf("No turning back now. Your adventure begins!\n ");
            return;
        }
        else {
            printf("The villagers recognize you the moment you step foot inside.\n");
            Sleep(2000);
            printf("Angry murmurs turn into shouts.\n");
            printf("Before you can react, fists and boots drive you back into the dirt.\n");
            printf("You wake up in the woods again, battered and bruised. (Lose -2 HP) \n");
            storyBegins();
        }
    }


void actOne() {

}
void actTwo() {

}
void actThree() {

}
void finalBoss() {

}