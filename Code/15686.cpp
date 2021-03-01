#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("cowjump.in");ofstream file_out("cowjump.out")
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

int n, m, ans = INF, a[MAXN][MAXN];
int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1};
vector<pii> c;

void bfs(vector<int> &s) {
	bool v[MAXN][MAXN] = {false};
	queue<tuple<int, int, int>> q;
	for (int x : s) {
		q.push({c[x].f, c[x].s, 0});
		v[c[x].f][c[x].s] = true;
	} 

	int ret = 0;
	while (!q.empty()) {
		auto [cx, cy, d] = q.front();
		q.pop();

		if (a[cx][cy] == 1) ret += d;

		for (int k = 0; k < 4; k++) {
			int nx = cx+dirx[k], ny = cy+diry[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (!v[nx][ny]) {
					q.push({nx, ny, d+1});
					v[nx][ny] = true;
				}
			}
		}		
	}

	ans = min(ans, ret);
}

void p(int i, int j, vector<int> &pi) {
	if (j == m) {
		bfs(pi);
		return;
	}
	if (i == c.size()) return;

	pi.pb(i);
	p(i+1, j+1, pi);
	pi.pop_back();
	p(i+1, j, pi);
}

int main() {
	fio();
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) c.push_back({i, j});
		}
	}	

	vector<int> pi;
	p(0, 0, pi);
	
	cout << ans << endl;
	return 0;
}
