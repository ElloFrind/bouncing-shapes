#include <iostream>
#include <utility>
using namespace std;
int main() {
  int numPeople,numRounds;
  cin >> numPeople >> numRounds;
  pair<int,int> value[numRounds]; // first/second
  for (int i = 0; i < numRounds; i++) {
    value[i].first = 0;
    value[i].second = 0;
  }
  for (int i = 0; i < numPeople; i++) {
    float highestValue = 0;
    int bestRound;
    for (int j = 0; j < numRounds; j++) {
      value[j].second++;
      float newValue = value[j].first+1/value[j].second;
      if (newValue > highestValue) {
        highestValue = newValue;
        bestRound = j;
      }
    }
  }
}
