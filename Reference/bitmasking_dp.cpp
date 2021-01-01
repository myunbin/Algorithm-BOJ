// TSP(Traveling Salesman Problem) with Bitmasking techinque

#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 16;
const int INF = 1e9;
int n, dp[MAX_N][1 << MAX_N];
int w[MAX_N][MAX_N];

int go(int i, int v) {
	if (v == (1 << n) - 1) {
		if (w[i][0] != 0) return w[i][0];
		else return INF;
	}
	
	int &ret = dp[i][v];
	if (ret != -1) return ret;
	
	ret = INF;
	for (int j = 0; j < n; j++) {
		if (v & (1 << j) || w[i][j] == 0) continue;
		ret = min(ret, go(j, v | (1 << j)) + w[i][j]); 
	}
	
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	memset(dp, -1, sizeof(dp));
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> w[i][j];
	}
	
	cout << go(0, 1) << '\n';
    return 0;
}
