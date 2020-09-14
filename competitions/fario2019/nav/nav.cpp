#include "nav.h"
int numNodes;
void init(int subtask, int n, int m, std::vector<int> A, std::vector<int> B) {
    numNodes = n;
}

int findPrime() {
    for (int i = 0; i < numNodes; i++) {
      if (nav(i) == -1) {
        return i;
      }
    }
    return 0;
}
