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
const int MOD = 1000000007;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 10101;
const int MAXR = 2e5 + 10;

int v, e;
vector<int> adj[MAXN], radj[MAXN], st;
int vst[MAXN];

void dfs(int cur) {
	vst[cur] = 1;
	for (int nxt : adj[cur]) {
		if (vst[nxt]) continue;
		dfs(nxt);
	}
	st.pb(cur);
}

vector<int> ans[MAXN];
int p = 0;

void rdfs(int cur, int i) {
	vst[cur] = 1;
	ans[i].pb(cur);
	
	for (int nxt : radj[cur]) {
		if (vst[nxt]) continue;
		rdfs(nxt, i);
	}
}

void scc() {
	while (!st.empty()) {
		int h = st.back();
		st.pop_back();
		if (!vst[h]) rdfs(h, p++);
	}
}

int main() {
	fio();
	
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		radj[b].pb(a);
	}
	
	for (int i = 1; i <= v; i++) {
		if (!vst[i]) dfs(i);
	}
	
	memset(vst, 0, sizeof(vst));
	
	scc();
	
	cout << p << endl;
	for(int i = 0; i< p; i++) sort(all(ans[i]));
	sort(ans, ans + p);
	for (int i = 0; i < p; i++) {
		for (int x : ans[i]) cout << x << ' ';
		cout << "-1\n";
	}
	
	return 0;
}
