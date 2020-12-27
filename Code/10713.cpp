#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 100001;

int a[MAX_N], b[MAX_N], c[MAX_N], d[MAX_N], p[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> p[i];
	for (int i = 1; i <= n - 1; i++) cin >> a[i] >> b[i] >> c[i];
	
	for (int i = 0; i < m - 1; i++) {
		int s = min(p[i], p[i + 1]);
		int e = max(p[i], p[i + 1]);
		
		d[s]++; d[e]--;
	}
	
	for (int i = 1; i <= n - 1; i++) d[i + 1] += d[i];
    
	ll sum = 0;
	for (int i = 1; i <= n - 1; i++)
		sum += min((ll)a[i] * d[i], c[i] + (ll)b[i] * d[i]);
	
	cout << sum << '\n';
	return 0;
}
