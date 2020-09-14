#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
struct edge {
  int end;
  int value;
  bool used;
  bool operator < (edge other) const {
    return value < other.value;
  }
  bool operator > (edge other) const {
    return value > other.value;
  }
  bool operator >= (edge other) const {
    return value >= other.value;
  }
  bool operator <= (edge other) const {
    return value <= other.value;
  }
};
int main() {
  int numNodes, numEdges;
  cin >> numNodes >> numEdges;
  int nodeValues[numNodes];
  vector <vector <edge> > adjList(numNodes);
  for (int i = 0; i < numNodes; i++) {
    cin >> nodeValues[i];
  }
  for (int i = 0; i < numEdges; i++) {
    int start,end,value;
    cin >> start >> end;
    start--;
    end--;
    value = nodeValues[start] - nodeValues[end];
    if (value < 0) {
      value = 0;
    }
    edge newEdge;
    newEdge.end = end;
    newEdge.value = value;
    newEdge.used = false;
    adjList[start].push_back(newEdge);
  }
  int highestCityPath[numNodes]; // holds the value of the best city currently in this path
  highestCityPath[0] = nodeValues[0];
  int distanceFromStart[numNodes]; // holds the current disappointment value for each node
  distanceFromStart[0] = 0;
  for (int i = 1; i < numNodes; i++) {
    distanceFromStart[i] = 1234567890;
  }
  priority_queue <edge> edges;
  edge startEdge;
  startEdge.end = 0;
  startEdge.value = 0;
  startEdge.used = false;
  edges.push(startEdge);
  while (!edges.empty()) {
    edge currentEdge = edges.top();
    edges.pop();
    for (int i = 0; i < adjList[currentEdge.end].size(); i++) {
      edge newEdge = adjList[currentEdge.end][i];
      int newPossibleDistance = max(highestCityPath[currentEdge.end]-nodeValues[newEdge.end],distanceFromStart[currentEdge.end]);
      if (distanceFromStart[newEdge.end] > max(highestCityPath[currentEdge.end] - nodeValues[newEdge.end], && newEdge.used == false) {
        distanceFromStart[newEdge.end] = distanceFromStart[currentEdge.end] + newEdge.value;
        adjList[currentEdge.end][i].used = true;
        edges.push(newEdge);
      }
    }
  }
  cout << distanceFromStart[numNodes-1] << endl;
}
