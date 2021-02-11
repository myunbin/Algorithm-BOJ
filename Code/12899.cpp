#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;
const int MAX_N = 2e6 + 1;
const int INF = 2e9;

vector<int> tr(4 * MAX_N);

void update(int nd, int le, int ri, int i, int v) {
	if (i < le || ri < i) return;
	if (le == ri) {
		tr[nd] += v;
		return;
	}
	int m = le + ri >> 1;
	update(nd << 1, le, m, i, v);
	update(nd << 1 | 1, m + 1, ri, i, v);
	tr[nd] = tr[nd << 1] + tr[nd << 1 | 1];
}

int query(int nd, int le, int ri, int k) {
	if (le == ri) return le;
	int m = le + ri >> 1;
	if (tr[nd << 1] < k) return query(nd << 1 | 1, m + 1, ri, k - tr[nd << 1]);
	return query(nd << 1, le, m, k);	
}

int main() {
	fio();

	int n;
	cin >> n;

	while (n--) {
		int t, x;
		cin >> t >> x;
		if (t == 1) update(1, 1, MAX_N, x, 1);
		else {
			int q = query(1, 1, MAX_N, x);
			cout << q << '\n';
			update(1, 1, MAX_N, q, -1);
		}
	}
	return 0;
}
