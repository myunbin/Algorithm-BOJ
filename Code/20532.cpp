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
const int MAXN = 1e5+10;
const int MAXR = 2e5 + 10;
int a[MAXN], cnt1[MAXN], cnt2[MAXN];
ll ans;
bool v[MAXN];
vector<int> adj[MAXN], divi[MAXN];

void dfs(int cur) {
	v[cur] = true;

	ans += cnt2[a[cur]];
	cnt1[a[cur]]++;
	for (int x : divi[a[cur]]) {
		cnt2[x]++;
		if (x != a[cur]) ans += cnt1[x];
	}
	for (int nxt : adj[cur]) {
		if (v[nxt]) continue;
		dfs(nxt);
	}
	cnt1[a[cur]]--;
	for (int x : divi[a[cur]]) cnt2[x]--;
}

int main() {
	fio();

	for (int i = 1; i <= 1e5; i++) {
		for (int j = i; j <= 1e5; j += i)
			divi[j].pb(i);
	}

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= n; i++) {
		int x; cin >> x;
		adj[x].pb(i);
	}
	dfs(1);
	cout << ans << endl;

	return 0;
}
