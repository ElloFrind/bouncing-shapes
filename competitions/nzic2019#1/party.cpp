#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int main() {
  int numPeople,numHosts;
  cin >> numPeople >> numHosts;
  vector <int> teaRequired;
  for (int i = 0; i < numPeople; i++) {
    teaRequired.push_back(0);
  }
  for (int i = 0; i < numPeople; i++) {
    string person;
    cin >> person;
    char teaType;
    cin >> teaType;
    switch (teaType) {
      case 'G': teaRequired[0]++; break;
      case 'C': teaRequired[1]++; break;
      case 'E': teaRequired[2]++; break;
      case 'P': teaRequired[3]++; break;
      case 'L': teaRequired[4]++; break;
      case 'S': teaRequired[5]++; break;
    }
  }
  map <string, vector <int> > hosts;
  for (int i = 0; i < numPeople; i++) {
    string person;
    cin >> person;
    for (int j = 0; j < 6; j++) {
      int teaQuantity;
      cin >> teaQuantity;
      hosts[person].push_back(teaQuantity);
    }
  }
  for (int i = 0; i < numHosts; i++) {
    string person;
    cin >> person;
    int numFails = 0;
    for (int j = 0; j < 6; j++) {
      if (hosts[person][j] < teaRequired[j]) {
        numFails += teaRequired[j] - hosts[person][j];
      }
    }
    cout << person << ' ';
    if (numFails == 0) {
      cout << "Successful\n";
    } else if (numFails <= 2) {
      cout << "Mildly Successful (" << numFails << ")\n";
    } else {
      cout << "Disaster (" << numFails << ")\n";
    }
  }
}
