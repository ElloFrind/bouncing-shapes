#include <iostream>
using namespace std;
int main() {
  int numRows,numColumns;
  cin >> numRows >> numColumns;
  int startx,starty,endx,endy;
  cin >> startx >> starty >> endx >> endy;
  startx--;
  starty--;
  endx--;
  endy--;
  if (starty == 0 && endy == 0) {
    int total = 0;
    for (int i = startx; i <= endx; i++) {
      int currentNum;
      cin >> currentNum;
      total += currentNum;
    }
    cout << total << endl;
    return 0;
  } else if (starty == 1 && endy == 1){
    for (int i = 0; i < numColumns; i++) { // get rid of the first line
      int currentNum;
      cin >> currentNum;
    }
    int total = 0;
    for (int i = startx; i <= endx; i++) {
      int currentNum;
      cin >> currentNum;
      total += currentNum;
    }
    cout << total << endl;
    return 0;
  }
  int topTotal = 0;
  int bottomTotal = 0;
  int bestTotal = 0;
  int topNums[numColumns];
  for (int i = 0; i < numColumns; i++) {
    cin >> topNums[i];
  }
  int bottomNums[numColumns];
  for (int i = 0; i < numColumns; i++) {
    cin >> bottomNums[i];
  }
  for (int i = startx; i <= endx; i++) {
    if (topNums[i] > 0) {
      topTotal += topNums[i];
    }
  }
  topTotal += bottomNums[endx];
  bestTotal = topTotal;
  for (int i = endx-1; i >= startx; i--) {
    if (topNums[i+1] > 0) {
      topTotal -= topNums[i+1];
    }
    if (bottomNums[i] > 0) {
      bottomTotal += bottomNums[i];
    }
    if (topTotal + bottomTotal > bestTotal) {
      bestTotal = topTotal + bottomTotal;
    }
  }
  cout << bestTotal << endl;
}
