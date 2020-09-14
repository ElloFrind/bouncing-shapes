#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int height, width, numThrows;
  cin >> height >> width >> numThrows;
  char canvas[width][height];
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      canvas[i][j] = '~';
    }
  }
  for (int i = 0; i < numThrows; i++) {
    int x,y,spread;
    char colour;
    cin >> x >> y >> spread >> colour;
    for (int i = max(x-spread,0); i <= min(x+spread,width-1); i++) {
      for (int j = max(y-spread,0); j <= min(y+spread,height-1); j++) {
        canvas[i][j] = colour;
      }
    }
  }
  int area = 0;
  char testColour;
  cin >> testColour;
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      if (canvas[i][j] == testColour) {
        area++;
      }
    }
  }
  cout << area << endl;
}
