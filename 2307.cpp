#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int MAX_N = 1010;
const int INF = 1e9;

vector<P> adj[MAX_N];
int n, m;
int prevNode[MAX_N];

int dijkstra() {
	priority_queue<P, vector<P>, greater<P>> pq;
	int dist[MAX_N];
	bool visited[MAX_N] = { false };
	
	fill(dist, dist + MAX_N, INF);
	dist[1] = 0;
	pq.push({dist[1], 1});
	
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
			int cost = p.second;
			
			if (dist[nxt] > dist[cur] + cost) {
				dist[nxt] = dist[cur] + cost;
				prevNode[nxt] = cur;
				pq.push({dist[nxt], nxt});
			}
		}
	}
	
	return dist[n];
}

int dijkstra2(int u, int v) {
	priority_queue<P, vector<P>, greater<P>> pq;
	int dist[MAX_N];
	bool visited[MAX_N] = { false };
	
	fill(dist, dist + MAX_N, INF);
	dist[1] = 0;
	pq.push({dist[1], 1});
	
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
			int cost = p.second;
			
			if (dist[nxt] > dist[cur] + cost) {
				if ((cur == u && nxt == v) || (cur == v && nxt == u))
					continue;
				dist[nxt] = dist[cur] + cost;
				pq.push({dist[nxt], nxt});
			}
		}
	}
	
	return dist[n];
}
void solve() {
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		adj[a].push_back({b, t});
		adj[b].push_back({a, t});
	}
	
	int minDist = dijkstra();
	if (minDist >= INF) {
		cout << -1 << '\n';
		return;
	}
	
	int ans = -1;
	
	for (int i = n; i != 1; i = prevNode[i]) {
		int ret = dijkstra2(i, prevNode[i]);
		if (ret == INF) {
			cout << -1 << '\n';
			return;
		}
		ans = max(ans, ret - minDist);
	}
	
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	solve();
	
	return 0;
}
