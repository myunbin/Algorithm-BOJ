#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_R = 1e4 + 1;
struct p{
	int x, y;
	p(){}
	p(int x, int y) : x(x), y(y){}
	bool operator < (const p &o) const {
		if (y == o.y) return x < o.x;
		return y < o.y;
	}
};
bool cmp(const p &a, const p &b) {return a.x < b.x;}
int dist(p a, p b) {return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);}

int main() {
	fio();
	int n;
	cin >> n;
	vector<p> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].x >> a[i].y;
	sort(all(a), cmp);

	set<p> c; c.insert(a[0]), c.insert(a[1]);
	int ans = dist(a[0], a[1]), s = 0;
	
	for (int i = 2; i < n; i++) {
		p cur = a[i];
		while (s < i) {
			auto t = a[s];
			int dx = cur.x - t.x;
			if (dx * dx > ans) {
				c.erase(t);
				s++;
			}
			else break;
		}
		
		int d = (int)sqrt((double)ans) + 1;
		auto lp = p(-MAX_R, cur.y - d);
		auto up = p(MAX_R, cur.y + d);
		auto l = c.lower_bound(lp), u = c.upper_bound(up);
		for (auto it = l; it != u; it++) {
			int d = dist(cur, *it);
			ans = min(ans, d);
		}
		c.insert(cur);
	}
	cout << ans << '\n';
	return 0;
}
