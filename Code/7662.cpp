#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define ends " "
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("input.in");ofstream file_out("output.out")
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
const int MOD = 1000000007;
const ll LMOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1);
const double eps = 1e-10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int MAX_N = 2020;

void solve() {
	int q; cin >> q;
	multiset<int> a;
	for (int i = 0; i < q; i++) {
		char c; int n;
		cin >> c >> n;
		if (c == 'I') a.insert(n);
		else {
			if (a.empty()) continue;
			multiset<int>::iterator it1 = a.begin(), it2 = a.end(); it2--;
			if (n == 1) a.erase(it2);
			else a.erase(it1);
		}
	}

	if (a.empty()) {
		cout << "EMPTY" << '\n';
		return;
	}
	multiset<int>::iterator it1 = a.begin(), it2 = a.end(); it2--;
	cout << *it2 << ' ' << *it1 << '\n';
}

int main() {
	fio();

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
