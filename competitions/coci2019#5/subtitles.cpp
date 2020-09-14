#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct timeHolder {
  int hour;
  int minute;
  int second;
  int millisecond;
};
struct subtitle {
  int ordinal;
  timeHolder start;
  timeHolder end;
  vector <string> text;
  bool operator < (subtitle other) const {
    return ordinal < other.ordinal;
  }
};
int charToInt(char c) {
  switch (c) {
    case '0': return 0; break;
    case '1': return 1; break;
    case '2': return 2; break;
    case '3': return 3; break;
    case '4': return 4; break;
    case '5': return 5; break;
    case '6': return 6; break;
    case '7': return 7; break;
    case '8': return 8; break;
    case '9': return 9; break;
    default: cout << "ERROR: Not Digit\n"; return -1;
  }
}
timeHolder addMilliseconds(timeHolder a, int b) {
  int carryMilli = (a.millisecond + b)/1000;
  int leave = (a.millisecond + b)%1000;
  if (leave < 0) {
    carryMilli--;
    leave = 1000+leave;
  }
  a.millisecond = leave;
  if (carryMilli == 0) {
    return a;
  }
  int carrySec = (a.second + carryMilli)/60;
  leave = (a.second + carryMilli)%60;
  a.second = leave;
  if (leave < 0) {
    carrySec--;
    leave = 60+leave;
  }
  if (carrySec == 0) {
    return a;
  }
  int carryMin = (a.minute + carrySec)/60;
  leave = (a.minute + carrySec)%60;
  a.minute = leave;
  if (leave < 0) {
    carryMin--;
    leave = 60+leave;
  }
  if (carryMin == 0) {
    return a;
  }
  a.hour += carryMin;
  return a;
}
int main() {
  vector <subtitle> list;
  while (true) {
    int ordinalNum;
    cin >> ordinalNum;
    cin.ignore();
    subtitle newSub;
    newSub.ordinal = ordinalNum;
    string times;
    getline(cin,times);
    newSub.start.hour = charToInt(times[0]) * 10 + charToInt(times[1]);
    newSub.start.minute = charToInt(times[3]) * 10 + charToInt(times[4]);
    newSub.start.second = charToInt(times[6]) * 10 + charToInt(times[7]);
    newSub.start.millisecond = charToInt(times[9]) * 100 + charToInt(times[10]) * 10 + charToInt(times[11]);
    newSub.end.hour = charToInt(times[17]) * 10 + charToInt(times[18]);
    newSub.end.minute = charToInt(times[20]) * 10 + charToInt(times[21]);
    newSub.end.second = charToInt(times[23]) * 10 + charToInt(times[24]);
    newSub.end.millisecond = charToInt(times[26]) * 100 + charToInt(times[27]) * 10 + charToInt(times[28]);
    string text;
    while (true) {
      getline(cin,text);
      if (text == "" || text == "#") {
        break;
      }
      newSub.text.push_back(text);
    }
    list.push_back(newSub);
    if (text == "#") {
      break;
    }
  }
  sort(list.begin(),list.end());
  int shift;
  cin >> shift;
  for (int i = 0; i < list.size(); i++) {
    subtitle currentSub = list[i];
    currentSub.start = addMilliseconds(currentSub.start,shift);
    currentSub.end = addMilliseconds(currentSub.end,shift);
    cout << currentSub.ordinal << '\n';
    if (currentSub.start.hour < 10) {
      cout << 0;
    }
    cout << currentSub.start.hour << ':';
    if (currentSub.start.minute < 10) {
      cout << 0;
    }
    cout << currentSub.start.minute << ':';
    if (currentSub.start.second < 10) {
      cout << 0;
    }
    cout << currentSub.start.second << ',';
    if (currentSub.start.millisecond < 10) {
      cout << "00";
    } else if (currentSub.start.millisecond < 100) {
      cout << 0;
    }
    cout << currentSub.start.millisecond << " --> ";
    if (currentSub.end.hour < 10) {
      cout << 0;
    }
    cout << currentSub.end.hour << ':';
    if (currentSub.end.minute < 10) {
      cout << 0;
    }
    cout << currentSub.end.minute << ':';
    if (currentSub.end.second < 10) {
      cout << 0;
    }
    cout << currentSub.end.second << ',';
    if (currentSub.end.millisecond < 10) {
      cout << "00";
    } else if (currentSub.end.millisecond < 100) {
      cout << 0;
    }
    cout << currentSub.end.millisecond << '\n';
    for (int j = 0; j < currentSub.text.size(); j++) {
      cout << currentSub.text[j] << '\n';
    }
    if (i == list.size()-1) {
      cout << "#\n";
    } else {
      cout << "\n";
    }
  }
}
