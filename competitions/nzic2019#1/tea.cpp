#include <iostream>
#include <map>
using namespace std;
int main() {
  map <char,int> teabags;
  teabags['C'] = 0;
  teabags['E'] = 0;
  teabags['P'] = 0;
  teabags['G'] = 0;
  teabags['L'] = 0;
  teabags['S'] = 0;
  while (true) {
    char teaType;
    cin >> teaType;
    if (teaType == 'D') {
      break;
    }
    int quantity;
    cin >> quantity;
    teabags[teaType] += quantity;
  }
  cout << teabags['G'] << ' ' << teabags['C'] << ' ' << teabags['E'] << ' ' << teabags['P'] << ' ' << teabags['L'] << ' ' << teabags['S'] << endl;
}
