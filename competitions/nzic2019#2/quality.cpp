#include <iostream>
using namespace std;
int main() {
  int numProducts,threshold;
  cin >> numProducts >> threshold;
  int products[numProducts];
  for (int i = 0; i < numProducts; i++) {
    cin >> products[i];
  }
  int numDefective = 0;
  for (int i = 0; i < numProducts; i++) {
    if (products[i] < threshold) {
      if (numDefective == 2) {
        cout << "Fault Detected\n" << products[i-2] << ' ' << products[i-1] << ' ' << products[i] << endl;
        return 0;
      } else {
        numDefective++;
      }
    } else {
      numDefective = 0;
    }
  }
  cout << "No Fault\n";
}
