#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("boards.txt");ofstream file_out("boards.txt")
#define f first
#define s second
//#define double long double
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
const double pi = acos(-1);
const double eps = 1e-10;
const int dx[] = { 0,1,0,-1 };
const int dy[] = { 1,0,-1,0 };
const int MOD = 987654321;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 10;
const int MAXR = 2e5 + 10;

int ccw(pii a, pii b, pii c) {
	ll pa = 1LL*a.f*b.s + 1LL*b.f*c.s + 1LL*c.f*a.s;
	ll pb = 1LL * a.s*b.f + 1LL * b.s*c.f + 1LL * c.s*a.f;
	if (pa == pb) return 0;
	else return pa - pb > 0 ? 1 : -1;
}

double dist(pii a, pii b) {
	double dx = (double)a.f-b.f, dy = (double)a.s-b.s;
	return sqrt(dx*dx + dy*dy);
	// can calculate sqrt here
}

double rotating_calipus(vector<pii> &pt) {
	sort(all(pt));
	vector<pii> up, lo;
	for (auto &p : pt) {
		while (up.size() >= 2 && ccw(*++up.rbegin(), *up.rbegin(), p) >= 0) up.pop_back();
		while (lo.size() >= 2 && ccw(*++lo.rbegin(), *lo.rbegin(), p) <= 0) lo.pop_back();
		up.emplace_back(p), lo.emplace_back(p);
	}

	if (up.size() <= 1) return 0.0;
	if (up.size()+lo.size()-2 <= 2) return dist(up[0], up[1]);

	double ret = 0;
	for (int i = 0, j = (int)lo.size()-1; i+1 < up.size() || j > 0;) {
		ret = max(ret, dist(up[i], lo[j]));
		if (i == up.size()-1) --j;
		else if (j == 0) ++i;
		else if ((up[i+1].s-up[i].s) * (lo[j].f-lo[j-1].f) > (up[i+1].f-up[i].f) * (lo[j].s-lo[j-1].s)) ++i;
		else --j;
	}
	return ret;
}
int main() {
	fio();
	int c; cin >> c;
	vector<pii> a(c);
	for (int i = 0; i < c; i++) cin >> a[i].f >> a[i].s;

	cout << fixed; cout.precision(12);
	cout << rotating_calipus(a) << endl; 
	
	return 0;
}
