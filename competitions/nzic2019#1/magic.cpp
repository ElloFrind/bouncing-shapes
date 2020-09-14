#include <iostream>
#include <map>
#include <utility>
#include <math.h>
using namespace std;
int main() {
  int a,b,c,d,n;
  cin >> a >> b >> c >> d >> n;
  int numV = 1;
  int numU = 1;
  int factor = 1;
  if (n > pow(10,5)) {
    for (int i = 2; i < n; i++) {
      if (n % i == 0) {
        factor = i;
        break;
      }
    }
    for (int i = 1; i < factor; i++) {
      int prevA = a;
      int prevB = b;
      int prevC = c;
      int prevD = d;
      a = prevA * prevA + prevA * prevB;
      b = prevB * prevC + prevB * prevD;
      c = prevC * prevA + prevC * prevB;
      d = prevD * prevC + prevD * prevD;
    }
  }
  for (int i = 0; i < n/factor; i++) {
    int prevU = numU;
    int prevV = numV;
    numU = (a*prevU + b*prevV) % 10000;
    numV = (c*prevU + d*prevV) % 10000;
  }
  cout << numU << ' ' << numV << endl;
}
