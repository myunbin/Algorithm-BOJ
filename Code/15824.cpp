#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
typedef long long ll;
const int MAX_N = 300005;
const int MOD = 1e9 + 7;

int main() {
	fio();
	
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());

	ll mod[MAX_N]; mod[0] = 1LL;
	for (int i = 1; i <= n; i++) mod[i] = mod[i - 1] * 2 % MOD;

	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum = (sum + (mod[i] - mod[n - i - 1]) * a[i] + MOD) % MOD;
	}

	cout << sum << '\n';

	return 0;
}
