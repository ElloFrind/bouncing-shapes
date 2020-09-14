#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main() {
  int numBuildings,numFams;
  cin >> numBuildings >> numFams;
  int totalWidth = 0;
  int totalHeight = 0;
  int highest;
  vector <pair<int,int> > buildings;
  for (int i = 0; i < numFams; i++) {
    int width,height;
    cin >> width >> height;
    buildings.push_back(make_pair(width,height));
    totalWidth += width;
    if (totalHeight < height) {
      highest = i;
      totalHeight = height;
    }
  }
  int totalArea = totalWidth * totalHeight;
  for (int i = 0; i < numBuildings-numFams; i++) {
    int width,height;
    cin >> width >> height;
    int endAreaChange = 0;
    int buildingChanged = -1;
    if (height > buildings[highest].second) {
      int newWidth = totalWidth - buildings[highest].first + width;
      int newAreaChange = height * newWidth - totalWidth * totalHeight;
      if (newAreaChange < endAreaChange) {
        endAreaChange = newAreaChange;
        buildingChanged = highest;
      }
    }
    for (int j = 0; j < numFams; j++) {
      if (buildings[j].first > width && !(height > buildings[highest].second && j == highest)) {
        int newAreaChange = width * buildings[highest].second - totalWidth * buildings[highest].second;
        if (newAreaChange < endAreaChange) {
          endAreaChange = newAreaChange;
          buildingChanged = j;
        }
      }
    }
    if (buildingChanged != -1) {
      buildings[buildingChanged].first = width;
      buildings[buildingChanged].second = height;
      if (buildingChanged == highest) {
        int newHighest = 0;
        int highestPlace;
        for (int i = 0; i < buildings.size(); i++) {
          if (newHighest < buildings[i].second) {
            newHighest = buildings[i].second;
            highestPlace = i;
          }
        }
        highest = highestPlace;
      }
    }
    totalArea += endAreaChange;
  }
  cout << totalArea;
}
