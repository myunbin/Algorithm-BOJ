#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_R = 1e5 + 10;
const int OFF = 5e4;
struct c{
	int x, y1, y2, s;
	bool operator < (const c &o) {
		return x < o.x;
	}
};

vector<pii> t(4 * MAX_R); //first = cnt, second = on/off
vector<c> a;
int n;

void update(int nd, int le, int ri, int ql, int qr, int v) {
	if (qr < le || ri < ql) return;
	if (ql <= le && ri <= qr) t[nd].first += v;
	else {
		int m = le + ri >> 1;
		update(nd<<1, le, m, ql, qr, v);
		update(nd<<1|1, m + 1, ri, ql, qr, v);
	}

	if (t[nd].first == 0) {
		if (le == ri) t[nd].second = 0;
		else t[nd].second = t[nd<<1].second + t[nd<<1|1].second;
	}
	else t[nd].second = ri - le + 1;
}

int main() {
	fio();

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1+=OFF, y1+=OFF, x2+=OFF, y2+=OFF;
		a.push_back({x1, y1, y2 - 1, 1});
		a.push_back({x2, y1, y2 - 1, -1});
	}
	sort(all(a));

	ll ans = 0;
	int l;
	for (int i = 0; i < 2 * n; i++) {
		if (i > 0) ans += 1LL * (a[i].x - l) * t[1].second; 
		update(1, 0, MAX_R, a[i].y1, a[i].y2, a[i].s);
		l = a[i].x;
	}
	
	cout << ans << '\n';
		
	return 0;
}
