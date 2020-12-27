#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1010;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	
	int pSum[MAX_N][MAX_N] = { 0 };
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1++; y1++; x2++; y2++;
		
		pSum[x1][y1]++;
		pSum[x1][y2]--;
		pSum[x2][y2]++;
		pSum[x2][y1]--;
    
    
	}
	
	int ans = 0;

	for (int i = 1; i < MAX_N; i++) {
		for (int j = 1; j < MAX_N; j++) {
			pSum[i][j] += (pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1]);
			if (pSum[i][j] == k) ans++;
		}
	}
	
	cout << ans << '\n';
	return 0;
}
