#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<P> a;
	for (int i = 0; i < n; i++) {
		int c, s, e;
		cin >> c >> s >> e;
		a.push_back({s, e});
	}
	
	sort(a.begin(), a.end());
	
	int ans = 1;
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(a[0].second);
	
	for (int i = 1; i < n; i++) {
		int s = a[i].first;
		int e = a[i].second;
		
		int topE = pq.top();
		if (s < topE) ans++;
		else pq.pop();
		
		pq.push(e);
	}
	
	cout << ans << '\n';
	return 0;
}
