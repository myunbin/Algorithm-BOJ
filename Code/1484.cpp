#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	int g;
	cin >> g;
	
	vector<ll> a;
	a.push_back(1);
	for (ll i = 2;; i++) {
		if (i * i - a.back() > 100000) break;
		a.push_back(i * i);
	}
	
	int s = 0, e = 0;
	vector<int> ans;
	
	while (s <= e) {
		if (a[e] - a[s] > g) s++;
		else if (e == a.size()) break;
		else e++;
		
		if (a[e] - a[s] == g) 
			ans.push_back(e + 1);
	}
	
	if (ans.empty()) cout << -1 << '\n';
	else for (int x : ans) cout << x << '\n';
	
    return 0;
}
