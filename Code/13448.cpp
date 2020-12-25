#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct s {
	ll m, p, r;
	bool operator < (const s& other) {
		return other.p * r < p * other.r;
	}
};

ll N, T;
vector<s> a;
ll dp[51][100010];

ll go(ll index, ll time) {
	if (index == N) return 0;
	
	ll &ret = dp[index][time];
	if (ret != -1) return ret;
	
	ret = go(index + 1, time);
	
	if (time + a[index].r <= T) {
		ll finT = time + a[index].r;
		ll score = a[index].m - finT * a[index].p;
		ret = max(ret, go(index + 1, finT) + score);
	}
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	cin >> N >> T;
	a.resize(N);
	for (int i = 0; i < N; i++) cin >> a[i].m;
	for (int i = 0; i < N; i++) cin >> a[i].p;
	for (int i = 0; i < N; i++) cin >> a[i].r;
	sort(a.begin(), a.end());
	
	memset(dp, -1, sizeof(dp));
	
	cout << go(0, 0) << '\n';
	
	return 0;
}
