#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int numBasks;
  cin >> numBasks;
  int baskValues[numBasks];
  for (int i = 0; i < numBasks; i++) {
    cin >> baskValues[i];
  }
  if (numBasks == 1) {
    cout << baskValues[0] << endl;
  } else if (numBasks == 2) {
    cout << baskValues[0]+baskValues[1] << endl;
  } else {
    int baskTotals[numBasks][3]; // 0 before this, 1 before this, and 2 before this
    baskTotals[0][0] = baskValues[0];
    baskTotals[0][1] = -1;
    baskTotals[0][2] = -1;
    baskTotals[1][0] = baskValues[1];
    baskTotals[1][1] = baskValues[0] + baskValues[1];
    baskTotals[1][2] = -1;
    for (int i = 2; i < numBasks; i++) {
      baskTotals[i][0] = max(baskTotals[i-2][0],max(baskTotals[i-2][1],baskTotals[i-2][2])) + baskValues[i];
      baskTotals[i][1] = baskTotals[i-1][0] + baskValues[i];
      baskTotals[i][2] = baskTotals[i-1][1] + baskValues[i];
    }
    int largest = -1;
    for (int i = 1; i <= 2; i++) {
      for (int j = 0; j < 3; j++) {
        if (baskTotals[numBasks-i][j] > largest) {
          largest = baskTotals[numBasks-i][j];
        }
      }
    }
    cout << largest << endl;
  }
}
