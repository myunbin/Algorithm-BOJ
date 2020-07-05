#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> P;
const int INF = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<P> line;
    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        line.push_back({s, e});
    }

    sort(line.begin(), line.end());

    int ans = 0, left = -INF, right = -INF;
    for (auto &p : line) {
        int curL = p.first;
        int curR = p.second;

        if (right < curL) {
            ans += right - left;
            left = curL;
            right = curR;
        }
        else {
            right = max(right, curR);
        }
    }
    ans += right - left;

    cout << ans << '\n';
    return 0;
}