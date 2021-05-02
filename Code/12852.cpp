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
const int MAXN = 1e6+10;
const int MAXR = 2e5 + 10;

int main() {
	fio();

	int n, p[MAXN];
	for (int i = 0; i < MAXN; i++) p[i] = i;
	cin >> n;

	bool v[MAXN] = {false};
	queue<pii> q;
	v[n] = true; q.push({n, 0});

	while (!q.empty()) {
		auto [c, k] = q.front();
		q.pop();

		if (c == 1) {
			cout << k << endl;
			break;
		}
		if (c%3 == 0 && !v[c/3]) {
			v[c/3] = true;
			p[c/3] = c;
			q.push({c/3, k+1});
		}
		if (c%2 == 0 && !v[c/2]) {
			v[c/2] = true;
			p[c/2] = c;
			q.push({c/2, k+1});
		}
		if (c-1 >= 0 && !v[c-1]) {
			v[c-1] = true;
			p[c-1] = c;
			q.push({c-1, k+1});
		}
	}

	vector<int> ans; 
	for (int i = 1; i != p[i]; i = p[i]) ans.pb(i);
	ans.pb(n);
	reverse(all(ans));
	for (int x : ans) cout << x << ' ';
	cout << endl;
	
	return 0;
}
