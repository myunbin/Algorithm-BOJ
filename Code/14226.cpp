#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("boards.txt");ofstream file_out("boards.txt")
#define f first
#define s second
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
const int MAXN = 2500;
const int MAXR = 2e5 + 10;
int s;
void bfs() {
	queue<tpi> q;
	q.push({1, 0, 0});
	bool v[MAXN][MAXN] = {0};
	
	while (!q.empty()) {
		auto [cur, cb, d] = q.front();
		q.pop();

		if (cur == s) {
			cout << d << endl;
			return;
		}

		if (!v[cur][cur]) {
			q.push({cur, cur, d+1});
			v[cur][cur] = true;
		}
		if (cur+cb < MAXN && !v[cur+cb][cb]) {
			q.push({cur+cb, cb, d+1});
			v[cur+cb][cb] = true;
		}
		if (cur-1 > 0 && !v[cur-1][cb]) {
			q.push({cur-1, cb, d+1});
			v[cur-1][cb] = true;
		}
	}
}
int main() {
	fio();

	cin >> s;
	bfs();

	return 0;
}

