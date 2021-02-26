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

int p[MAXN];

int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	p[b] = a;
}

int main() {
	fio();
	for (int i = 0; i <= MAXN; i++) p[i] = i;

	int n, m, t;
	cin >> n >> m >> t;
	vector<int> tr;
	for (int i = 0; i < t; i++) {
		int x; cin >> x; 
		tr.pb(x);
	} 
	
	vector<int> q[MAXN];
	for (int i = 0; i < m; i++) {
		int c; cin >> c;
		for (int j = 0; j < c; j++) {
			int x; cin >> x;
			if (j) merge(x, q[i].back());
			q[i].pb(x);
		}
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		bool f = true;
		for (int x : q[i]) {
			for (int y : tr) {
				if (find(x) == find(y)) {
					f = false;
					break;
				}
			}
			if (!f) break;
		}
		ans += f;
	}

	cout << ans << endl;
	return 0;
}

