#include <iostream>
#include <map>
#include <utility>
#include <math.h>
#include <vector>
using namespace std;
struct quad {
  int a,b,c,d;
};
int main() {
  int a,b,c,d,n;
  cin >> a >> b >> c >> d >> n;
  int numV = 1;
  int numU = 1;
  vector <quad> nums;
  quad newQuad;
  newQuad.a = a;
  newQuad.b = b;
  newQuad.c = c;
  newQuad.d = d;
  nums.push_back(newQuad);
  int totalAdded = 0;
  for (int i = 0; i < sqrt(n); i++) {
    int prevA = a;
    int prevB = b;
    int prevC = c;
    int prevD = d;
    a = prevA * prevA + prevA * prevB;
    b = prevB * prevC + prevB * prevD;
    c = prevC * prevA + prevC * prevB;
    d = prevD * prevC + prevD * prevD;
    newQuad.a = a;
    newQuad.b = b;
    newQuad.c = c;
    newQuad.d = d;
    nums.push_back(newQuad);
  }
  int currentPower = nums.size()-1;
  while (totalAdded <= n) {
    if (totalAdded + pow(2,currentPower) <= n) {
      int prevU = numU;
      int prevV = numV;
      numU = (nums[currentPower].a*prevU + nums[currentPower].b*prevV) % 10000;
      numV = (nums[currentPower].c*prevU + nums[currentPower].d*prevV) % 10000;
      totalAdded += pow(2,currentPower);
    } else if (currentPower == 0) {
      cout << numU << ' ' << numV << endl;
      return 0;
    } else {
      currentPower--;
    }
  }
}
