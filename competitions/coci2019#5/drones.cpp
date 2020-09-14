#include <iostream>
using namespace std;
int main() {
  int numDrones;
  cin >> numDrones;
  int good[numDrones];
  int bad[numDrones];
  bool taken[numDrones];
  for (int i = 0; i < numDrones; i++) {
    cin >> good[i];
  }
  for (int i = 0; i < numDrones; i++) {
    cin >> bad[i];
  }
  int bestTotal = 0;
  for (int i = -10; i <= 10; i++) {
    int currentTotal = 0;
    for (int j = 0; j < numDrones; j++) {
      good[j] += i;
      taken[j] = false;
    }
    for (int j = 0; j < numDrones; j++) {
      for (int k = 0; k < numDrones; k++) {
        if (good[j] == bad[k] && taken[k] == false) {
          currentTotal++;
          taken[k] = true;
          break;
        }
      }
    }
    for (int j = 0; j < numDrones; j++) {
      good[j] -= i;
      taken[j] = false;
    }
    if (currentTotal > bestTotal) {
      bestTotal = currentTotal;
    }
  }
  cout << bestTotal << endl;
}
