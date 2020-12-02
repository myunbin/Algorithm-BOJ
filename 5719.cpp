#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;
const int MAX_V = 550;
const int INF = 2e9;

int N, M, S, D;
vector<P> adj[MAX_V];
vector<int> sp[MAX_V];

int solve() {
	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);
	dist[S] = 0;
	
	bool visited[MAX_V] = { false };
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({dist[S], S});
	
	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[cur]);
		
		if (visited[cur]) break;
		visited[cur] = true;
		
		for (auto p : adj[cur]) {
			int nxt = p.first;
			int cost = p.second;
			
			if (dist[nxt] > dist[cur] + cost) {
				dist[nxt] = dist[cur] + cost;
				pq.push({dist[nxt], nxt});
				
				sp[nxt].clear();
				sp[nxt].push_back(cur);
			}
			else if (dist[nxt] == dist[cur] + cost) {
				sp[nxt].push_back(cur);
			}
		}
	}
	
	return dist[D];
}

void erasePath() {
	queue<int> q;
	q.push(D);
	
	bool check[MAX_V][MAX_V] = { false };
	
	while (!q.empty()) {			
		int cur = q.front();
		q.pop();
		
		for (int nxt : sp[cur]) {
			if (check[cur][nxt]) continue;
			check[cur][nxt] = true;
			
			for (auto &find : adj[nxt]) {
				if (find.first == cur) {
					find.second = INF;
					q.push(nxt);
				}		
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (true) {	
		for (int i = 0; i < MAX_V; i++) {
			adj[i].clear();
			sp[i].clear();
		} 
		
		cin >> N >> M;
		if (N == 0 && M == 0) return 0;
		
		cin >> S >> D;
		
		for (int i = 0; i < M; i++) {
			int from, to, cost;
			cin >> from >> to >> cost;
			adj[from].push_back({to, cost});
		}
	
		solve();
		erasePath();
		
		int ans = solve();
		if (ans == INF) cout << -1 << '\n';
		else cout << ans << '\n';
	}
	return 0;
}
