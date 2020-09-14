#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  int numLength;
  cin >> numLength;
  string cardStr;
  cin >> cardStr;
  vector <int> cardNum(numLength);
  int xPlace;
  for (int i = 0; i < numLength; i++) {
    switch (cardStr[i]) {
      case '0': cardNum[i] = 0; break;
      case '1': cardNum[i] = 1; break;
      case '2': cardNum[i] = 2; break;
      case '3': cardNum[i] = 3; break;
      case '4': cardNum[i] = 4; break;
      case '5': cardNum[i] = 5; break;
      case '6': cardNum[i] = 6; break;
      case '7': cardNum[i] = 7; break;
      case '8': cardNum[i] = 8; break;
      case '9': cardNum[i] = 9; break;
      case 'x': cardNum[i] = -1; xPlace = i; break;
    }
  }
  if (numLength == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (xPlace == numLength-1) {
    int currentPlace = numLength-2;
    while (currentPlace > 0) {
      cardNum[currentPlace] = cardNum[currentPlace] * 2;
      if (cardNum[currentPlace] > 10) {
        cardNum[currentPlace] = cardNum[currentPlace] % 10 + cardNum[currentPlace] / 10;
      }
      currentPlace -= 2;
    }
    int total = 0;
    for (int i = 0; i < numLength-1; i++) {
      total += cardNum[i];
    }
    cout << (total * 9) % 10 << endl;
    return 0;
  }
  for (int i = 0; i < 10; i++) {
    vector <int> cardNumCopy = cardNum;
    cardNumCopy[xPlace] = i;
    int currentPlace = numLength-2;
    while (currentPlace > 0) {
      cardNumCopy[currentPlace] = cardNumCopy[currentPlace] * 2;
      if (cardNumCopy[currentPlace] > 10) {
        cardNumCopy[currentPlace] = cardNumCopy[currentPlace] % 10 + cardNumCopy[currentPlace] / 10;
      }
      currentPlace -= 2;
    }
    int total = 0;
    for (int j = 0; j < numLength-1; j++) {
      total += cardNumCopy[j];
    }
    total = (total*9)%10;
    if (total == cardNumCopy[numLength-1]) {
      cout << i << endl;
      return 0;
    }
  }
}
