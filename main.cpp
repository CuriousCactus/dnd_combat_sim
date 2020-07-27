/*
* main file of dnd combat simulator
* currently compiles with:
*    g++ -o dndcs main.cpp dice.cpp
*/

#include "dndcs.h"

int main (int argc, char *argv[]) {
    // command line arguments
    if (argc > 1) {
        // collecting command line arguments
        vector<string> args(argv + 1, argv + argc);

        /* initialize random seed: */
        srand (time(NULL));

        /* rolling some dice */
        if (args.size() >= 2) {
            cout << "Rolling " << args[0] << "d" << args[1] << endl;
            cout << dice_roll( std::stoi(args[0]), std::stoi(args[1])) << endl;
        }
    }

    return 0;
}
