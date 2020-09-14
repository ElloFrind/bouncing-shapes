#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main() {
  int numPeople,height;
  cin >> numPeople >> height;
  vector <pair<int,int> > carved;// effectively the pole; keeps track of carved places, inclusive then exclusive
  int numCarvings = 0;
  int persona;
  cin >> persona;
  persona--;
  carved.push_back(make_pair(persona,persona+1));
  numCarvings++;
  for (int i = 1; i < numPeople; i++) {
    int person;
    cin >> person;
    person--;
    int carveBlock = carved.size()-1;
    while (true) {
      if (carved[carveBlock].first-1 <= person && carved[carveBlock].second > person) {
        if (carved[carveBlock].first == 0) {
          break;
        }
        carved[carveBlock].first--;
        numCarvings++;
        if (carveBlock != 0) {
          if (carved[carveBlock-1].second == carved[carveBlock].first) {
            carved[carveBlock-1].second = carved[carveBlock].second;
            carved.erase(carved.begin()+carveBlock);
          }
        }
        break;
      } else {
        if (carveBlock == 0) {
          carved.emplace(carved.begin(),make_pair(person,person+1));
          numCarvings++;
          break;
        } else {
          if (carved[carveBlock-1].second == person) {
            carved[carveBlock-1].second++;
            numCarvings++;
            if (carveBlock < carved.size()) {
              if (carved[carveBlock+1].first == carved[carveBlock].second) {
                carved[carveBlock+1].first = carved[carveBlock].first;
                carved.erase(carved.begin()+carveBlock);
              }
            }
            break;
          } else if (person > carved[carveBlock-1].second) {
            carved.emplace(carved.begin()+carveBlock,make_pair(person,person+1));
            numCarvings++;
            break;
          } else {
            carveBlock--;
            // continue with another iteration of this while loop
          }
        }
      }
    }
  }
  cout << numCarvings << endl;
}
