#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
typedef long long ll;
const int MAX_N = 5e5 + 1;
int n, a[MAX_N], s[MAX_N];
ll ans;

void merge(int le, int ri) {
	int mid = le + ri >> 1;
	int lo = le, hi = mid + 1;
	int k = le;
	
	while (lo <= mid || hi <= ri) {
		if (hi > ri || (lo <= mid && a[lo] <= a[hi])) s[k++] = a[lo++];
		else {
			ans += (ll)(mid - lo + 1);
			s[k++] = a[hi++];
		}
	}
	for (int i = le; i <= ri; i++) a[i] = s[i];
}

void mergeSort(int le, int ri) {
	if (le >= ri) return;
	
	int mid = le + ri >> 1;
	mergeSort(le, mid); mergeSort(mid + 1, ri);
	merge(le, ri);
}

int main() {
	fio();
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	mergeSort(0, n - 1);
	
	cout << ans << '\n';
	
	return 0;
}
