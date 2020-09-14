#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
// all players start with 10hp, and Shadow with 60hp
struct player {
  int pos;
  int dmg;
  int hp;
  bool operator < (player other) const {
    return pos < other.pos;
  }
  bool operator > (player other) const {
    return pos > other.pos;
  }
  bool operator == (player other) const {
    return pos == other.pos;
  }
};
int main() {
  int numPlayers;
  cin >> numPlayers;
  vector <player> players;
  int totalDmg = 0;
  for (int i = 0; i < numPlayers; i++) {
    int position,damage;
    cin >> position >> damage;
    totalDmg += damage;
    player newPlayer;
    newPlayer.pos = position;
    newPlayer.dmg = damage;
    newPlayer.hp = 10;
    players.push_back(newPlayer);
  }
  player shadow;
  cin >> shadow.pos >> shadow.dmg;
  shadow.hp = 60;
  players.push_back(shadow);
  sort(players.begin(),players.end());
  for (int i = 0; i < players.size(); i++) {
    if (players[i].pos == shadow.pos) {
      shadow.pos = i;
      break;
    }
  }
  while (true) {
    //shadowAttack
    if (shadow.pos == 0) {
      players[1].hp -= shadow.dmg;
      if (players[1].hp <= 0) {
        totalDmg -= players[1].dmg;
        players.erase(players.begin()+1);
      }
    } else if (shadow.pos == players.size()-1) {
      players[players.size()-2].hp -= shadow.dmg;
      if (players[players.size()-2].hp <= 0) {
        totalDmg -= players[players.size()-2].dmg;
        players.erase(players.begin()+players.size()-2);
        shadow.pos--;
      }
    } else {
      players[shadow.pos-1].hp -= shadow.dmg;
      players[shadow.pos+1].hp -= shadow.dmg;
      if (players[shadow.pos-1].hp <= 0) {
        totalDmg -= players[shadow.pos-1].dmg;
        players.erase(players.begin()+shadow.pos-1);
        shadow.pos--;
      }
      if (players[shadow.pos+1].hp <= 0) {
        totalDmg -= players[shadow.pos+1].dmg;
        players.erase(players.begin()+shadow.pos+1);
      }
    }
    if (players.size() == 1) {
      cout << "Shadow wins!\n";
      return 0;
    }
    //playersAttack
    shadow.hp -= totalDmg;
    if (shadow.hp <= 0) {
      cout << "We win! Players alive:";
      for (int i = 0; i < players.size(); i++) {
        if (i != shadow.pos) {
          cout << ' ' << players[i].pos;
        }
      }
      cout << endl;
      return 0;
    }
  }
}
