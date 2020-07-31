/*
* header file for dnd combat simulator
*/
#include <iostream>
#include <string>
#include <vector>
#include <time.h> // for time(NULL)
#include <cstdlib> // for rand()

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::ostream;

// dice.cpp
int dice_roll(int number_of_dice, int number_of_faces);
void dice_init();

// creature.cpp
class Creature {
public:
    // initialization
    Creature();
    Creature(const Creature&);
	Creature(string name, int hp_max, int ac, int attack_bonus,
             int damge_dice_number, int damage_dice_faces,
             int damage_bonus, int initiative_bonus);

    // destruction
	~Creature();

    // copying
	Creature& operator=(const Creature&);

    // combat
    bool alive() const;
    bool defend(int to_hit) const;
    void take_damage(int damage);
    void attack(Creature& target);

    // stream <<
	friend ostream& operator<< (ostream&,const Creature&);
	friend istream& operator>> (istream&, Creature&);

    // name stuff
    string get_name() const;
    void rename(const string);

private:
    string name;
	int hp_max;
    int hp;
    int ac;
    int attack_bonus;
    int damge_dice_number;
    int damage_dice_faces;
    int damage_bonus;
    int initiative_bonus;

    void copy(const Creature&);
};
