#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 1;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	string s;
	int q;
	cin >> s >> q;
	s.insert(0, "1");
	
	int pSum[27][MAX_N] = { 0 };
	
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j < s.length(); j++) {
			pSum[i][j] = pSum[i][j - 1] + (s[j] - 'a' == i);
		}
	}
	
	while (q--) {
		char c;
		int s, e;
		cin >> c >> s >> e;
		s++; e++;
		c -= 'a';
		
		cout << pSum[c][e] - pSum[c][s - 1] << '\n';
	}
	return 0;
}
