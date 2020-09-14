#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int numWords,length;
  cin >> numWords >> length;
  char words[numWords][length];
  for (int i = 0; i < numWords; i++) {
    for (int j = 0; j < length; j++) {
      cin >> words[i][j];
    }
  }
  int numSimilar = 0;
  for (int i = 0; i < numWords-1; i++) {
    for (int j = i+1; j < numWords; j++) {
      bool similar = true;
      for (int k = 0; k < length; k++) {
        if (words[i][k] != '?' && words[j][k] != '?' && words[i][k] != words[j][k]) {
          similar = false;
          break;
        }
      }
      if (similar) {
        numSimilar++;
      }
    }
  }
  cout << numSimilar << endl;
}
