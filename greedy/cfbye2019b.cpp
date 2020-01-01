/*************************************************************************
    > File Name: cfbye2019b.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue 31 Dec 2019 02:27:17 PM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 2e5 + 7;

int a[maxn];
int t;
int n;

void print(bool foundAns, int a, int b) {
  if (foundAns) {
    cout << "YES" << endl;
    cout << a << " " << b << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  cin >> t;
  for (int nCase = 0; nCase < t; ++nCase) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    int curMaxInd = 0, curMinInd = 0;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
      if (abs(a[curMinInd] - a[i]) >= i - curMinInd + 1) {
        print(true, curMinInd+1, i+1);
        flag = true;
        break;
      }
      if (abs(a[curMaxInd] - a[i]) >= i - curMaxInd + 1) {
        print(true, curMaxInd+1, i+1);
        flag = true;
        break;
      }

      if (a[i] - a[curMinInd] <= i - curMinInd + 1) curMinInd = i;
      if (a[curMaxInd] - a[i] >= i - curMaxInd + 1) curMaxInd = i;
    }

    if (!flag) print(false, -1, -1);
  }

  return 0;
}
