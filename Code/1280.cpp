#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 200000;
const int MOD = 1000000007;
typedef long long int lld;

void update(vector<lld> &tree, int node, int start, int end, int index, lld delta) {
    if (index < start || end < index) return;

    tree[node] += delta;

    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, delta);
        update(tree, node * 2 + 1, mid + 1, end, index, delta);
    }
}

lld sum(vector<lld> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;

    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tree_h = (int)ceil(log2(MAX));
    int tree_size = (1 << (tree_h + 1));

    vector<lld> cnt_Tree;
    vector<lld> sum_Tree;
    cnt_Tree.resize(tree_size, 0);
    sum_Tree.resize(tree_size, 0);

    int N, x1; cin >> N >> x1;
    update(cnt_Tree, 1, 0, MAX, x1, (lld)1);
    update(sum_Tree, 1, 0, MAX, x1, (lld)x1);

    lld ans = 1;
    for (int i = 1; i < N; i++) {
        int x; cin >> x;
        lld L_cost = sum(cnt_Tree, 1, 0, MAX, 0, x - 1) * x - sum(sum_Tree, 1, 0, MAX, 0, x - 1);
        lld R_cost = sum(sum_Tree, 1, 0, MAX, x + 1, MAX) - x * sum(cnt_Tree, 1, 0, MAX, x + 1, MAX);
        ans = (L_cost + R_cost) % MOD * (ans % MOD);

        update(cnt_Tree, 1, 0, MAX, x, (lld)1);
        update(sum_Tree, 1, 0, MAX, x, (lld)x);
    }

    cout << ans % MOD << '\n';
    return 0;
}
