#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef pair <int,int> edge;
int main() {
  int numCities;
  cin >> numCities;
  int cityFuel[numCities];
  for (int i = 0; i < numCities; i++) {
    cin >> cityFuel[i];
  }
  vector <vector <edge> > adjList(numCities);
  for (int i = 0; i < numCities-1; i++) {
    int start,end,distance;
    cin >> start >> end >> distance;
    start--;
    end--;
    adjList[start].push_back(make_pair(distance,end));
    adjList[end].push_back(make_pair(distance,start));
  }
  int numPossible = 2;
  int totalFuel = 0;
  for (int i = 0; i < numCities-1; i++) {
    totalFuel += cityFuel[i];
    totalFuel -= adjList[i][0].first;
    if (totalFuel < 0) {
      numPossible--;
      break;
    }
  }
  totalFuel = 0;
  totalFuel += cityFuel[numCities-1];
  totalFuel -= adjList[numCities-1][0].first;
  if (totalFuel < 0) {
    numPossible--;
    cout << numPossible << endl;
    return 0;
  }
  for (int i = numCities-2; i > 0; i++) {
    totalFuel += cityFuel[i];
    totalFuel -= adjList[i][1].first;
    if (totalFuel < 0) {
      numPossible--;
      break;
    }
  }
  cout << numPossible << endl;
}
