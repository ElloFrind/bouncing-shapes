#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int n,a,b,c;
  cin >> n >> a >> b >> c;
  if (a == b && b == c) {
    cout << "Possible\n";
    for (int i = 0; i < n; i++) {
      cout << a << ' ';
    }
    cout << endl;
  } else if (n == 1) {
    cout << "Impossible\n" << endl;
  } else if (n == 3) {
    if (b == c) {
      vector <float> sequence;
      sequence.push_back(b);
      sequence.push_back(b);
      sequence.push_back(a*n - b*2);
      float num = 1.0;
      if (sequence[2] % num == 0 && sequence[2] > 0) {
        sort(sequence.begin(),sequence.end());
        cout << "Possible\n" << sequence[0] << ' ' << sequence[1] << ' ' << sequence[2] << endl;
      } else {
        cout << "Impossible\n";
      }
    }
  }
}
