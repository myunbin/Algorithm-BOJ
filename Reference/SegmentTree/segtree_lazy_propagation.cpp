#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAX = 1000;

struct Node { ll val, lazy; };
struct SegTree {
    Node tree[4 * MAX] = { 0 };
    int arr[MAX] = { 0 };

    ll init(int node, int start, int end) {
        if (start == end) return tree[node].val = arr[start];
        int mid = (start + end) / 2;
        return tree[node].val = init(node * 2, start, mid)
                                + init(node * 2 + 1, mid + 1, end);
    }

    void update_range(int node, int start, int end, int nodeL, int nodeR, ll diff) {
        //lazy 값이 남아 있는 경우 미리 value 업데이트 해주고 propagate 해야함
        if (tree[node].lazy != 0) {
            tree[node].val += (end - start + 1) * tree[node].lazy;
            if (start != end) {
                tree[node * 2].lazy += tree[node].lazy;
                tree[node * 2 + 1].lazy += tree[node].lazy;
            }
            tree[node].lazy = 0;
        }

        if (nodeR < start || end < nodeL) return;
        if (nodeL <= start && end <= nodeR) {
            tree[node].val += (end - start + 1) * diff;
            if (start != end) {
                tree[node * 2].lazy += diff;
                tree[node * 2 + 1].lazy += diff;
            }
            return;
        }
        int mid = (start + end) / 2;
        update_range(node * 2, start, mid, nodeL, nodeR, diff);
        update_range(node * 2 + 1, mid + 1, end, nodeL, nodeR, diff);

        tree[node].val = tree[node * 2].val + tree[node * 2 + 1].val;
    }

    ll sum(int node, int start, int end, int nodeL, int nodeR) {
        if (tree[node].lazy != 0) {
            tree[node].val += (end - start + 1) * tree[node].lazy;
            if (start != end) {
                tree[node * 2].lazy += tree[node].lazy;
                tree[node * 2 + 1].lazy += tree[node].lazy;
            }
            tree[node].lazy = 0;
        }

        if (nodeR < start || end < nodeL) return 0;
        if (nodeL <= start && end <= nodeR) return tree[node].val;

        int mid = (start + end) / 2;
        return sum(node * 2, start, mid, nodeL, nodeR)
               + sum(node * 2 + 1, mid + 1, end, nodeL, nodeR);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    SegTree segTree;
    for (int i = 0; i < N; i++) cin >> segTree.arr[i];
    segTree.init(1, 0, N - 1);

    M += K;
    while (M--) {
        int op, a, b;
        cin >> op >> a >> b;

        a--; b--;
        if (op == 1) {
            ll diff;
            cin >> diff;
            segTree.update_range(1, 0, N - 1, a, b, diff);
        }
        else cout << segTree.sum(1, 0, N - 1, a, b) << '\n';
    }
    return 0;
}
