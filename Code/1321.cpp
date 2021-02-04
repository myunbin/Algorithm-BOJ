#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1e5 + 10;
const int INF = 1e9 + 1;
int n, m;
vector<int> tr;

void update(int i, int v) {
	for (; i <= n; i += (i & -i)) tr[i] += v;
}

ll query(int i, ll s = 0) {
	for (; i > 0; i -= (i & -i)) s += 1LL * tr[i];
	return s; 
}

void bs(int x) {
	int le = 1, ri = n;
	while (le <= ri) {
		int mid = le + ri >> 1;
		int a = query(mid - 1), b = query(mid);
		if (a < x && x <= b) {
			cout << mid << '\n';
			return;
		}
		else if (b < x) le = mid + 1;
		else if (x < b) ri = mid - 1;
	}
}

int main() {
	fio();

	cin >> n;
	tr.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		update(i, x);
	}
	cin >> m;
	while (m--) {
		int x, i, a;
		cin >> x >> i;
		if (x == 1) {
			cin >> a;
			update(i, a);
		}
		else bs(i);
	}
	
	return 0;
}
