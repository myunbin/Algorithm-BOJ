#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 5001;
const int MAX_W = 8e5;
const int INF = 1e9 + 1;

int main() {
	fio();

	bool chk[MAX_W] = { false };

	int w, n;
	cin >> w >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)	cin >> a[i];

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int s = a[i] + a[j];
			if (s > w) continue;
			if (chk[w - s]) {
				cout << "YES" << '\n';
				return 0;
			}
		}

		for (int j = 0; j < i; j++) chk[a[i] + a[j]] = true;
	
	}

	cout << "NO" << '\n';
	
	return 0;
}
