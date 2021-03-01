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
pii piv;
int n;
vector<pii> a;

int ccw(pii p1, pii p2, pii p3) {
	ll t1 = 1LL * p1.f * p2.s + 1LL * p2.f * p3.s + 1LL * p3.f * p1.s;
	ll t2 = 1LL * p1.s * p2.f + 1LL * p2.s * p3.f + 1LL * p3.s * p1.f;
	return t1==t2 ? 0 : (t1-t2)/abs(t1-t2);
}

bool cmp(pii a, pii b) {
	return ccw(piv, a, b)>0; // -1도 참이에요
}

int main() {
	fio();
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a.push_back({x, y});
	}
	sort(all(a));
	vector<int> s1, s2;
	s1.pb(0);
	
	// uppper
	for (int i = 1; i < n; i++) {
		while (s1.size() >= 2) {
			int j = s1.back();
			s1.pop_back();
			int k = s1.back();
			if (ccw(a[k], a[j], a[i]) < 0) {
				s1.pb(j);
				break;
			}
		}
		s1.pb(i);
	}
	
	s2.pb(0);
	for (int i = 1; i < n; i++) {
		while (s2.size() >= 2) {
			int j = s2.back();
			s2.pop_back();
			int k = s2.back();
			if (ccw(a[k], a[j], a[i]) > 0) {
				s2.pb(j);
				break;
			}
		}
		s2.pb(i);
	}
	
	cout << s1.size()+s2.size()-2 << endl;
	
	return 0;
}

