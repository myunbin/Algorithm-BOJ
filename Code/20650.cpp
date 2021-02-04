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
const int MAX_N = 55;
const int INF = 1e9;

int main() {
	fio();

	vector<int> a(7);
	for (int i = 0; i < 7; i++) cin >> a[i];
	sort(all(a));

	int A = a[0], sum = a[6];
	int B, C;
	for (int i = 1; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (a[i] + a[j] == sum - A) {
				B = a[i], C = a[j];	
				break;
			}
		}
	}
	cout << A << ' ' << B << ' ' << C << '\n';
	return 0;
}
