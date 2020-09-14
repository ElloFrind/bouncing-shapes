#include "nav.h"
using namespace std;
int numNodes,numEdges;
vector <int> startNodes;
vector <int> endNodes;
void init(int subtask, int n, int m, vector <int> A, vector <int> B) {
  numNodes = n;
  numEdges = m;
  startNodes = A;
  endNodes = B;
}
int findPrime() {
  for (int i = 0; i < numNodes; i++) {
    if (nav(i) == -1) {
      return i;
    }
  }
}
