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

bool cmp(pii a, pii b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	fio();
	int n, ans = 1;
	cin >> n;
	vector<pii> a(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i].first >> a[i].second;
	sort(all(a), cmp);
	
	vector<int> m;
	for (int i = 0; i < n; i++) {
		int s = a[i].second;
		while (!m.empty() && m.back() <= a[i].second) {
			s = min(s, m.back());
			m.pop_back();
		}
		m.push_back(s);
	}

	cout << m.size() << '\n';
	return 0;
}
