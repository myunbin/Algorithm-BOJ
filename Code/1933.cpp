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

int main() {
	fio();

	int n; cin >> n;
	vector<tpi> a;
	for (int i = 0; i < n; i++) {
		int x1, x2, y;
		cin >> x1 >> y >> x2;
		a.push_back({x1, y, 1});
		a.push_back({x2, y, 0});
	}
	sort(all(a));
	
	multiset<int, greater<int>> s;
	int cury = 0, p = 0;
	
	while (p < a.size()) {
		auto [x, y, b] = a[p];
		while (p < a.size() && x == get<0>(a[p])) {
			auto [nx, ny, nb] = a[p];
			if (nb) s.insert(ny);
			else s.erase(s.find(ny));
			p++;
		}
		if (s.empty()) {
			cury = 0;
			cout << x << ' ' << cury << ' ';
			continue;
		}
		auto it = s.begin();
		if (cury != *it) {
			cury = *it;
			cout << x << ' ' << cury << ' ';
		}
	}
	return 0;
}
