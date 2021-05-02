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
const int MOD = 987654321;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 101;
const int MAXR = 2e5 + 10;

int main() {
	fio();
	int n;
	cin >> n;
	stack<int> s;
	int c = 1;
	string ans;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) {
		if (s.empty() || s.top() < a[i]) {
			while (s.empty() || s.top() < a[i]) {
				s.push(c++);
				ans += '+';
			}
		}
		if (!s.empty() && s.top() == a[i]) {
			s.pop();
			ans += '-';
		}
		else if (!s.empty() && s.top() != a[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	for (char c : ans) cout << c << endl;
	return 0;
}
