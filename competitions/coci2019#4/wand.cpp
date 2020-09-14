#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
  int numNodes,numEdges;
  cin >> numNodes >> numEdges;
  vector <vector <int> > adjList(numNodes);
  for (int i = 0; i < numEdges; i++) {
    int start,end;
    cin >> start >> end;
    start--;
    end--;
    adjList[end].push_back(start);
  }
  queue <int> nodeList;
  bool visited[numNodes];
  bool firstAgain = false;
  for (int i = 0; i < numNodes; i++) {
    visited[i] = false;
  }
  nodeList.push(0);
  while (!nodeList.empty()) {
    int currentNode = nodeList.front();
    nodeList.pop();
    if (visited[currentNode]) {
      continue;
    }
    visited[currentNode] = true;
    for (int i = 0; i < adjList[currentNode].size(); i++) {
      nodeList.push(adjList[currentNode][i]);
      if (adjList[currentNode][i] == 0) {
        firstAgain = true;
      }
    }
  }
  if (firstAgain) {
    cout << 1;
  } else {
    cout << 0;
  }
  for (int i = 1; i < numNodes; i++) {
    if (visited[i]) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
}
