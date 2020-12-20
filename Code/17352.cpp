#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 3e5 + 1;
int parent[MAX_N];
int n;

int find(int a) {
	if (parent[a] < 0) return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	memset(parent, -1, sizeof(parent));
	cin >> n;
	for (int i = 0; i < n - 2; i++) {
		int u, v;
		cin >> u >> v;
		
		merge(u, v);
	}
	
	for (int i = 1; i < n; i++) {
		if (find(i) != find(i + 1)) {
			cout << i << ' ' << i + 1 << '\n';
			return 0;
		}
	}
}
