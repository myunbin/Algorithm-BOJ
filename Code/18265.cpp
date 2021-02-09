#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;
const int MAX_N = 1e5 + 10;
const int INF = 2e9;

int main() {
	fio();
//	freopen("moobuzz.in","r",stdin);	
//	freopen("moobuzz.out","w",stdout);

	ll n;
	cin >> n;

	ll le = 0, ri = 2e10; 
	
	while (le + 1 < ri) {
		ll mid = le + ri >> 1;
		ll c = mid - mid / 3 - mid / 5 + mid / 15;
		if (c < n) le = mid;
		else ri = mid;
	}
	
	cout << ri << '\n';
	return 0;
}
