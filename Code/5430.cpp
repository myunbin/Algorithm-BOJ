#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("boards.txt");ofstream file_out("boards.txt")
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
const int MAXN = 10101;
const int MAXR = 2e5 + 10;

void solve() {
	string p; int n;
	cin >> p >> n;
	string s; cin >> s;
	int idx = 1;
	vector<int> a;
	while (idx < s.length()) {
		if ('0' <= s[idx] && s[idx] <= '9') {
			string x;
			while (idx < s.length() && '0' <= s[idx] && s[idx] <= '9')
			x += s[idx++];
			a.pb(stoi(x));
		}
		idx++;
	}

	int le = 0, ri = a.size()-1;
	bool d = true;
	
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == 'R') d = !d;
		else {
			if (le > ri) {
				cout << "error\n";
				return;
			}
			if (d) le++;
			else ri--;
		}
	}

	cout << '[';
	if (d) {
		for (int i = le; i <= ri; i++) {
			cout << a[i];
			if (i != ri) cout << ',';
		}
	}
	else {
		for (int i = ri; i >= le; i--) {
			cout << a[i];
			if (i != le) cout << ',';
		}
	}
	cout << "]\n";
}
int main() {
	fio();
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

