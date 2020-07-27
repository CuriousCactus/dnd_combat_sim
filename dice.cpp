/*
* dice rolling for dnd combat simulator
*/

#include "dndcs.h"

// rolls a specified number of specified dice
int dice_roll(int number_of_dice, int number_of_faces) {
    int result = 0;
    for (int i=0; i<number_of_dice; i++)
        result += 1 + rand() % number_of_faces;
    return result;
}

// initialises random number generator
// N.B. takes one second to get a new seed
void dice_init() {
    srand(time(NULL));
}
