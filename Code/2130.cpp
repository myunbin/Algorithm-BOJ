#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 50050;
const int RNG = 1e6 + 10;

int main() {
	fio();

	int n, v;	
	cin >> n;

	int p[RNG] = { 0 };
	for (int i = 0; i < n; i++) {
		int b, h, w, d;
		cin >> b >> h >> w >> d;
		p[b] += w * d, p[b + h] -= w * d;
	}
	cin >> v;

	for (int i = 1; i < RNG; i++) p[i] += p[i - 1];

	double ans = 0;
	for (int i = 0; i < RNG; i++) {
		if (v - p[i] <= 0) {
			printf("%.2lf\n", (double)i + (double)v / p[i]);
			return 0;
		}
		v -= p[i];
	}

	printf("OVERFLOW\n");
	return 0;
}
