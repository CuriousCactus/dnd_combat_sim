/*
* dice rolling for dnd combat simulator
*/

#include "dndcs.h"

int dice_roll(int number_of_dice, int number_of_faces) {
    int result = 0;
    for (int i=0; i<number_of_dice; i++)
        result += 1 + rand() % number_of_faces;
    return result;
}
