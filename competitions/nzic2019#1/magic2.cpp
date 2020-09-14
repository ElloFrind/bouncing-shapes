#include <iostream>
using namespace std;
int main() {
  int a,b,c,d,n;
  cin >> a >> b >> c >> d >> n;
  int numU = 1;
  int numV = 1;
  for (int i = 0; i < n; i++) {
//    cout << "u: " << numU << '\n';
  //  cout << "v: " << numV << '\n';
    int prevU = numU;
    int prevV = numV;
    numU = (a*prevU + b*prevV) % 10000;
    numV = (c*prevU + d*prevV) % 10000;
  }
//  cout << "u: " << numU << '\n';
//  cout << "v: " << numV << '\n';
  cout << numU << ' ' << numV << endl;
}
