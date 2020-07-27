/*
* dice rolling for dnd combat simulator
*/

#include "dndcs.h"
#include <cstdlib>

int dice_roll(int number_of_dice, int number_of_faces) {
    int result = 0;
    for (int i=0; i<number_of_dice; i++)
        result += rand() % number_of_faces;
    return result;
}
