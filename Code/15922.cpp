#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
typedef long long ll;
typedef pair<int, char> pic;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	int n;
	cin >> n;

	vector<pii> a;
	vector<int> b;

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		a.push_back({s, e});
		b.push_back(s); b.push_back(e);
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	
	int d[MAX_N * 2] = { 0 };
	for (int i = 0; i < n; i++) {
		int s = lower_bound(b.begin(), b.end(), a[i].first) - b.begin();
		int e = lower_bound(b.begin(), b.end(), a[i].second) - b.begin();
		
		d[s]++; d[e]--;
	}
	
	for (int i = 0; i < b.size(); i++) {
		d[i + 1] += d[i];
	}
	
	ll ans = 0;
	for (int i = 0; i < b.size() - 1; i++) 
		if (d[i] > 0) ans += (ll)b[i + 1] - (ll)b[i];
	
	cout << ans << '\n';
	return 0;
}
