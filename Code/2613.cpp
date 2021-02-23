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

int n, m, a[303];

bool f(int x) {
	int s = 0, g = 1;
	for (int i = 0; i < n; i++) {
		s += a[i];
		if (s > x) s = a[i], g++;
	}
	return g<=m;
}

void trkans(int ans) {
	int s = 0, g = 0, c = 0;
	for (int i = 0; i < n; i++) {
		s += a[i];
		if (s > ans) {
			cout << c << ' ';
			c = 0, s = a[i], g++;
		}
		c++;
		if (n-i == m-g) break;
	}
	cout << c << ' ';
	for (int i = 0; i < m-g-1; i++) cout << 1 << ' ';
}

int main() {
	fio();
	cin >> n >> m;
	int le = 0, ri = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		le = max(le, a[i]);
		ri += a[i];
	}

	int ans = 0;
	while (le <= ri) {
		int m = le+ri>>1;
		if (f(m)) {
			ans = m;
			ri = m-1;
		} 
		else le = m+1;
	}

	cout << ans << endl;
	trkans(ans);
	return 0;
}

