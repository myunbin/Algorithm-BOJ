#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAX_N = 202;
int dist[MAX_N][MAX_N];
int cost[MAX_N][MAX_N];
int n, m;

void solve() {
	cin >> n >> m;
	
	int ans[MAX_N][MAX_N];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = (i == j) ? 0 : INF;
			cost[i][j] = (i == j) ? 0 : INF;
			ans[i][j] = -1;
		}
	}
	
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;v--;
		
		cost[u][v] = min(cost[u][v], w);
		cost[v][u] = min(cost[v][u], w);
		
		dist[u][v] = min(dist[u][v], w);
		dist[v][u] = min(dist[v][u], w);
	}
	
	
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			for (int k = 0; k < n; k++) {
				if (cost[i][k] == 0) continue;
				if (cost[i][k] + dist[k][j] == dist[i][j])
					ans[i][j] = k;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				cout << "- ";
				continue;
			}
			cout << ans[i][j] + 1 << ' ';
		}
		cout << '\n';
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	solve();
	
	return 0;
}
