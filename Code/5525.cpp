#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("cowjump.in");ofstream file_out("cowjump.out")
#define f first
#define s second
#define double long double
#define db double
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
const int MOD = 1234567891;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 111;
const int MAXR = 2e5 + 10;

int main() {
	fio();
	int n, m;
	string s;
	cin >> n >> m >> s;
	int i = 0;
	int ans = 0;
	while (i < m) {
		if (s[i] == 'I') {
			i++;
			int l = 1;
			while (i < m && s[i-1] != s[i]) {
				l++;
				i++;
			}
			int k = (l-1)/2;
			if (k >= n) ans += k-n+1;
		}
		else i++;
	}
	cout << ans << endl;
	return 0;
}
