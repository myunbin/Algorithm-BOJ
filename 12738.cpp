#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a;
vector<int> LIS;
int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    a.resize(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i];
    LIS.push_back(a[1]);

    for (int i = 2; i <= N; i++){
        if (LIS.back() < a[i]) LIS.push_back(a[i]);
        else {
            int pos = lower_bound(LIS.begin(), LIS.end(), a[i]) - LIS.begin();
            LIS[pos] = a[i];
        }
    }

    cout << LIS.size() << endl;
    return 0;
}