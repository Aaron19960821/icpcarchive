/*************************************************************************
    > File Name: hihocoder1499.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Apr 11 22:31:12 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
const int maxn = 100010;

ll grid[maxn][2];
ll sum = 0;
int n;

void Solve()
{
	int i;
	ll ans = 0;

	for(i=1;i<=n;i++){
		ll curcol = grid[i][0] + grid[i][1];
		if(curcol >= 2*sum){
			if(grid[i][0] >= sum && grid[i][1] >= sum){
				ans += (curcol - 2*sum);
				grid[i+1][0] += (grid[i][0] - sum);
				grid[i+1][1] += (grid[i][1] - sum);
			}
			else{
				int index = grid[i][0]>sum?0:1;
				ans += (grid[i][index]-sum);
				grid[i][index] -= (sum-grid[i][1-index]);
				grid[i+1][index] += (grid[i][index]-sum);
			}
		}
		else{
			if(grid[i][0] <= sum && grid[i][1] <= sum){
				ans += (2*sum-curcol);
				grid[i+1][0] -= (sum - grid[i][0]);
				grid[i+1][1] -= (sum - grid[i][1]);
			}
			else{
				int index = grid[i][0]<sum?0:1;
				ans += (sum - grid[i][index]);
				grid[i][index] += (grid[i][1-index]-sum);
				grid[i+1][index] -= (sum - grid[i][index]);
			}
		}
	}

	cout << ans << endl;
	return;
}

int main()
{
	freopen("input","r",stdin);
	int i;
	cin >> n;

	for(i=1;i<=n;i++){
		scanf("%lld%lld",&grid[i][0],&grid[i][1]);
		sum += (grid[i][0]+grid[i][1]);
	}

	sum /= (2*n);

	Solve();
}


