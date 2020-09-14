#include <iostream>
using namespace std;
int main() {
  int numPics,numAllowed;
  cin >> numPics >> numAllowed;
  int pics[numPics];
  bool allNegative = true;
  for (int i = 0; i < numPics; i++) {
    cin >> pics[i];
    if (pics[i] > 0) {
      allNegative = false;
    }
  }
  if (allNegative) {
    int largest = -1234567890;
    for (int i = 0; i < numPics; i++) {
      if (pics[i] > largest) {
        largest = pics[i];
      }
    }
    cout << largest << endl;
    return 0;
  } else {
    int largestSequenceSum = 0;
    int currentSequenceSum = 0;
    bool sequenceStarted = false;
    for (int i = 0; i < numPics; i++) {
      if (sequenceStarted) {
        if (pics[i] < 0) {
          if (currentSequenceSum > largestSequenceSum) {
            largestSequenceSum = currentSequenceSum;
          }
          sequenceStarted = false;
          currentSequenceSum = 0;
        } else {
          currentSequenceSum += pics[i];
        }
      } else {
        if (pics[i] > 0) {
          currentSequenceSum += pics[i];
          sequenceStarted = true;
        }
      }
    }
  }
}
