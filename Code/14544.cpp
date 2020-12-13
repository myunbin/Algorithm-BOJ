#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> P;
const int MAX_N = 100010;
const int MOD = 1000000009;
const ll INF = numeric_limits<ll>::max();

vector<P> adj[MAX_N];
int n, m, s, e;

ll dijkstra() {
	priority_queue<P, vector<P>, greater<P>> pq;
	ll dist[MAX_N];
	ll sp[MAX_N] = { 0 };
	bool visited[MAX_N] = { false };
	
	fill(dist, dist + MAX_N, INF);
	dist[s] = 0;
	sp[s] = 1;
	pq.push({dist[s], s});
	
	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[cur]);
		
		if (visited[cur]) break;
		visited[cur] = true;
		
		for (P p : adj[cur]) {
			int nxt = p.first;
			ll cost = p.second;
			
			if (dist[nxt] > dist[cur] + cost) {
				dist[nxt] = dist[cur] + cost;
				pq.push({dist[nxt], nxt});
				
				sp[nxt] = sp[cur] % MOD;
			}
			else if (dist[nxt] == dist[cur] + cost) {
				sp[nxt] += sp[cur] % MOD;
			}
		}
	}
	
	return sp[e];
}

void solve() {
	cin >> n >> m >> s >> e;
	
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		
		adj[a].push_back({b, t});
		adj[b].push_back({a, t});
	}
	
	cout << dijkstra() % MOD << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	solve();
	
	return 0;
}
