#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int cache[10010][101];
int N, T;
int cost[101];
int score[101];

int go(int t, int idx){
    if (t < 0) return 0;
    if (idx > N) return 0;

    int &ret = cache[t][idx];
    if (ret != -1) return ret;

    ret = go(t, idx + 1);
    
    if (t - cost[idx] >= 0){
        ret = max(ret, go(t - cost[idx], idx + 1) + score[idx]);
    }
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cache, -1, sizeof(cache));

    cin >> N >> T;
    for (int i = 1; i <= N; i++){
        cin >> cost[i] >> score[i];
    }

    cout << go(T, 1);

    return 0;
}