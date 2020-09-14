#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int numPics,numAllowed;
  cin >> numPics >> numAllowed;
  int pics[numPics];
  for (int i = 0; i < numPics; i++) {
    cin >> pics[i];
  }
  int dp[numPics][numAllowed];
  for (int i = 0; i < numPics; i++) {
    for (int j = 0; j < numAllowed; j++) {
      dp[i][j] = -1234567890;
    }
  }
  if (numAllowed == 1){
    int largest = -1234567890;
    for (int i = 0; i < numPics; i++) {
      if (pics[i] > largest) {
        largest = pics[i];
      }
    }
    cout << largest << endl;
    return 0;
  } else {
    dp[0][0] = pics[0];
  }
  for (int i = 1; i < numPics; i++) {
    dp[i][0] = pics[i];
    for (int j = 1; j < numAllowed; j++) {
      dp[i][j] = dp[i-1][j-1] + pics[i];
    }
  }
  int largest = -1234567890;
  for (int i = 0; i < numPics; i++) {
    for (int j = 0; j < numAllowed; j++) {
      if (dp[i][j] > largest) {
        largest = dp[i][j];
      }
    }
  }
  cout << largest << endl;
  return 0;
}
