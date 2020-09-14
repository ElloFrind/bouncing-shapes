#include <iostream>
using namespace std;
struct space {
  int x;
  int y;
  int value;
  bool operator < (space other) const {
    return value < other.value;
  }
  bool operator > (space other) const {
    return value > other.value;
  }
}
int main() {
  int numRows,numColumns,startx,starty,endx,endy;
  cin >> numRows >> numColumns >> startx >> starty >> endx >> endy;
  int grid[numRows][numColumns];
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numColumns)
  }
}
