#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;
const int MAX_N = 3e5 + 1;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	int n;
	cin >> n;
	
	vector<tp> v;
	for (int i = 0; i < n; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		v.push_back(make_tuple(s, e, c));
	}
	sort(v.begin(), v.end());
	
	int dp[MAX_N] = { 0 };
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	
	int ep = 0;
	for (int i = 0; i < n; i++) {
		auto [curs, cure, curc] = v[i];
		while (!pq.empty() && pq.top().first < curs) {
			ep = max(ep, pq.top().second);
			pq.pop();
		}
		dp[i] = ep + curc;
		pq.push({cure, dp[i]});
	}
	
	int ans = -1;
	for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
	
	cout << ans << '\n';
	
	return 0;
}
