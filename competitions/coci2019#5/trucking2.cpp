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
  pair <int,int> distances[numCities][numCities];
  for (int i = 0; i < numCities; i++) {
    for (int j = 0; j < numCities; j++) {
      distances[i][j].first = 123456790;
    }
  }
  for (int i = 0; i < numCities; i++) {
    distances[i][i].first = 0;
    distances[i][i].second = cityFuel[i];
  }
  for (int i = 0; i < numCities; i++) {
    for (int j = 0; j < adjList[i].size(); j++) {
      edge currentEdge = adjList[i][j];
      distances[i][currentEdge.second].first = currentEdge.first;
    }
  }
  for (int i = 0; i < numCities; i++) {
    for (int j = 0; j < numCities; j++) {
      for (int k = 0; k < numCities; k++) {
        if (distances[i][k].first + distances[k][j].first < distances[i][j].first) {
          distances[i][j].first = distances[i][k].first + distances[k][j].first;
        }
      }
    }
  }
}
