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
const int MOD = 1234567891;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 555;
const int MAXR = 2e5 + 10;
int n, a[22][22], ans;
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
pii st = {2, 0};

tpi bfs(int i, int j) {
	bool v[22][22] = {0};
	queue<tpi> q;
	v[i][j] = true;
	q.push({i, j, 0});
	int piv = -1;
	vector<pii> t;
	while (!q.empty()) {
		auto [cx, cy, d] = q.front();
		q.pop();

		if (0 < a[cx][cy] && a[cx][cy] < st.f) {
			if (piv == -1) piv = d;
			else if (piv != d) break;
			t.push_back({cx, cy});
		}

		for (int k = 0; k < 4; k++) {
			int nx = cx+dx[k], ny = cy+dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (!v[nx][ny] && a[nx][ny] <= st.f) {
					v[nx][ny] = true;
					q.push({nx, ny, d+1});
				} 
			}
		}
	}
	if (t.empty()) return {-1, 0, 0};
	sort(all(t), [](pii a, pii b) {
		if (a.f == b.f) return a.s < b.s;
		return a.f < b.f;
	});
	a[t[0].f][t[0].s] = 0;
	if (st.f == ++st.s) ++st.f, st.s = 0;
	return {piv, t[0].f, t[0].s};
}
int main() {
	fio();
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 9) {
				x = i, y = j;
				a[i][j] = 0;
			}
		}
	}

	while (true) {
		auto [d, nx, ny] = bfs(x, y);
		//cout << nx << ' ' << ny << ' ' << d << endl;
		if (d == -1) break;
		x = nx, y = ny;
		ans += d;
	}
	
	cout << ans << endl;
	return 0;
}
