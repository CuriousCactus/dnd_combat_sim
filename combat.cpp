#include "./dndcs.h"

vector<string> roll_initiative() {
  vector<string> initiative_order = {"A1", "B1"};
  return initiative_order;
}

string assign_target(string combatant) {
  string target;
  if (combatant == "A1") {
    target = "B1";
  } else {
    target = "A1";
  }
  return target;
}

string attack(string combatant, string target) {
  return "Ouch!";
}

string combat() {
  vector<string> initiative_order = roll_initiative();
  int combatant_count = initiative_order.size();
  string who_won = initiative_order[0];
  who_won = who_won.at(0);
  bool both_alive = true;
  while (both_alive == true) {
    for (int i = 0; i < combatant_count; i++) {
      string combatant = initiative_order[i];
      string target = assign_target(combatant);
      string result = attack(combatant, target);
      std::cout << combatant << " targets " << target << ", " << result << endl;
    }
    both_alive = false;
  }
  cout << "Winner: Team " << who_won << endl;
  return who_won;
}

int main() {
  combat();
  return 0;
}
