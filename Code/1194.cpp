#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 51;
struct t { int x, y, k; };
int n, m;
int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1};
int dist[MAX_N][MAX_N][1 << 6];
bool visited[MAX_N][MAX_N][1 << 6];
string s[MAX_N];

void bfs(int sx, int sy) {
	queue<t> q;
	q.push({sx, sy, 0});
	visited[sx][sy][0] = true;
	
	while (!q.empty()) {
		int curx = q.front().x;
		int cury = q.front().y;
		int curk = q.front().k;
		q.pop();
		
		if (s[curx][cury] == '1') {
			cout << dist[curx][cury][curk] << '\n';
			return;
		}
		
		for (int i = 0; i < 4; i++) {
			int nx = curx + dirx[i];
			int ny = cury + diry[i];
			
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				char ns = s[nx][ny];
				if (ns == '#') continue;
				else if ('a' <= ns && ns <= 'f') {
					if (!visited[nx][ny][curk | (1 << (ns - 'a'))]) {
						q.push({nx, ny, curk | (1 << (ns - 'a'))});
						visited[nx][ny][curk | (1 << (ns - 'a'))] = true;
						dist[nx][ny][curk | (1 << (ns - 'a'))] = dist[curx][cury][curk] + 1;
					}
				}
				else if ('A' <= ns && ns <= 'F') {
					if (curk & (1 << (ns - 'A'))) {
						if (!visited[nx][ny][curk]) {
							q.push({nx, ny, curk});
							visited[nx][ny][curk] = true;
							dist[nx][ny][curk] = dist[curx][cury][curk] + 1;
						}	
					}
				}
				else {
					if (!visited[nx][ny][curk]) {
						q.push({nx, ny, curk});
						visited[nx][ny][curk] = true;
						dist[nx][ny][curk] = dist[curx][cury][curk] + 1;
					}
				}
			}
		}
	}
	cout << -1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '0') {
				bfs(i, j);
				break;
			}
		}
	}
    
    return 0;
}
