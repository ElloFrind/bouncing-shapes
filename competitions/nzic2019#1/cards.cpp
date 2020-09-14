#include <iostream>
using namespace std;
int main() {
  int numStories;
  cin >> numStories;
  int numCards = 0;
  for (int i = 1; i <= numStories; i++) {
    numCards += i + i * 2;
  }
  numCards -= numStories;
  cout << numCards << endl;
}
