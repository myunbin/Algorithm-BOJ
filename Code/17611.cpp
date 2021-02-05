#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 5001;
const int OFF = 5e5 + 1;
const int RNG = 1e6 + 10;
const int INF = 1e9 + 1;

int n, px[RNG], py[RNG];

int main() {
	fio();

	cin >> n;
	int lx, ly;
	cin >> lx >> ly;
	lx += OFF, ly += OFF;
	int fx = lx, fy = ly;

	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x += OFF, y += OFF;
		if (lx == x) py[min(ly, y)]++, py[max(ly, y)]--;
		else px[min(lx, x)]++, px[max(lx, x)]--;
		lx = x; ly = y;
	}

	if (fx == lx) py[min(fy, ly)]++, py[max(fy, ly)]--;
	else px[min(fx, lx)]++, px[max(fx, lx)]--;

	for (int i = 1; i < RNG; i++) 
        px[i] += px[i - 1], py[i] += py[i - 1];

	int ans = 0;
	for (int i = 0; i < RNG; i++) 
		ans = max({ans, px[i], py[i]});

	cout << ans << '\n';
	
	return 0;
}
