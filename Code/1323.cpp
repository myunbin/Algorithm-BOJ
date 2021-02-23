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
const int MAXN = 110;
const int MAXR = 2e5 + 10;

int main() {
	fio();

	int n, k, ans = -1;
	cin >> n >> k;
	ll p = 1, m = n % k;
	while (p <= n) p *= 10;
	for (int i = 1; i <= k; i++) {
		if (!m) {ans = i; break;}
		m = (m*p + n) % k;
	}
	cout << ans << endl;
	return 0;
}

