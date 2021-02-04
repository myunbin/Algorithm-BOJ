#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 10001;
const int INF = 1e9;
struct north{
	int x, y, idx;
	bool operator < (const north &o) {
		return x < o.x;
	}
};
struct east{
	int x, y, idx;
	bool operator < (const east &o) {
		return y < o.y;
	}
};

int n, ans[MAX_N];
vector<east> E;
vector<north> N;
vector<int> stop[MAX_N];
bool v[MAX_N];

int dfs(int cur) {
	if (ans[cur] != -1) return ans[cur];
	ans[cur] = 0;

	for (int nxt : stop[cur]) {
		ans[cur] += 1 + dfs(nxt);
	}

	return ans[cur];
}

int main() {
	fio();
	memset(ans, -1, sizeof(ans));

	cin >> n;
	for (int i = 0; i < n; i++) {
		char c; int x, y;
		cin >> c >> x >> y;
		if (c == 'E') E.push_back({x, y, i});
		else N.push_back({x, y, i});
	}

	sort(all(E)), sort(all(N));

	int szE = E.size(), szN = N.size();

	vector<bool> st(n, false);

	for (int i = 0; i < szE; i++) {
		for (int j = 0; j < szN; j++) {
			if (st[N[j].idx] || st[E[i].idx]) continue;

			int dx = N[j].x - E[i].x, dy = E[i].y - N[j].y;
			if (dx >= 0 && dy >= 0) {
				if (dx < dy) {
					st[N[j].idx] = true;
					stop[E[i].idx].pb(N[j].idx);
				}
				else if (dy < dx) {
					st[E[i].idx] = true;
					stop[N[j].idx].pb(E[i].idx);
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << dfs(i) << '\n';
	}

	return 0;
}
