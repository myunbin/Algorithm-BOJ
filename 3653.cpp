#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long lld;

struct SegmentTree {
    vector<lld> tree;
    vector<int> idx;

    SegmentTree(int N, int M) {
        int tree_h = (int)ceil(log2(N + M + 1));
        int tree_size = (1 << (tree_h + 1));

        tree.resize(tree_size);
        idx.resize(N + M - 1);
    };
    lld query(int node, int start, int end, int left, int right) {
        if (end < left || right < start) return 0;
        if (left <= start && end <= right) return tree[node];

        int mid = (start + end) / 2;
        return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
    }
    void update(int node, int start, int end, int index, int diff) {
        if (index < start || end < index) return;

        tree[node] += diff;

        if (start != end) {
            int mid = (start + end) / 2;
            update(node * 2, start, mid, index, diff);
            update(node * 2 + 1, mid + 1, end, index, diff);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        SegmentTree SegTree(N, M);

        int top = N + 1;

        for (int i = 1; i <= N; i++) {
            SegTree.idx[i] = N - (i - 1);
            SegTree.update(1, 0, N + M, SegTree.idx[i], 1);
        }
        for (int i = 1; i <= M; i++) {
            int num;
            cin >> num;

            cout << SegTree.query(1, 0, N + M, SegTree.idx[num] + 1, N + M) << ' ';

            SegTree.update(1, 0, N + M, SegTree.idx[num], -1);
            SegTree.idx[num] = top;
            SegTree.update(1, 0, N + M, SegTree.idx[num], 1);
            top++;
        }
        cout << '\n';
    }
    return 0;
}