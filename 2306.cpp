#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 505;

string s;
int dp[MAX_N][MAX_N];

int go(int left, int right) {
	if (left >= right) return 0;
	
	int &ret = dp[left][right];
	if (ret != -1) return ret;
	
	if ((s[left] == 'a' && s[right] == 't') || (s[left] == 'g' && s[right] == 'c'))
		ret = max(ret, go(left + 1, right - 1) + 2);
	
	for (int k = left; k + 1 <= right; k++) 
		ret = max(ret, go(left, k) + go(k + 1, right));
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	memset(dp, -1, sizeof(dp));
	
	cin >> s;
	cout << go(0, s.length() - 1) << '\n';
	
	return 0;
}
