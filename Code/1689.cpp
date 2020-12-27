#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	int n;
	cin >> n;
	
	vector<pii> a;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		a.push_back({s, e});
	}
	sort(a.begin(), a.end());
	
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(a[0].second);
	
	int ans = 1;
	for (int i = 1; i < n; i++) {
		int s = a[i].first, e = a[i].second;
		int topE = pq.top();
		
		if (topE <= s) {
			topE = e;
			pq.pop();
		}
		else ans++;
		
		pq.push(e);
	}
	cout << ans << '\n';
	return 0;
}
