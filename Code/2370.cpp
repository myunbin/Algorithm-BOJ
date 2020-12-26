#include <bits/stdc++.h>
using namespace std;
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
	
	vector<int> p(3e4, 0);
	
	for (int i = 0; i < n; i++) {
		int x = a[i].first, y = a[i].second;
		int s = lower_bound(b.begin(), b.end(), x) - b.begin();
		int e = lower_bound(b.begin(), b.end(), y) - b.begin();
		
		for (int j = s; j <= e; j++) p[j] = i + 1;
	}
	
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	cout << p.size() - 1 << '\n';

	return 0;
}
