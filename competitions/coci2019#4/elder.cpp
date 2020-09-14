#include <iostream>
#include <set>
using namespace std;
// use char - 65
int main() {
  char wandHolder;
  cin >> wandHolder;
  int numDuels;
  cin >> numDuels;
  int numHolders = 1;
  set <char> holders;
  holders.insert(wandHolder);
  for (int i = 0; i < numDuels; i++) {
    char win,lose;
    cin >> win >> lose;
    if (wandHolder == lose) {
      wandHolder = win;
      if (holders.find(win) == holders.end()) {
        numHolders++;
        holders.insert(win);
      }
    }
  }
  cout << wandHolder << '\n' << numHolders << '\n';
}
