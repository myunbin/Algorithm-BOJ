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
const int MAXN = 1e5+10;
const int MAXR = 2e5 + 10;
struct seg {
	pll s, e;
	int idx;
	bool operator == (const seg &o) const {
		return idx==o.idx;
	}
};
ll x;
db ev(seg s) {
	if (s.s.f == s.e.f) return s.s.s;
	return s.s.s+(db)(s.e.s-s.s.s)*(x-s.s.f)/(s.e.f-s.s.f);
}

bool operator < (seg s1, seg s2) {
	db ev1 = ev(s1), ev2 = ev(s2);
	return abs(ev1-ev2)>1e-9 && ev1<ev2;
}
int n;
vector<seg> v;
vector<pair<pll, int>> a;

int ccw(pll p1, pll p2, pll p3) {
	ll t1 = p1.f * p2.s + p2.f * p3.s + p3.f * p1.s;
	ll t2 = p1.s * p2.f + p2.s * p3.f + p3.s * p1.f;
	if (t1 == t2) return 0;
	return t1>t2 ? 1 : -1;
}

int segint(seg s1, seg s2){
	pll p1 = s1.s, p2 = s1.e, p3 = s2.s, p4 = s2.e;
	int r1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int r2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
	if (r1 == 0 && r2 == 0) {
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);
		return p3 <= p2 && p1 <= p4;
	}
	return r1 <= 0 && r2 <= 0;
}

int main() {
	fio();
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		pll s, e;
		cin >> s.f >> s.s >> e.f >> e.s;
		v.push_back({s, e, i});
		a.push_back({s, i});
		a.push_back({e, i});
	}
	sort(all(a));

	for (int i = 1; i < n*2; i++) {
		if (a[i].f == a[i-1].f) {
			cout << 1 << endl;
			return 0;
		}
	}

	set<seg> act;
	int ans = 0;
	for (auto [p, i] : a) {
		x = p.f;
		auto it = act.find(v[i]);
		if (it != act.end()) { //선분끝
			auto bf = it, af = it; af++;
			if (bf != act.begin() && af != act.end()) {
				bf--; 
				if (segint(*af, *bf)) {
					ans = 1;
					break;
				}
			}
			act.erase(it);
		}
		else { // 선분시작
			act.insert(v[i]);
			it = act.find(v[i]);
			auto bf = it, af = it; af++;
			if (af != act.end() && segint(*af, v[i])) {
				ans = 1;
				break;
			}
			if (bf != act.begin()) {
				bf--;
				if (segint(*bf, v[i])) {
					ans = 1;
					break;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}
