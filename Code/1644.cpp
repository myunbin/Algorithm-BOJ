#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 4e6 + 10;

int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
    bool isPrime[MAX_N] = { 0 };
	fill(isPrime, isPrime + MAX_N, true);
	vector<int> prime;
	
    for (int i  = 2; i < MAX_N; i++){
		if (!isPrime[i]) continue;
		else prime.push_back(i);
		
        for (int j = i + i; j < MAX_N; j += i)
            isPrime[j] = false;
    }
	
	int n;
	cin >> n;
	
	int sum = 0;
	int s = 0, e = 0;
	int size = prime.size();
	int ans = 0;
	while (s <= e) {
		if (sum >= n) sum -= prime[s++];
		else if (e == size) break;
		else sum += prime[e++];
		
		if (sum == n) ans++;
	}

	cout << ans << '\n';
    return 0;
}
