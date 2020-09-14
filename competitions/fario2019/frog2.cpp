#include <iostream>
using namespace std;
int main() {
  int numStones,maxJumps;
  cin >> numStones >> maxJumps;
  long long stones[numStones];
  for (int i = 0; i < numStones; i++) {
    cin >> stones[i];
  }
  int possibleHome[numStones];// 0 = false, 1 = true, 2 = undecided
  for (int i = 0; i < numStones; i++) {
    possibleHome[i] = 2;
  }
  for (int i = 0; i < numStones; i++) {
    int currentStonePapa = i;
    for (int j = 0; j < maxJumps; j++) {
      int papaOffset = 1;
      while (true) {
        // papa move
        if (currentStonePapa + papaOffset < numStones && stones[currentStonePapa + papaOffset] > stones[currentStonePapa]) {
          currentStonePapa = currentStonePapa + papaOffset;
          break;
        } else if (currentStonePapa - papaOffset >= 0 && stones[currentStonePapa - papaOffset] > stones[currentStonePapa]) {
          currentStonePapa = currentStonePapa - papaOffset;
          break;
        } else {
          papaOffset++;
        }
        if (currentStonePapa + papaOffset >= numStones && currentStonePapa - papaOffset < 0) {
          possibleHome[i] = 0;
          break;
        }
      }
      int currentStoneBaby = currentStonePapa;
      for (int k = 0; k < maxJumps; k++) {
        int babyOffset = 1;
        while (true) {
          // baby move
          if (currentStoneBaby + babyOffset < numStones && stones[currentStoneBaby + babyOffset] < stones[currentStoneBaby]) {
            currentStoneBaby = currentStoneBaby + babyOffset;
            break;
          } else if (currentStoneBaby - babyOffset >= 0 && stones[currentStoneBaby - babyOffset] < stones[currentStoneBaby]) {
            currentStoneBaby = currentStoneBaby - babyOffset;
            break;
          } else {
            babyOffset++;
          }
          if (currentStoneBaby + babyOffset >= numStones && currentStoneBaby - babyOffset < 0) {
            break;
          }
        } // finish computing baby's move
        if (currentStoneBaby == i) {
          possibleHome[i] = 1;
          break;
        }
      } // finish computing all baby's jumps
      if (possibleHome[i] != 2) {
        break;
      }
    } // finish computing for all jumps
    if (possibleHome[i] == 2) {
      possibleHome[i] = 0;
    }
  } // finish computing for all stones
  for (int i = 0; i < numStones; i++) {
    cout << possibleHome[i];
  }
  cout << endl;
}
