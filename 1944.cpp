#include <bits/stdc++.h>
using namespace std;
const int MAX_S = 51;
const int MAX_V = 255;
struct E {
	int u, v, w;
	E() : E(-1, -1, 0){}
	E(int a, int b, int c): u(a), v(b), w(c) {}
	bool operator < (const E& other) const { return w < other.w; }
};

char Map[MAX_S][MAX_S];
int Index[MAX_S][MAX_S];
int N, M;
vector<E> edge;

bool goAble(int x, int y) {
	if (0 <= x && x < N && 0 <= y && y < N) {
		if (Map[x][y] != '1') return true;
	}
	return false;
}

void bfs(int x, int y) {
	int dirx[] = {-1, 1, 0, 0};
	int diry[] = {0, 0, 1, -1};
	
	int dist[MAX_S][MAX_S] = { 0 };
	bool visited[MAX_S][MAX_S] = { false };
	queue<pair<int, int>> q;
	
	q.push({x, y});
	visited[x][y] = true;
	
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nxtX = curX + dirx[i];
			int nxtY = curY + diry[i];
			
			if (goAble(nxtX, nxtY) && !visited[nxtX][nxtY]) {
				visited[nxtX][nxtY] = true;
				dist[nxtX][nxtY] = dist[curX][curY] + 1;
				q.push({nxtX, nxtY});
				
				if (Map[nxtX][nxtY] == 'K') {
					edge.push_back({Index[x][y], Index[nxtX][nxtY], dist[nxtX][nxtY]});
				}
			}
		}
	}
}

int uf[MAX_V];

int find(int a) {
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return false;
	uf[a] = b;
	return true;
}

void solve () {
	cin >> N >> M;	
	for (int i = 0; i < N; i++)
		cin >> Map[i];
	
	vector<pair<int, int>> posK;
	
	int idx_cnt = 1;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Map[i][j] == 'S' || Map[i][j] == 'K')
				Index[i][j] = idx_cnt++;
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Map[i][j] == 'S') {
				bfs(i, j);
				Map[i][j] = '0';
			}
			if (Map[i][j] == 'K') 
				posK.push_back({i, j});
		}
	}
	
	for (int i = 0; i < M; i++) {
		bfs(posK[i].first, posK[i].second);
		Map[posK[i].first][posK[i].second] = '0';
	}
	
	sort(edge.begin(), edge.end());
	int ans = 0, cnt = 0;
	fill(uf, uf + MAX_V, -1);
	
	for (E e : edge) {
		if (merge(e.u, e.v)) {
			ans += e.w;
			if(++cnt == M) break;
		}
	}
	
	if (cnt < M) ans = -1;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
