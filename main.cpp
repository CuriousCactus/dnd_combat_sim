/*
* main file of dnd combat simulator
* currently compiles with:
*    g++ -o dndcs main.cpp dice.cpp
*/

#include "dndcs.h"

int main (int argc, char *argv[]) {

    // collecting command line arguments
    // vector<string> args(argv + 1, argv + argc);

    // initialising dice
    dice_init();

    // an example creature
    Creature alice("Alice", 13, 13, 4, 1, 6, 2, 2);

    // showing the example creature
    cout << endl;
    cout << alice;
    cout << "Alive: " << alice.alive() << endl << endl;

    // copying
    Creature bob;
    bob = alice;
    bob.rename("Bob");

    // showing the copied creature
    cout << bob;
    cout << "Alive: " << bob.alive() << endl << endl;

    // initiative
    cout << "The starter is " << alice.get_name() << "!" << endl;
    cout << endl;

    // having a battle
    while (alice.alive() && bob.alive()) {
        alice.attack(bob);
        if (bob.alive())
            bob.attack(alice);
    }

    // showing results
    string victor = (alice.alive()? alice.get_name(): bob.get_name());
    cout << "The winner is " << victor << "!" << endl;
    cout << endl;

    return 0;
}
