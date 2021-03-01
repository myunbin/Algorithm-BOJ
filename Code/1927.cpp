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
const int MAXN = 1e5+10;
const int MAXR = 2e5 + 10;

int main() {
	fio();
	
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	while (n--) {
		int x; cin >> x;
		if (x) pq.push(x);
		else {
			cout << (pq.empty() ? 0 : pq.top()) << endl;
			if (!pq.empty()) pq.pop();
		}
	}

	return 0;
}
