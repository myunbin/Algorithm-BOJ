#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("boards.txt");ofstream file_out("boards.txt")
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
const int MAXN = 3030;
const int MAXR = 2e5 + 10;

int ccw(pii p1, pii p2, pii p3) {
	int t1 = p1.f * p2.s + p2.f * p3.s + p3.f * p1.s;
	int t2 = p1.s * p2.f + p2.s * p3.f + p3.s * p1.f;
	return t1==t2 ? 0 : (t1-t2)/abs(t1-t2);
}

int segint(pii p1, pii p2, pii p3, pii p4){
	int r1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int r2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
	if (r1 == 0 && r2 == 0) {
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);
		return p3 <= p2 && p1 <= p4;
	}
	return r1 <= 0 && r2 <= 0;
}

void solve() {
	pii a, b, c, d;
	cin >> a.f >> a.s >> b.f >> b.s;
	cin >> c.f >> c.s >> d.f >> d.s;

	pii ld = {min(c.f, d.f), min(c.s, d.s)};
	pii ru = {max(c.f, d.f), max(c.s, d.s)};

	if (ld.f <= min(a.f, b.f) && max(a.f, b.f) <= ru.f) {
		if (ld.s <= min(a.s, b.s) && max(a.s, b.s) <= ru.s) {
			cout << 'T' << endl;
			return;
		}	
	}

	pair<pii, pii> si[4];
	si[0] = {{ld.f, ld.s}, {ru.f, ld.s}};
	si[1] = {{ld.f, ru.s}, {ru.f, ru.s}};
	si[2] = {{ld.f, ld.s}, {ld.f, ru.s}};
	si[3] = {{ru.f, ld.s}, {ru.f, ru.s}};

	for (auto [p1, p2] : si) {
		if (segint(p1, p2, a, b)) {
			cout << 'T' << endl;
			return;
		}
	}
	cout << 'F' << endl;
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

