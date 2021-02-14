#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("input.txt");ofstream file_out("output.txt")
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
const int MOD = 1000000007; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e5 + 10;

struct fw {
    int sz; vector<ll> t;
    fw(int _sz) : sz(_sz), t(_sz + 1) {}
    void update(int i, ll v) {
        for (; i <= sz; i += (i & -i)) t[i] += v;
    }
    ll query(int i, ll s = 0) {
        for (; i > 0; i -= (i & -i)) s += t[i];
        return s;
    }
};

int n;
int main() {
	fio();

	cin >> n;
	vector<ll> d(n + 1, 0);
	fw t(n + 1);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		d[x] += t.query(n) - (x ? t.query(x) : 0);
		if (x) t.update(x, 1);
	}
	
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cout << ans << '\n';
		ans += d[i];
	}

	return 0;
}
