#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define ends " "
#define pb(x) push_back(x)
#define f first
#define s second
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("input.in");ofstream file_out("output.out")
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, double> pdd;
const int MOD = 1000000007;
const ll LMOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1);
const double eps = 1e-10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int MAXN = 2e5+10;

int ccw(pii a, pii b, pii c) {
	ll pa = 1LL * a.f*b.s + 1LL * b.f*c.s + 1LL * c.f*a.s;
	ll pb = 1LL * a.s*b.f + 1LL * b.s*c.f + 1LL * c.s*a.f;
	if (pa == pb) return 0;
	else return pa - pb > 0 ? 1 : -1;
}

int main() {
	fio();
	int n;
	cin >> n;

	vector<pii> v(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &v[i].f, &v[i].s);
	sort(all(v));
	
	vector<pii> upper, lower;
	for (int i = 0; i < n; i++) {
		while (upper.size() >= 2 && ccw(*++upper.rbegin(), *upper.rbegin(), v[i]) >= 0) upper.pop_back();
		upper.push_back(v[i]);
		while (lower.size() >= 2 && ccw(*++lower.rbegin(), *lower.rbegin(), v[i]) <= 0) lower.pop_back();
		lower.push_back(v[i]);
	}
	//rotating calipus
	upper.insert(upper.end(), ++lower.rbegin(), --lower.rend());
	printf("%d", upper.size());
	return 0;
}
