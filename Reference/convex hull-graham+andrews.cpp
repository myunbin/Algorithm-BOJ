#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int ccw(pii a, pii b, pii c) {
	ll pa = 1LL * a.x*b.y + 1LL * b.x*c.y + 1LL * c.x*a.y;
	ll pb = 1LL * a.y*b.x + 1LL * b.y*c.x + 1LL * c.y*a.x;
	if (pa == pb) return 0;
	else return pa - pb > 0 ? 1 : -1;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<pii> V(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &V[i].x, &V[i].y);
	sort(V.begin(), V.end());
	
	vector<pii> upper, lower;
	for (int i = 0; i < n; i++) {
		while (upper.size() >= 2 && ccw(*++upper.rbegin(), *upper.rbegin(), V[i]) >= 0) upper.pop_back();
		upper.push_back(V[i]);
		while (lower.size() >= 2 && ccw(*++lower.rbegin(), *lower.rbegin(), V[i]) <= 0) lower.pop_back();
		lower.push_back(V[i]);
	}
	//rotating calipus
	upper.insert(upper.end(), ++lower.rbegin(), --lower.rend());
	printf("%d", upper.size());
	return 0;
}
