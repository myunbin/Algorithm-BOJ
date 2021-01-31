#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 5050;
const int INF = 1e9 + 1;
vector<pii> adj[MAX_N];

int main() {
	fio();

	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].ppb(v, w), adj[v].ppb(u, w);
	}

	while (q--) {
		int k, u;
		cin >> k >> u;

		int ans = 0;
		bool v[MAX_N] = { false };
		queue<int> q;
		q.push(u);
		v[u] = true;
		
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			
			for (auto nxt : adj[cur]) {
				if (v[nxt.first]) continue;
				if (nxt.second >= k) {
					ans++;
					v[nxt.first] = true;
					q.push(nxt.first);
				}
			}
		}

		cout << ans << '\n';
	}
	return 0;
}
