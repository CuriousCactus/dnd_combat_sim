/*
* creature class functions for dnd combat simulator
*/

#include "dndcs.h"

// initialiser
Creature::Creature() {
    name = "";
    hp_max = 0;
    hp = 0;
    ac = 0;
    attack_bonus = 0;
    damge_dice_number = 0;
    damage_dice_faces = 0;
    damage_bonus = 0;
    initiative_bonus = 0;
}

// initialiser from another
Creature::Creature(const Creature& cr) {
    copy(cr);
}

// initialiser with arguments
Creature::Creature(string name_in, int hp_max_in, int ac_in,
                   int attack_bonus_in, int damge_dice_number_in,
                   int damage_dice_faces_in, int damage_bonus_in,
                   int initiative_bonus_in) {
    name = name_in;
    hp_max = hp_max_in;
    hp = hp_max;
    ac = ac_in;
    attack_bonus = attack_bonus_in;
    damge_dice_number = damge_dice_number_in;
    damage_dice_faces = damage_dice_faces_in;
    damage_bonus = damage_bonus_in;
    initiative_bonus = initiative_bonus_in;
}

// destructor
Creature::~Creature() {
    // do nothing - it's all automatic
}

// copy
void Creature::copy(const Creature& cr) {
    name = cr.name;
    hp_max = cr.hp_max;
    hp = cr.hp;
    ac = cr.ac;
    attack_bonus = cr.attack_bonus;
    damge_dice_number = cr.damge_dice_number;
    damage_dice_faces = cr.damage_dice_faces;
    damage_bonus = cr.damage_bonus;
    initiative_bonus = cr.initiative_bonus;
}

// copy with = operator
Creature& Creature::operator=(const Creature& cr) {
    copy(cr);
    return *this;
}

// alive
bool Creature::alive() const {
    return hp > 0;
}

// defend
bool Creature::defend(int to_hit) const {
    return ac > to_hit;
}

// void take_damage(int damage);
void Creature::take_damage(int damage) {
    hp -= damage;
}

// attack
void Creature::attack(Creature& target) {
    int to_hit, damage;
    to_hit = dice_roll(1, 20) + attack_bonus;
    if (target.defend(to_hit))
        return;
    damage = dice_roll(damge_dice_number, damage_dice_faces) + damage_bonus;
    target.take_damage(damage);
}

// get name
string Creature::get_name() const {
    return name;
}

// rename
void Creature::rename(const string new_name) {
    name = new_name;
}

// stream <<
ostream& operator<< (ostream& os,const Creature& cr) {
    os << std::left;
	os << "Name              : " << cr.name << endl;
    os << "HP max            : " << cr.hp_max << endl;
    os << "HP                : " << cr.hp << endl;
    os << "AC                : " << cr.ac << endl;
    os << "attack_bonus      : " << cr.attack_bonus << endl;
    os << "damge_dice_number : " << cr.damge_dice_number << endl;
    os << "damage_dice_faces : " << cr.damage_dice_faces << endl;
    os << "damage_bonus      : " << cr.damage_bonus << endl;
    os << "initiative_bonus  : " << cr.initiative_bonus << endl;
    return os;
}

// stream >>
istream& operator>> (istream& is, Creature& cr) {
    is >> cr.name;
    is >> cr.hp_max;
    is >> cr.hp;
    is >> cr.ac;
    is >> cr.attack_bonus;
    is >> cr.damge_dice_number;
    is >> cr.damage_dice_faces;
    is >> cr.damage_bonus;
    is >> cr.initiative_bonus;
    return is;
}
