#include <iostream>
using namespace std;
int main() {
  int numStones,maxJumps;
  cin >> numStones >> maxJumps;
  int stones[numStones];
  for (int i = 0; i < numStones; i++) {
    cin >> stones[i];
  }
  int possibleHome[numStones];// 0 = false, 1 = true, 2 = undecided
  for (int i = 0; i < numStones; i++) {
    possibleHome[i] = 2;
  }
  for (int i = 0; i < numStones; i++) {
    int currentStonePapa = i;
    int currentStoneBaby = i;
    for (int j = 0; j < maxJumps; j++) {
      int papaOffset = 1;
      int babyOffset = 1;
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
      if (possibleHome[i] != 0) {
        while (true) {
          // baby move
          if (currentStoneBaby - babyOffset >= 0 && stones[currentStoneBaby - babyOffset] > stones[currentStoneBaby]) {
            currentStoneBaby = currentStoneBaby - babyOffset;
            break;
          } else if (currentStoneBaby + babyOffset < numStones && stones[currentStoneBaby + babyOffset] > stones[currentStoneBaby]) {
            currentStoneBaby = currentStoneBaby + babyOffset;
            break;
          } else {
            babyOffset++;
          }
          if (currentStoneBaby + babyOffset >= numStones && currentStoneBaby - babyOffset < 0) {
            possibleHome[i] = 0;
            break;
          }
        }
        if (possibleHome[i] == 0) {
          break;
        }
      }
      if (currentStoneBaby == currentStonePapa && possibleHome[i] == 2) {
        possibleHome[i] = 1;
        break;
      }
    }
    if (possibleHome[i] == 2) {
      possibleHome[i] = 0;
    }
  }
  for (int i = 0; i < numStones; i++) {
    cout << possibleHome[i];
  }
  cout << endl;
}
