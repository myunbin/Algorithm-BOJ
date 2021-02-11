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

int main() {
	fio();

	int n, m;
	cin >> n >> m;
	set<int> s;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		s.insert(b[i]);
	}
	sort(all(b));
	int c = 0;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(all(b), a[i]) - b.begin();
		if (b[idx] == a[i]) c++;
	}
	cout << s.size() - c << endl;
	return 0;
}
