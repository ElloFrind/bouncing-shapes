#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int numPics,numAllowed;
  cin >> numPics >> numAllowed;
  int pics[numPics];
  for (int i = 0; i < numPics; i++) {
    cin >> pics[i];
  }
  int dp[2][numAllowed];
  for (int i = 0; i < 2; i++) {
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
  int largest = dp[0][0]; // because why not; it could be and it's the first to consider
  for (int i = 1; i < numPics; i++) {
    dp[1][0] = pics[i];
    for (int j = 1; j < numAllowed; j++) {
      dp[1][j] = dp[0][j-1] + pics[i];
    }
    for (int j = 0; j < numAllowed; j++) {
      dp[0][j] = dp[1][j];
      if (dp[0][j] > largest) {
        largest = dp[0][j];
      }
    }
  }
  cout << largest << endl;
  return 0;
}
