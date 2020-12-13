#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;
const int MAX_V = 101;
const int MAX_M = 10010;
const int INF = 2e9;

struct T { int v, c, d; };
struct Q { 
	int dist, node, m;
	Q(int a, int b, int c) : dist(a), node(b), m(c) {}
	
	bool operator < (const struct Q& other) const {
		return dist > other.dist;
	}
};

void solve() {
	int N, M, K;
	cin >> N >> M >> K;
	
	vector<T> adj[MAX_V];
	for (int i = 0; i < K; i++) {
		int u, v, c, d;
		cin >> u >> v >> c >> d;
		
		adj[u].push_back({v, c, d});
	}
	
	int dist[MAX_V][MAX_M];
	bool visited[MAX_V][MAX_M] = { false };
	for (int i = 0; i < MAX_V; i++) {
		for (int j = 0; j < MAX_M; j++)
			dist[i][j] = INF;
	}
	dist[1][0] = 0;
	
	priority_queue<Q> pq;
	pq.push({dist[1][0], 1, 0});
	
	while (!pq.empty()) {
		int cur, curM;
		do {
			cur = pq.top().node;
			curM = pq.top().m;
			pq.pop();
		} while (!pq.empty() && visited[cur][curM]);
		
		if (visited[cur][curM]) break;
		visited[cur][curM] = true;
		
		for (T t : adj[cur]) {
			int nxt = t.v, nxtC = t.c, nxtD = t.d;
			
			if (curM + nxtC <= M) {
				if (dist[nxt][curM + nxtC] > dist[cur][curM] + nxtD) {
					dist[nxt][curM + nxtC] = dist[cur][curM] + nxtD;
					pq.push({dist[nxt][curM + nxtC], nxt, curM + nxtC});
				}
			}
		}
	}
	
	int ans = INF;
	for (int i = 0; i <= M; i++) ans = min(ans, dist[N][i]);
	
	if (ans == INF) cout << "Poor KCM" << '\n';
	else cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; 
	cin >> t;
	
	while (t--) {
		solve();	
	}
		
	return 0;
}
