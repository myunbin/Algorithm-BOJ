#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int MAX_N = 1010;

int n, k;
vector<P> cord;

double getDist(int x1, int y1, int x2, int y2) {
	int dx = x1 - x2;
	int dy = y1 - y2;
	
	return (int)ceil(sqrt(dx * dx + dy * dy) / 10);
}

bool isPossible(int mid) {
	queue<int> q;
	vector<bool> visited(n, false);
	int dist[MAX_N] = { 0 };
	
	q.push(0);
	visited[0] = true;
	
	while (!q.empty()) {
		int curi = q.front();
		q.pop();
		
		int curx = cord[curi].first;
		int cury = cord[curi].second;
		
		if (curi == 1) {
			return (dist[1] - 1 <= k);
		}
		
		for (int i = 1; i < n + 2; i++) {
			if (visited[i]) continue;
			
			int nx = cord[i].first;
			int ny = cord[i].second;
			
			if (getDist(curx, cury, nx, ny) <= mid) {
				q.push(i);
				visited[i] = true;
				dist[i] = dist[curi] + 1;
			}
		}
	}
	
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	cin >> n >> k;
	
	cord.push_back({0, 0});
	cord.push_back({10000, 10000});
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		cord.push_back({x, y});
	}
	
	int le = 0, ri = getDist(0, 0, 10000, 10000);
	int ans = -1;
	
	while (le <= ri) {
		int mid = le + ri >> 1;
		
		if (isPossible(mid)) {
			ans = mid;
			ri = mid - 1;
		}
		else le = mid + 1;
	}
	
	cout << ans << '\n';
	
	return 0;
}
