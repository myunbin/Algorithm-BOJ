#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;
const int MAX_N = 1e5 + 1;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	int n, m;
	cin >> m >> n;
	
	vector<int> c(m);
	for (int i = 0; i < m; i++) cin >> c[i];
	
	vector<tp> v;
	for (int i = 0; i < n; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		v.emplace_back(s, e, (e - s) * c[t - 1]);
	}
	sort(v.begin(), v.end());

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	
	int ep = 0;
	int ans = -1;
	for (int i = 0; i < n; i++) {
		auto [curs, cure, curc] = v[i];
		while (!pq.empty() && pq.top().first <= curs) {
			ep = max(ep, pq.top().second);
			pq.pop();
		}
		pq.push({cure, ep + curc});
		ans = max(ans, ep + curc);
	}
	
	cout << ans << '\n';
	
	return 0;
}
