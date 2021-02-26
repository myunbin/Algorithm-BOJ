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
const int MAXN = 4e5;
const int MAXR = 2e5 + 10;
ll gcd(int a, int b) {
	if (!b) return a;
	return gcd(a, b%a);
}

int main() {
	fio();

	ll g, l;
	cin >> g >> l;

	ll x = l/g;
	ll a, b;
	for (ll i = (ll)sqrt(x)+1; i >= 1; i--) {
		if (x % i == 0 && gcd(min(i, x/i), max(i, x/i)) == 1) {
			a = min(i, x/i), b = max(i, x/i);
			break;
		}
	}
	cout << g*a << ' ' << g*b << endl;
	return 0;
}

