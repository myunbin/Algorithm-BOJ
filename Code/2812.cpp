#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	int n, k;
	string s;
	vector<int> a;
	
	cin >> n >> k >> s;
	
	for (int i = 0; i < n; i++)
		a.push_back(s[i] - '0');
	
	stack<int> st;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && k && st.top() < a[i]) {
			st.pop();
			k--;
		}
		st.push(a[i]);
	}
	
	vector<int> ans;
	
	while (!st.empty()) {
		if (k) {
			while (!st.empty() && k) {
				k--;
				st.pop();
			}
		}
		
		ans.push_back(st.top());
		st.pop();
	}
	
	reverse(ans.begin(), ans.end());
	for (int x : ans) cout << x;
	cout << '\n';
	return 0;
}
