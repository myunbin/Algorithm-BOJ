#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("boards.txt");ofstream file_out("boards.txt")
#define f first
#define s second
#define double long double
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
const int MAXN = 3030;
const int MAXR = 2e5 + 10;
vector<pair<pii, pii>> po;
int p[MAXN];

int find(int a) {
	if (p[a] < 0) return a;
	return p[a] = find(p[a]);
}

bool merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return false;
	p[a] += p[b];
	p[b] = a;
	return true;
}

int ccw(pii p1, pii p2, pii p3) {
	int t1 = p1.f * p2.s + p2.f * p3.s + p3.f * p1.s;
	int t2 = p1.s * p2.f + p2.s * p3.f + p3.s * p1.f;
	return t1==t2 ? 0 : (t1-t2)/abs(t1-t2);
}

int segint(pii p1, pii p2, pii p3, pii p4) {
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
	memset(p, -1, sizeof(p));

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		po.push_back({{x1, y1}, {x2, y2}});
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (segint(po[i].f, po[i].s, po[j].f, po[j].s)) 
				merge(i, j);
		}
	}

	int cnt = 0, ans = 0; 
	for (int i = 0; i < n; i++) {
		if (p[i] < 0) {
			cnt++;
			ans = max(ans, -p[i]);
		}
	}

	cout << cnt << endl << ans << endl;
	return 0;
}

