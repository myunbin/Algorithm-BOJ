#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 1010;
const int INF = 2e9;
typedef pair<int, int> P;


void solve () {
	int N, M;
	cin >> N >> M;
	
	vector<P> adj[MAX_V];	
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	
	int dist[MAX_V];
	bool visited[MAX_V] = { false };
	
	fill(dist, dist + MAX_V, INF);
	priority_queue<P, vector<P>, greater<P>> pq;
	
	dist[1] = 0;
	pq.push({dist[1], 1});
	
	int prev[MAX_V] = { 0 };
	
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
				prev[nxt] = cur;
				pq.push({dist[nxt], nxt});
			}
		}
	}
	
	vector<P> e;
	bool check[MAX_V] = { false };
	
	for (int i = 2; i <= N; i++) {
		int x = i;
		vector<int> path;
		while (x != 1) {
			path.push_back(x);
			x = prev[x];
		}
		path.push_back(1);
		reverse(path.begin(), path.end());
		
		int size = path.size();
		for (int i = 0; i < size - 1; i++) {
			if (check[path[i]] && check[path[i + 1]]) continue;
			e.push_back({path[i], path[i + 1]});
			check[path[i]] = true; check[path[i + 1]] = true;
		}
	}
	
	cout << e.size() << '\n';
	for (P p : e) {
		cout << p.first << ' ' << p.second << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
