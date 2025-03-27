#define _CRT_SECURE_NO_WARNINGS
#include "Storyline.h"

int checkPoint(int newCheckpoint) {

    static int currentCheckPoint = 0;

    if (newCheckpoint > 0) {
        currentCheckPoint = newCheckpoint;
    }

    return currentCheckPoint;
}
int getUserChoice(int min, int max) {
    int choice;
    while (1) {
        printf("Enter your choice (%d-%d): ", min, max);
        if (scanf("%d", &choice) == 1 && choice >= min && choice <= max) {
            return choice; // Valid input, return choice
        }
        // Flush invalid input
        printf("Invalid choice. Please enter a number between %d and %d.\n", min, max);
        while (getchar() != '\n');
    }
}

int handleRandomEvent(int numEvents) {
    return RNG(numEvents, 1); // Returns a random event ID from 1 to numEvents
}


void storyBegins(PC* player) {
    int userInput;
    checkPoint(1); //checkpoint
    printf("          # #### ####  \n");
    printf("       ### \\/#|### |/####\n");
    printf("      ##\\/#/\\||/##/_/##/_#\n");
    printf("    ### \\/###|/\\/ # ##_###\n");
    printf("  ##_\\_#\\_\\| #/###_/_####?#\n");
    printf(" ## #### #\\ #| /  #### ## / ##\n");
    printf("  __#_--###`  |{,###---###-~\n");
    printf("           \\}{{\n");
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
    printf("Which way do you go?\n");
    printf("(1) To the forest! or (2) To the Village: ");
    userInput = getUserChoice(1, 2);
    if (userInput == 1) {
        printf("No turning back now. Your adventure begins!\n ");
    }
    else {
        printf("The villagers recognize you the moment you step foot inside.\n");
        Sleep(2000);
        printf("Angry murmurs turn into shouts.\n");
        Sleep(2000);
        printf("Before you can react, fists and boots drive you back into the dirt.\n");
        Sleep(2000);
        printf("You wake up in the woods again, battered and bruised. (Lose -2 HP) \n");
        Sleep(3000);
        storyBeginsAgain(player);
    }
    return;
}
void storyBeginsAgain(PC* player) {
    int userInput;
    checkPoint(100);
    printf("          # #### ####  \n");
    printf("       ### \\/#|### |/####\n");
    printf("      ##\\/#/\\||/##/_/##/_#\n");
    printf("    ### \\/###|/\\/ # ##_###\n");
    printf("  ##_\\_#\\_\\| #/###_/_####?#\n");
    printf(" ## #### #\\ #| /  #### ## / ##\n");
    printf("  __#_--###`  |{,###---###-~\n");
    printf("           \\}{{\n");
    printf("             }}{\n");
    printf("             }}{\n");
    printf("             {{}\n");
    printf("        , -=-~{ .-^- _\n");
    printf("You wake up in the middle of the woods, with your head pounding.\n");
    printf("The damp earth clings to your clothes, and the scent of pine and decay lingers in the air.\n");
    printf("Shadows stretch between the trees as a cold breeze cuts through the silence.\n");
    printf("Your body aches, but nothing seems broken. Your weapons and supplies are gone, but your gear remains.\n");
    printf("It's as if someone wanted you alive, but defenseless...\n");
    printf("You have no memory of how you got here. \n");
    printf("Through the trees to your right, you see the distant glow of lanterns.\n");
    printf("It is a small village, quiet but eerily familiar.\n");
    printf("To your left, the woods grow darker and denser, the path uncertain.\n");
    printf("Which way do you go?");
    printf("(1) To the forest! or (2) To the Village: ");
    userInput = getUserChoice(1, 2);
    if (userInput == 1) {
        printf("No turning back now. Your adventure begins!\n ");
    }
    else {
        printf("The villagers recognize you the moment you step foot inside.\n");
        printf("Angry murmurs turn into shouts.\n");
        Sleep(2000);
        printf("Before you can react, fists and boots drive you back into the dirt.\n");
        Sleep(2000);
        printf("You wake up in the woods again, battered and bruised. (Lose -2 HP) \n");//Need to add in function to remove health
        Sleep(3000);
        storyBeginsAgain(player);
    }
    return;
}

void actOne(PC* player) {
    int userInput;
    checkPoint(2);
    printf("\nThe scent of damp earth and crushed leaves fills the air as you weave through the underbrush.\n");
    Sleep(2000);
    printf("Your hands stained with berry juice from picking the small red berries you find in the bushes.\n");
    Sleep(2000);
    printf("A cool breeze rustles the trees, whispering secrets you can't quite decipher.\n");
    Sleep(2000);
    printf("Up ahead, a small figure sits in the middle of the path. \n");
    Sleep(2000);
    printf("       __\n");
    printf("      / \\`\\         __\n");
    printf("     |  \\ `\\       /` /\\ \n");
    printf("      \\_/`\\  \\-\"\"-/`/\\  \\ \n");
    printf("           |       |  \\  | \n");
    printf("           (d     b)   \\_/\n");
    printf("           /       \\ \n");
    printf("      , -.|.'.\\_/.'.|.-,\n ");
    printf("     /   /\\' _|_ '/\\   \\ \n");
    printf("      |  /  '-`-`-'  \\  |\n");
    printf("      | |             | |\n");
    printf("      | \\    \\   /    / |\n");
    printf("       \\ \\    \\ /    / /\n");
    printf("        `-`\\   :   /'-'\n");
    printf("            `--`--`\n");
    Sleep(2000);
    printf("It's a bunny! White, small, fluffy, and sporting an adorable pair of droopy ears.\n");
    printf("It tilts its head at you, completely unbothered by your approach. \n");
    printf("You pause. What do you do?\n");
    printf("(1) Offer the bunny a berry or (2) Kick the bunny out of your way: \n");
    userInput = getUserChoice(1, 2);
    if (userInput == 1) {
        printf("You crouch, extending a berry toward the tiny creature.\n");
        Sleep(2000);
        printf("The bunny sniffs, hesitates, then snatches it with a wiggle of its nose.\n");
        Sleep(2000);
        printf("Nothing happens except, now you know the berries aren't poisonous.\n");
        Sleep(2000);
        printf("A moment later, it hops off the path, disappearing into the underbrush. \n");
        Sleep(2000);
        printf("You shake your head, chuckling at the randomness of it all, and keep walking. \n");
        Sleep(2000);
        printf("The woods thicken,the path narrows and soon, a figure emerges from the shadows.\n");
        Sleep(2000);
        printf("A thief blocks your path, blade drawn. A fight? Just what you've been waiting for.\n");
        combatLoop(player, setEnemy(THIEF));
    }
    else {
        printf("You're on an adventure, no time for distractions.\n");
        Sleep(2000);
        printf("Your foot swings forward but the moment your boot makes contact, the world shifts.\n");
        Sleep(2000);
        printf("The trees around you contort unnaturally, the air turns heavy.\n");
        Sleep(2000);
        printf("the once-innocent bunny erupts into a nightmarish form.\n");
        Sleep(2000);
        printf("Its fur blackens, its eyes glow with malice, and the air trembles with an ancient force now awake.\n");
        Sleep(2000);
        printf("Final Boss Fight Begins.\n");
        Sleep(2000);
        finalBoss(player);
    }
    return;
}

void actTwo(PC* player) {
    int userInput;
    checkPoint(3);
    printf("The trees close in around you, their gnarled branches reaching like skeletal fingers toward the sky.\n");
    Sleep(2000);
    printf("The path beneath your feet is uneven, soft, like something is shifting beneath the surface.\n");
    Sleep(2000);
    printf("A thick mist creeps in, swirling at your ankles.\n");
    Sleep(2000);
    printf("        ..-+#@@@@@@+@@#=..                                                    ..::.-*##*-..        \n");
    printf("     ..:-*@@@@@@@@@@@@@@@@@#+-...                                     ....-++@@@@@@@@@@@@@@@*:..   \n");
    printf("    ....-=-::...:-=*@@@@@@@@@@@#*-..                             ...-*#@@@@@@@@@@+*==-==+**-...   \n");
    printf("                      .:#@@@@@@@@@@@@@*:...::           ...   ..:*@@@@@@@@@@@@+-..                 \n");
    printf("                       ..:*+@@@@@@@@@@@@@++-           .+==*@@@@@@@@@@@@@@*:.                     \n");
    printf("                            ..-*@@@@@@@@@@@@-           .*@@@@@@@@@@@@@#=:..                       \n");
    printf("                             ...=+@@@@@@@=           .*@@@@@@@@@#:..                         \n");
    printf("           .....:--======--:....     .....-*-           .*+#*=:....    ...--=+*###*=-:..        \n");
    printf("     .::..+=-#++@@@@@@@@@@@@@@@#+..                     ...        ..-*+@@@@@@@@@@@@@@@#*+..-:...  \n");
    printf("   ::.++++-*@@@+*@@@@@@@#...-+:#@@+-.                           ..-+@@*+@@@@@@+-...+:*@@@@@+:=+-.-.\n");
    printf("  ...*#*@@@@@+..*@@@@@@=*:..-*:...++@-..                      ..=+#-..=@@@@@@**=..:*-..:#@@@@#++=..\n");
    printf("  .:###@@@@#:. .*@@@@@@@@@@@@#:.  ..-++-.                   ..+@*:.. .=@@@@@@@@@@@@@-. ..+@@@@+*#+.\n");
    printf("     .+@@@@+.   :+@@@@@@@@@@@=.      .=-:.                 .:*+..     .#@@@@@@@@@@@*.    .+@@@@=.  \n");
    printf("      ....... ....#@@@@@@@@+-. ..                                   ....*@@@@@@@@@+. .. .......    \n");
    printf("             ..-+=-=*++#+:.:==:.                                   ..-=+-=*+++*-..-=:.            \n");
    printf("                 ..=#@@@@++...                                         ..=#@@@@@*:..              \n");
    printf("\n");
    Sleep(2000);
    printf("Something...no, someone is watching you.\n");
    Sleep(2000);
    printf("A cloaked figure steps from the shadows, their face completely hidden beneath their hood. \n");
    Sleep(2000);
    printf("The cloaked stranger asks: Do you know who you truly are?\n ");
    Sleep(2000);
    printf("(1) - Yes! I know exactly who I am!\n");
    Sleep(2000);
    printf("(2) - No, tell me the truth! \n");
    Sleep(2000);
    printf("(3) - You talk too much! *attacks the figure* \n");
    userInput = getUserChoice(1, 3);

    if (userInput == 1) {
        increaseStatPC(player, STR, 3);
        printf("Confidence surges through you!(+3 STR) The cloaked figure nods at you and vanishes.\n");
    }
    else if (userInput == 2) {
        increaseStatPC(player, INTEL, 3);
        printf("A deep hum fills the air. The stranger steps closer and whispers forgotten knowledge into your mind before vanishing.(+3 INT)\n");
    }
    else {
        increaseStatPC(player, HP, -5);
        printf("The moment you move, your vision blurs. You're slammed backward by an unseen force, gasping for breath. (-5 HP) \n");
        printf("The figure simply vanishes, leaving you alone.\n");
    }
    Sleep(2000);
    printf("You glance ahead. Two distinct paths emerge: \n");
    Sleep(2000);
    printf("(1) - Enter the cave\n");
    Sleep(2000);
    printf("(2) - Continue down the forest path\n");
    Sleep(2000);
    printf("Which do you choose: \n");
    userInput = getUserChoice(1, 2);

    if (userInput == 1) {
        printf("The air inside is heavy, thick with the scent of wet stone and something ancient.\n");
        Sleep(2000);
        printf("The walls pulse faintly, as if the cave itself is alive. \n");

        int eventID = handleRandomEvent(3);
            switch (eventID) {
            case 1:
            {
                printf("You stumble upon a crystal-clear pool. Its waters shimmer as you kneel, and the moment you drink, warmth floods your veins.\n");
                int poolEffect = handleRandomEvent(3);
                if (poolEffect == 1) {
                    increaseStatPC(player, DEF, 3);
                    printf("A warm sensation spreads through your body. You feel unbreakable. (+3 DEF)\n");
                }
                else if (poolEffect == 2) {
                    increaseStatPC(player, STR, 3);
                    printf("Your blood burns with newfound strength. You feel unstoppable. (+3 STR)\n");
                }
                else {
                    increaseStatPC(player, INTEL, 3);
                    printf("Your thoughts sharpen. Patterns emerge in the chaos. (+3 INT)\n");
                }
                break;
            }
            
            case 2:
            {
                increaseStatPC(player, HP, -5);
                printf("A dart shoots from the wall, piercing your arm. Poison burns your veins (-5 HP)\n");
                Sleep(2000);
                printf("You stumble out of the cave and run down the path.\n");
                break;
            }
            case 3:
            {
                printf("A shadow lunges at you from the dark! You barely raise your arms before the fight begins.\n");
                // Insert combat function
                break;
            }
        }
    }
    else {
        printf("You press forward, leaving the cave behind.\n");
        Sleep(2000);
        printf("The forest around you shifts, the trees twisting in unnatural angles.\n");
        Sleep(2000);
        printf("Ahead, the path ends abruptly. A small hut stands before you.\n");
    }
    return;
}
void actThree(PC* player) {
    int userInput;
    checkPoint(4);
    printf("The forest is dense, suffocatingly quiet.\n");
    Sleep(2000);
    printf("The mist thickens, curling around your ankles like unseen hands.\n");
    Sleep(2000);
    printf("Then... through the trees, you see it.\n");
    Sleep(2000);
    printf("A small wooden hut stands in the middle of the clearing. Smoke curls from the chimney... as if someone has been expecting you\n");
    Sleep(2000);
    printf("You enter the hut. The fire crackles, shadows dancing across the wooden walls, and a tall mirror stands in the corner\n");
    Sleep(2000);
    printf("The figure does not move. The air feels heavier\n");
    Sleep(2000);
    printf("You consider what your next move should be:\n");
    Sleep(2000);
    printf("(1) Approach the figure\n");
    Sleep(2000);
    printf("(2) Look into the mirror\n");
    Sleep(2000);
    printf("(3) Search the hut for answers\n");
    Sleep(2000);
    printf("Which will you choose?\n");
    userInput = getUserChoice(1, 3);
    if (userInput == 1) {
        printf("You step closer to the figure, and for a moment, you see your own face beneath the hood... before they vanish into smoke.(+3 INT)\n");
        increaseStatPC(player, INTEL, 3);
    }
    else if (userInput == 2) {
        printf("Your reflection distorts. It smiles when you do not. The room twists and tilts before you stumble back, gasping.(-3 HP)\n");
        increaseStatPC(player, HP, -5);
    }
    else {
        printf("You find markings carved deep into the walls, symbols of protection, of warning. You press your hand to one, and strength surges through you.(+3 STR)\n");
        increaseStatPC(player, STR, 3);
    }

    printf("The air shifts. The hut creaks, groaning as if it is alive. The door swings open on its own, leading back into the forest.\n");
    Sleep(2000);
    printf("The moment you step outside, the world is not the same\n");
    Sleep(2000);
    printf("The trees are taller, stretching impossibly high.\n");
    Sleep(2000);
    printf("The ground feels wrong, like something is moving beneath it.\n");
    Sleep(2000);
    printf("And then... you see it. Sitting perfectly still. Watching\n");
    printf("The bunny has been waiting for you....\n");
    Sleep(2000);
    printf("The trees around you contort unnaturally, the air turns heavy.\n");
    Sleep(2000);
    printf("the once-innocent bunny erupts into a nightmarish form.\n");
    Sleep(2000);
    printf("Its fur blackens, its eyes glow with malice, and the air trembles with an ancient force now awake.\n");
    Sleep(2000);
    printf("Final Boss Fight Begins.\n");
    Sleep(2000);
    finalBoss(player);
    return;
}

void finalBoss(PC* player) {
    checkPoint(101);
    printf("The earth splits beneath your feet. The sky darkens. The final confrontation begins. \n");
    //insert combat function
    combatLoop(player, setEnemy(FIN));
    return;
}
