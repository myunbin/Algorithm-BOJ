  #include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int MAX_V = 2001;
const int INF = 2e9;

int n, m, t;
int s, g, h;
vector<P> adj[MAX_V];

vector<int> dijkstra(int start) {
	vector<int> dist(MAX_V, INF);
  	bool visited[MAX_V] = { false };
  	priority_queue<P, vector<P>, greater<P>> pq;

  	dist[start] = 0;
  	pq.push({dist[start], start});

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
        		pq.push({dist[nxt], nxt});
      		}
    	}
  	}
	
	return dist;
}

void solve() {
  	cin >> n >> m >> t;
  	cin >> s >> g >> h;

 	for (int i = 0; i < m; i++) {
		int a, b, d;
 	    cin >> a >> b >> d;
 	    adj[a].push_back({b, d});
 	    adj[b].push_back({a, d});
  	}

  	vector<int> cand;
  	for (int i = 0; i < t; i++) {
    	int x; cin >> x;
    	cand.push_back(x);
  	}

  	vector<int> distS = dijkstra(s);
	vector<int> distG = dijkstra(g);
	vector<int> distH = dijkstra(h);
	
	sort(cand.begin(), cand.end());
	for (int d : cand) {
		if (distS[d] == distS[g] + distG[h] + distH[d]) cout << d << ' ';
		else if (distS[d] == distS[h] + distH[g] + distG[d]) cout << d << ' ';
	}
	
	cout << '\n';
} 
int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

  	int t; 
	cin >> t;
  	while (t--) {
    	solve();
		for (int i = 1; i <= MAX_V; i++)
			adj[i].clear();
  	}

  	return 0;
}
