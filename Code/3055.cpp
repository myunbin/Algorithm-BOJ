#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("boards.txt");ofstream file_out("boards.txt")
#define f first
#define s second
#define double long double
#define db double
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
const int MOD = 987654321;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 55;
const int MAXR = 2e5 + 10;
string fr[MAXN];
int d1[MAXN][MAXN], d2[MAXN][MAXN];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs1() {
	queue<pii> q;
	bool v[MAXN][MAXN] = {false};
	for (int i = 0; i < n; i++) {
		fill(d1[i], d1[i]+m, INF);
		for (int j = 0; j < m; j++) {
			if (fr[i][j] == '*') {
				q.push({i, j});
				v[i][j] = true;
				d1[i][j] = 0;
			}
		}
	}	

	while (!q.empty()) {
		auto [cx, cy] = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = cx+dx[k], ny = cy+dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (v[nx][ny] || fr[nx][ny] == 'X'|| fr[nx][ny] == 'D') continue;
			v[nx][ny] = true;
			q.push({nx, ny});
			d1[nx][ny] = d1[cx][cy]+1; 
		}
	}
}

void bfs2() {
	queue<pii> q;
	bool v[MAXN][MAXN] = {false};

	for (int i = 0; i < n; i++) {
		fill(d2[i], d2[i]+m, -1);
		for (int j = 0; j < m; j++) {
			if (fr[i][j] == 'S') {
				q.push({i, j});
				d2[i][j] = 0;
				v[i][j] = true;
				break;
			}
		}
	}
	
	while (!q.empty()) {
		auto [cx, cy] = q.front();
		q.pop();

		if (fr[cx][cy] == 'D') {
			cout << d2[cx][cy] << endl;
			return;
		}

		for (int k = 0; k < 4; k++) {
			int nx = cx+dx[k], ny = cy+dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (v[nx][ny] || fr[nx][ny] == 'X') continue;
			if (d2[cx][cy]+1 < d1[nx][ny]) {
				v[nx][ny] = true;
				q.push({nx, ny});
				d2[nx][ny] = d2[cx][cy]+1;
			} 
		}
	}

	cout << "KAKTUS" << endl;
}
int main() {
	fio();
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> fr[i];
	bfs1(), bfs2();
	return 0;
}

