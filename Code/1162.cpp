#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;
const int MAX_V = 10010;
const ll INF = 2e11;


struct Q { 
	ll dist;
	int node, k;
	Q(ll a, int b, int c) : dist(a), node(b), k(c) {}
	
	bool operator < (const struct Q& other) const {
		return dist > other.dist;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;
	
	vector<P> adj[MAX_V];
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		
		adj[from].push_back({to, cost});
		adj[to].push_back({from, cost});
	}

	ll dist[MAX_V][30];
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++)
			dist[i][j] = INF;
	}
	dist[1][0] = 0;
	
	bool visited[MAX_V][30] = { false };

	priority_queue<Q> pq;
	pq.push({dist[1][0], 1, 0});
	
	while (!pq.empty()) {
		int cur, curK;
		do {
			cur = pq.top().node;
			curK = pq.top().k;
			
			pq.pop();
		} while (!pq.empty() && visited[cur][curK]);
		
		if (visited[cur][curK]) break;
		visited[cur][curK] = true;
		
		for (auto p : adj[cur]) {
			int nxt = p.first;
			int cost = p.second;
			
			if (curK + 1 <= K) {
				if (dist[nxt][curK + 1] > dist[cur][curK]) {
					dist[nxt][curK + 1] = dist[cur][curK];
					pq.push({dist[nxt][curK + 1], nxt, curK + 1});
				}
			}
			if (dist[nxt][curK] > dist[cur][curK] + cost) {
				dist[nxt][curK] = dist[cur][curK] + cost;
				pq.push({dist[nxt][curK], nxt, curK});
			}
		}
	}
	
	
	ll ans = INF;
	for (int i = 0; i <= K; i++) {
		ans = min(ans, dist[N][i]);
		//cout << dist[N][i] << '\n';
	} 
	
	cout << ans << '\n';
	return 0;
}
