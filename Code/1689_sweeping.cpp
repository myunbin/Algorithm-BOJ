#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	vector<pii> a;
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		a.push_back({s, 1});
		a.push_back({e, -1});
	}
	sort(a.begin(), a.end());
	
	int i = 0;
	int f = 0, ans = -1;
	
	while (i < a.size()) {
		int x = a[i].first;
		while (i < a.size() && x == a[i].first) {
			f += a[i].second;
			i++;
		}
		ans = max(ans, f);
	}
	
	cout << ans << '\n';
	
	return 0;
}
