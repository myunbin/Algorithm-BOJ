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
	deque<int> d;

	while (n--) {
		string s; 
		cin >> s;
		int x;

		if (s == "push_front") {
			cin >> x;
			d.push_front(x);
		}
		else if (s == "push_back") {
			cin >> x;
			d.push_back(x);
		}
		else if (s == "pop_front") {
			cout << (d.empty()?-1:d.front()) << endl;	
			if (!d.empty()) d.pop_front();
		}
		else if (s == "pop_back") {
			cout << (d.empty()?-1:d.back()) << endl;
			if (!d.empty()) d.pop_back();
		}
		else if (s == "size") cout << d.size() << endl;
		else if (s == "empty") cout << d.empty() << endl;
		else if (s == "front") cout << (d.empty()?-1:d.front()) << endl;
		else if (s == "back") cout << (d.empty()?-1:d.back()) << endl;
	}

	return 0;
}
