#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("boards.txt");ofstream file_out("boards.txt")
#define f first
#define s second
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;
const int MOD = 987654321;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1010;
const int MAXR = 2e5 + 10;
pii p[4];

int ccw(pii p1, pii p2, pii p3) {
	int t1 = p1.f * p2.s + p2.f * p3.s + p3.f * p1.s;
	int t2 = p1.s * p2.f + p2.s * p3.f + p3.s * p1.f;
	return t1==t2? 0 : (t1-t2)/abs(t1-t2);
}

int main() {
	fio();

	for (int i = 0; i < 4; i++) 
		cin >> p[i].f >> p[i].s;
	
	int c1 = ccw(p[0], p[1], p[2]) * ccw(p[0], p[1], p[3]);
	int c2 = ccw(p[2], p[3], p[0]) * ccw(p[2], p[3], p[1]);
	cout << (c1 == -1 && c2 == -1) << endl;
	return 0;
}

