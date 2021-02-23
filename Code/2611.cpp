#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("boards.txt");ofstream file_out("boards.txt")
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;
const int MOD = 987654321;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e3 + 10;
const int MAXR = 2e5 + 10;

int main() {
	fio();
	int n, m;
	cin >> n >> m;

	vector<pii> adj[MAXN];
	int ind[MAXN] = {0};
	for (int i = 0; i < m; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		adj[p].push_back({q, r});
		ind[q]++;
	}

	queue<int> q;
	q.push(1);
	
	int pr[MAXN] = {0}, d[MAXN] = {0};
	for (int i = 1; i <= n; i++) {
		int cur = q.front();
		q.pop();
		
		for (auto [nxt, cost] : adj[cur]) {
			if (d[nxt] < d[cur] + cost) {
				d[nxt] = d[cur] + cost;
				pr[nxt] = cur;
			}
			if (!(--ind[nxt])) q.push(nxt); 
		}
	}
	
	vector<int> tr; tr.pb(1);
	for (int c = pr[1]; c != 1; c = pr[c]) tr.pb(c);
	tr.pb(1), reverse(all(tr));

	cout << d[1] << endl;
	for (int x : tr) cout << x << ' ';

	return 0;
}

