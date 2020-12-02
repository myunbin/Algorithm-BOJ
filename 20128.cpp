#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
const int MAX_V = 100010;
const ll INF = 3e15;

struct T {
	ll dist;
	int node, sign;
	T(ll a, int b, int c) : dist(a), node(b), sign(c) {}
	bool operator < (const struct T& other) const {
		return dist > other.dist;
	}
};

void solve() {
	int N, M;
	cin >> N >> M;
	
	vector<P> adj[MAX_V];
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	
	ll dist[MAX_V][2];
	bool visited[MAX_V][2] = { false };
	for (int i = 0; i < MAX_V; i++) {
		dist[i][0] = INF;
		dist[i][1] = INF;
	}
		
	dist[1][0] = 0;
	
	priority_queue<T> pq;
	pq.push({dist[1][0], 1, 0});
	
	while (!pq.empty()) {
		int cur, curS;
		do {
			cur = pq.top().node;
			curS = pq.top().sign;
			pq.pop();
		} while (!pq.empty() && visited[cur][curS]);
		
		if (visited[cur][curS]) break;
		visited[cur][curS] = true;
		
		for (auto p : adj[cur]) {
			int nxt = p.first, cost = p.second;
			if (dist[nxt][(curS + cost) % 2] > dist[cur][curS] + cost) {
				dist[nxt][(curS + cost) % 2] = dist[cur][curS] + cost;
				pq.push({dist[nxt][(curS + cost) % 2], nxt, (curS + cost) % 2});
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (dist[i][1] == INF) cout << -1 << ' ';
		else cout << dist[i][1] << ' ';
		
		if (dist[i][0] == INF) cout << -1 << ' ';
		else cout << dist[i][0] << ' ';
		
		cout << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
