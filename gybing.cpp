#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
struct place {
  int value;
  int fromLeft;
  int fromRight;
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int width,length;
  cin >> width >> length;
  place path[length+1][width];
  for (int i = 0; i < width; i++) {
    path[0][i].value = 0;
    path[0][i].fromLeft = 0;
    path[0][i].fromRight = 0;
  }
  for (int i = 1; i <= length; i++) {
    for (int j = 0; j < width; j++) {
      int newSpot;
      cin >> newSpot;
      path[i][j].value = newSpot;
      path[i][j].fromRight = -1234567890;
      path[i][j].fromLeft = -1234567890;
    }
  }
  for (int i = 0; i < width; i++) {
    path[1][i].fromRight = 0;
    path[1][i].fromLeft = 0;
  }
  for (int i = 2; i <= length; i++) {
    path[i][0].fromRight = max(path[i-1][1].fromLeft-(path[i-1][1].value*path[i-1][1].value),path[i-1][1].fromRight+path[i-1][1].value);
    // if coming from the previous one's left, you need to minus off the square of the value of that square
    for (int j = 1; j < width-1; j++) {
      path[i][j].fromRight = max(path[i-1][j+1].fromLeft-(path[i-1][j+1].value*path[i-1][j+1].value),path[i-1][j+1].fromRight+path[i-1][j+1].value);
      path[i][j].fromLeft = max(path[i-1][j-1].fromRight-(path[i-1][j-1].value*path[i-1][j-1].value),path[i-1][j-1].fromLeft+path[i-1][j-1].value);
    }
    path[i][width-1].fromLeft = max(path[i-1][width-2].fromRight-(path[i-1][width-2].value*path[i-1][width-2].value),path[i-1][width-2].fromLeft+path[i-1][width-2].value);
  }
  path[length][0].value += path[length][0].fromRight;
  for (int i = 1; i < width-1; i++) {
    path[length][i].value += max(path[length][i].fromRight,path[length][i].fromLeft);
  }
  path[length][width-1].value += path[length][width-1].fromLeft;
  int largestValue = -1234567890;
  for (int i = 0; i < width; i++) {
    if (path[length][i].value > largestValue) {
      largestValue = path[length][i].value;
    }
  }
  cout << largestValue;
}
