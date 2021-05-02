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
const int MAXN = 111;
const int MAXR = 2e5 + 10;

void solve() {
	int n;
	cin >> n;
	vector<pii> adj[MAXN], pos(n+2);
	cin >> pos[0].f >> pos[0].s;
	for (int i=1; i<=n; i++) cin >> pos[i].f >> pos[i].s;
	cin >> pos[n+1].f >> pos[n+1].s;
	n += 2;
	bool v[MAXN] = {false};
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			int c = abs(pos[i].f-pos[j].f)+abs(pos[i].s-pos[j].s);
			adj[i].push_back({j, c});
			adj[j].push_back({i, c});
		}
	}
	v[0] = true;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == n-1) {
			cout << "happy" << endl;
			return;
		}

		for (auto [nxt, c]: adj[cur]) {
			if (!v[nxt] && c <= 1000) {
				v[nxt] = true;
				q.push(nxt);
			}
		}
	}
	cout << "sad" << endl;
}
int main() {
	fio();
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
