#include <iostream>
#include <string>
using namespace std;
int main() {
  string teas[6] = {"Ginger", "Chamomile", "Earl Gray", "Peppermint", "Lemon", "Strawberry"};
  for (int i = 0; i < 6; i++) {
    int input;
    cin >> input;
    cout << teas[i] << ' ' << input * 240 << endl;
  }
}
