#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
struct line {
  int startx;
  int starty;
  int endx;
  int endy;
  bool drawn;
  int id;
};
pair <int,int> otherCoords(line currentLine, int x, int y) {
  if (currentLine.startx == x && currentLine.starty == y) {
    return make_pair(currentLine.endx,currentLine.endy);
  } else {
    return make_pair(currentLine.startx,currentLine.starty);
  }
}
int main() {
  int numLines;
  cin >> numLines;
  vector <vector <vector <int> > > lineMatrix; // holds the ids of every line that reaches this space
  vector <line> lines(numLines);
  for (int i = 0; i < numLines; i++) {
    cin >> lines[i].startx;
    cin >> lines[i].starty;
    cin >> lines[i].endx;
    cin >> lines[i].endy;
    int largestx = max(lines[i].startx,lines[i].endx);
    if (largestx > lineMatrix.size()) {
      lineMatrix.resize(largestx);
    }
    int largesty = max(lines[i].starty,lines[i].endy);
    if (largesty > lineMatrix[0].size()) {
      for (int j = 0; j < lineMatrix[0].size(); j++) {
        lineMatrix[j].resize(largesty);
      }
    }
    lineMatrix[startx][starty].push_back(i);
    lineMatrix[endx][endy].push_back(i);
    lines[i].id = i;
  }
  pair <int,int> startPoint;
  cin >> startPoint.first >> startPoint.second;
  queue <pair <int,int> > drawnPoints;
  drawnPoints.push(startPoint);
  while (!drawnPoints.empty()) {
    pair <int,int> currentPoint = drawnPoints.front();
    drawnPoints.pop();
    for (int i = 0; i < lineMatrix[currentPoint.first][currentPoint.second].size(); i++) {
      if (lines[lineMatrix[currentPoint.first][currentPoint.second][i].drawn] == false) {

      }
    }
  }
}
