#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAX_N = 110;
int dist[MAX_N][MAX_N];
bool relation[MAX_N][MAX_N];
bool check[MAX_N];
int n, m;

vector<int> bfs(int s) {
	queue<int> q;
	vector<int> ret;
	
	q.push(s);
	ret.push_back(s);
	check[s] = true;
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		for (int i = 1; i <= n; i++) {
			if (i != cur && relation[cur][i] && !check[i]) {
				check[i] = true;
				q.push(i);
				ret.push_back(i);
			}
		}
	}
	
	return ret;
}

void solve() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = (i == j) ? 0 : INF;
		}
	}
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		
		dist[a][b] = 1;
		dist[b][a] = 1;
		
		relation[a][b] = true;
		relation[b][a] = true;
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	int cnt = 0;
	vector<vector<int>> comm;
	
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			comm.push_back(bfs(i));
			cnt++;
		}
	}
	
	vector<int> ans;
	int sizeComm = comm.size();
	for (int k = 0; k < sizeComm; k++) {
		int minRe = INF;
		int minIdx;
		for (int i : comm[k]) {
			int Max = 0;
			
			for (int j : comm[k]) {
				if (i == j) continue;
				Max = max(Max, dist[i][j]);
			}
			
			if (minRe > Max) {
				minRe = Max;
				minIdx = i;
			}
		}
		
		ans.push_back(minIdx);
	}
	
	sort(ans.begin(), ans.end());
	
	cout << sizeComm << '\n';
	for (int x : ans) cout << x << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	solve();
	
	return 0;
}
