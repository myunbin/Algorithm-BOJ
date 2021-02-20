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
const int MAXN = 1e5 + 10;
const int MAXR = 2e5 + 10;

vector<ll> tr, a;
ll dp[MAXN];
int n, d;
void update(int nd, int le, int ri, int i, ll v) {
	if (i < le || ri < i) return;
	if (le == ri) {
		tr[nd] = v;
		return;
	}
	int m = le+ri>>1;
	update(nd<<1, le, m, i, v), update(nd<<1|1, m+1, ri, i, v);
	tr[nd] = max(tr[nd<<1], tr[nd<<1|1]);
}

ll query(int nd, int le, int ri, int ql, int qr) {
	if (qr < le || ri < ql) return -INF;
	if (ql <= le && ri <= qr) return tr[nd];
	int m = le+ri>>1;
	return max(query(nd<<1, le, m, ql, qr), query(nd<<1|1, m+1, ri, ql, qr));
}

int main() {
	fio();

	cin >> n >> d;
	a.resize(n+1), tr.resize(4*n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < n; i++)
	 {
		int ql = max(0, i-d), qr = max(0, i-1);
		ll t = max(0LL, query(1,0,n-1,ql, qr)) + a[i];
		update(1,0,n-1,i,t);
	}
	cout << tr[1] << endl;
	return 0;
}

