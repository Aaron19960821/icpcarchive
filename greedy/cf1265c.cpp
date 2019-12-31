/*************************************************************************
    > File Name: cf1265c.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Fri 06 Dec 2019 03:57:07 PM CST
 ************************************************************************/

#include<iostream>
#include<utility>
#include<vector>
#include <cstdlib>

using namespace std;

using pi = pair<int, int>;

int T;
int N;
vector<pi> solveList;

int main() {
  //freopen("./cf1265c.in", "r", stdin);
  int g, s, b;

  cin >> T;
  while(T--) {
    g = s = b = 0;
    solveList.clear();
    int N;
    cin >> N;
    pi tmp;
    int tmpNum;
    for (int i = 0; i < N; ++i) {
      cin >> tmpNum;
      if (i == 0 || tmpNum != tmp.first) {
        if (i != 0)
          solveList.push_back(tmp);
        tmp.first = tmpNum;
        tmp.second = 1;
      } else {
        tmp.second++;
      }
    }
    solveList.push_back(tmp);

    g = solveList[0].second;

    int sBucket = 0;
    for (int i = 1; i < solveList.size(); ++i) {
      s += solveList[i].second;
      sBucket++;
      if (s > g) break;
    }

    for (int i = 1+sBucket; i < solveList.size(); ++i) {
      if (b + s + g + solveList[i].second <= N / 2) {
        b += solveList[i].second;
      } else {
        break;
      }
    }

    if (b > g && s > g && b + s + g <= N / 2) {
      cout << g << " " << s << " " << b << endl;
    } else {
      cout << "0 0 0" << endl;
    }
  }

  return 0;
}
