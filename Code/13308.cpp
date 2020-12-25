#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int MAX_N = 2501;
const int MAX_P = 2501;
const ll INF = 1e18;

vector<pii> adj[MAX_N];
int oil[MAX_N];
int N, M;

struct S {
	ll dist;
	int node, price;
	S(ll a, int b, int c) : dist(a), node(b), price(c){}
	bool operator < (const struct S& other) const {
		return dist > other.dist;
	}
};

void dijkstra() {
	ll dist[MAX_N][MAX_P];
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_P; j++)
			dist[i][j] = INF;
	}
	
	bool visited[MAX_N][MAX_P] = {false};
	
	priority_queue<S> pq;
	dist[1][oil[1]] = 0;
	pq.push({(ll)0, 1, oil[1]}); // dist, node, price
	
	while (!pq.empty()) {
		int curN, curP;
		do {
			curN = pq.top().node;
			curP = pq.top().price;
			pq.pop();
		} while (!pq.empty() && visited[curN][curP]);
		
		if (visited[curN][curP]) break;
		visited[curN][curP] = true;
		
		for (auto p : adj[curN]) {
			int nxtN = p.first;
			int cost = p.second;
			int nxtP = oil[nxtN];
			
			int minP = min(curP, nxtP);
			if (dist[nxtN][minP] > dist[curN][curP] + (ll)cost * curP) {
				dist[nxtN][minP] = dist[curN][curP] + (ll)cost * curP;
				pq.push({dist[nxtN][minP], nxtN, minP});
			}
		}
	}
	
	ll ans = INF;
	for (int i = 0; i < MAX_P; i++) 
		ans = min(ans, dist[N][i]);
	
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> oil[i];
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	
	dijkstra();
	
	return 0;
}
