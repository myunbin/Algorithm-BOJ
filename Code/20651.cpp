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
const int MAX_N = 55;
const int INF = 1e9;

int main() {
	fio();

	int n, ans = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		int s = 0;
		for (int j = i; j < n; j++) {
			s += a[j];
			for (int k = i; k <= j; k++) {
				if (a[k] * (j - i + 1) == s) {
					ans++;
					break;
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
