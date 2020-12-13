#include <bits/stdc++.h>
using namespace std;
const int MAX = 20;

int ans, N;
int Map[MAX][MAX];
int dp[3][MAX][MAX] = { 0 };

bool goAble(int dir, int i, int j) {
	if (0 <= i && i < N && 0 <= j && j < N) {
		if (!Map[i][j]) {
			if (dir == 2) {
				if (!Map[i - 1][j] && !Map[i][j - 1]) return true;
				return false;
			}
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) 
			cin >> Map[i][j];
	}
	
	dp[0][0][1] = 1;
	
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (goAble(0, i, j + 1)) dp[0][i][j + 1] += dp[0][i][j];
			if (goAble(2, i + 1, j + 1)) dp[2][i + 1][j + 1] += dp[0][i][j];
			
			if (goAble(1, i + 1, j)) dp[1][i + 1][j] += dp[1][i][j];
			if (goAble(2, i + 1, j + 1)) dp[2][i + 1][j + 1] += dp[1][i][j];
			
			if (goAble(0, i, j + 1)) dp[0][i][j + 1] += dp[2][i][j];
			if (goAble(1, i + 1, j)) dp[1][i + 1][j] += dp[2][i][j];
			if (goAble(2, i + 1, j + 1)) dp[2][i + 1][j + 1] += dp[2][i][j];
		}	
	}
	
	
	for (int i = 0; i < 3; i++) ans += dp[i][N - 1][N - 1];
	cout << ans << '\n';
	return 0;
}
