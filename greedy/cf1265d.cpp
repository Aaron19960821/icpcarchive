/*************************************************************************
    > File Name: cf1265d.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Fri 06 Dec 2019 04:40:33 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int a, b, c, d;

int main() {
  cin >> a >> b >> c >> d;

  string s;
  if (c == 0 && d == 0 && a - b == 1) {
    s += "0";
    for (int i = 0; i < b; ++i)
      s += "10";
  } else if (b == 0 && a == 0 && d == c + 1) {
    s += "3";
    for (int i = 0; i < c; ++i)
      s += "23";
  } else if (b - a == c - d && b >= a) {
    for (int i = 0; i < a; ++i) {
      s += "01";
    }

    for (int i = 0; i < d; ++i) {
      s += "23";
    }

    for (int i = 0; i < c - d; ++i) {
      s += "21";
    }
  } else if (b - a == c - d - 1 && b >= a) {
    for (int i = 0; i < a; ++i) {
      s += "01";
    }

    for (int i = 0; i < d; ++i) {
      s += "23";
    }

    for (int i = 0; i < b - a; ++i) {
      s += "21";
    }

    s += "2";
  } else if (b - a -1 == c - d && c >= d) {
    s += "1";
    for (int i = 0; i < a; ++i) {
      s += "01";
    }

    for (int i = 0; i < d; ++i) {
      s += "23";
    }

    for (int i = 0; i < b - a - 1; ++i) {
      s += "21";
    }
  } else {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  for (int i = 0; i < s.size(); ++i) {
    cout << s[i];
    if (i != s.size() - 1)
      cout << " ";
    else 
      cout << endl;
  }

  return 0;
}

