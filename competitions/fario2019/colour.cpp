#include <iostream>
#include <vector>
using namespace std;
vector <long long> wayCount;
long long wayCounter(long long currentTile, vector <long long> &tiles, vector <vector <long long> > &adjList) {
  if (wayCount[currentTile] != -1) {
    return wayCount[currentTile] % 1000000007;
  } // else...
  long long total = 0;
  for (long long i = 0; i < adjList[currentTile].size(); i++) {
    total += wayCounter(adjList[currentTile][i],tiles,adjList) % 1000000007;
  }
  wayCount[currentTile] = total % 1000000007;
  return total % 1000000007;
}
int main() {
  long long numTiles,numColours;
  cin >> numTiles >> numColours;
  vector <long long> tiles(numTiles);
  for (long long i = 0; i < numTiles; i++) {
    cin >> tiles[i];
  }
  vector <vector <long long> > adjList(numTiles);
  long long numCompatible;
  cin >> numCompatible;
  for (long long i = 0; i < numCompatible; i++) {
    long long colour1,colour2;
    cin >> colour1 >> colour2;
    for (long long j = 0; j < numTiles-1; j++) {
      for (long long k = j+1; k < numTiles; k++) {
        if ((tiles[j] == colour1 && tiles[k] == colour2) || (tiles[j] == colour2 && tiles[k] == colour1)) {
          adjList[k].push_back(j); // going to move from the end to the start
        }
      }
    }
  }
  wayCount.resize(numTiles);
  wayCount[0] = 1;
  for (long long i = 1; i < numTiles; i++) {
    wayCount[i] = -1;
  }
  cout << wayCounter(numTiles-1,tiles,adjList) << endl;
}
