#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
typedef pair<int, int> pii;
const int MAX_V = 1e5 + 1;
vector<pii> adj[MAX_V];
bool visited[MAX_V];
int v, dist[MAX_V];

void dfs(int cur) {
	visited[cur] = true;
	for (auto p : adj[cur]) {
		int nxt = p.first, cost = p.second;
		if (visited[nxt]) continue;
		dist[nxt] = dist[cur] + cost;
		dfs(nxt);
	}
}

int main() {
	fio();
	
	cin >> v;
	for (int i = 0; i < v; i++) {
		int u; cin >> u;
		while (true) {
			int x, c;
			cin >> x; 
			if (x == -1) break;
			cin >> c;
			
			adj[u].push_back({x, c});
		}
	}
	
	dfs(1);
	int maxD = -1, maxI = -1;
	for (int i = 1; i <= v; i++) {
		if (maxD < dist[i]) {
			maxD = dist[i];
			maxI = i;
		}
	}
	
	memset(dist, 0, sizeof(dist));
	memset(visited, false, sizeof(visited));
	
	dfs(maxI);
	int ans = -1;
	for (int i = 1; i <= v; i++) ans = max(ans, dist[i]);

	cout << ans << '\n';
	return 0;
}
