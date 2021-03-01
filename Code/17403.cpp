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
const int MAXN = 1e3 + 10;
const int MAXR = 2e5 + 10;
vector<pair<pii, int>> a;
int n, chk[MAXN];

int ccw(pii a, pii b, pii c) {
	ll pa = 1LL*a.f*b.s + 1LL*b.f*c.s + 1LL*c.f*a.s;
	ll pb = 1LL*a.s*b.f + 1LL*b.s*c.f + 1LL*c.s*a.f;
	return pa==pb ? 0 : (pa-pb)/abs(pa-pb);
}

void convexhull(int k) {
	vector<int> s[2], s1, s2;
	int m = 1;
	for (int p = 0; p < 2; p++) {
		for (int i = 0; i < n; i++) {
			if (chk[a[i].s]) continue;
			while (s[p].size() >= 2) {
				int j = s[p].back();
				s[p].pop_back();
				int k = s[p].back();
				if (m*ccw(a[k].f, a[j].f, a[i].f) < 0) {
					s[p].pb(j);
					break;
				}
			}
			s[p].pb(i);
		}
		m *= -1;
	}
	
	if (s[0].size()+s[1].size()-2 <= 2) return;
	for (int i = 0; i < 2; i++) 
		for (int x : s[i]) if (!chk[a[x].s]) chk[a[x].s] = k;
}

int main() {
	fio();
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].f.f >> a[i].f.s;
		a[i].s = i;
	}
	sort(all(a));
	for (int i = 1; i <= n; i++) convexhull(i);
	for (int i = 0; i < n; i++) cout << chk[i] << ' ';	
	return 0;
}
