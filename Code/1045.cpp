#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
typedef pair<int, int> pii;
const int MAX_N = 55;

int parent[MAX_N];

int find(int a) {
	if (parent[a] < 0) return a;
	return parent[a] = find(parent[a]);
}

bool merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return false;
	if (parent[a] < parent[b]) {
		parent[a] += parent[b];
		parent[b] = a;
	}
	else {
		parent[b] += parent[a];
		parent[a] = b;
	}
	return true; 
}

int main() {
	fio();

	int n, m;
	cin >> n >> m;

	vector<pii> a;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = i + 1; j < n; j++) {
			if (s[j] == 'Y') a.push_back({i, j});
		}
	}

	int ans[MAX_N] = { 0 }, cnt = 0;
	bool v[MAX_N] = { false };
	for (int i = 0; i < MAX_N; i++) parent[i] = -1;
	
	for (int i = 0; i < a.size() && cnt < n - 1; i++) {
		auto p = a[i];
		if (merge(p.first, p.second)) {
			v[i] = true;
			++ans[p.first]; ++ans[p.second];
			++cnt;
		}
	}

	if (cnt < n - 1) {
		cout << -1 << '\n';
		return 0;
	}

	for (int i = 0; i < a.size() && cnt < m; i++) {
		if (v[i]) continue;
		auto p = a[i];
		++ans[p.first]; ++ans[p.second];
		++cnt;
	}

	if (cnt < m) cout << -1;
	else for (int i = 0; i < n; i++) cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}
