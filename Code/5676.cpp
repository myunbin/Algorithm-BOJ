#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int query(vector<int> &tree, int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 1;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return query(tree, node * 2, start, mid, left, right) * query(tree, node * 2 + 1, mid + 1, end, left, right);
}

int update(vector<int> &tree, int node, int start, int end, int index, int val) {
    if (index < start || end < index) return tree[node];

    if (start == end) return tree[node] = val;
    if (start != end) {
        int mid = (start + end) / 2;
        return tree[node] = update(tree, node * 2, start, mid, index, val) * update(tree, node * 2 + 1, mid + 1, end, index, val);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int N, K;
        cin >> N >> K;

        if (cin.eof()) return 0;

        int tree_h = (int)ceil(log2(N));
        int tree_size = (1 << (tree_h + 1));

        vector<int> tree(tree_size);

        for (int i = 0; i < N; i++) {
            int sign;
            cin >> sign;

            if (sign > 0) update(tree, 1, 0, N - 1, i, 1);
            else if (sign == 0) update(tree, 1, 0, N - 1, i, 0);
            else update(tree, 1, 0, N - 1, i, -1);
        }

        for (int i = 0; i < K; i++) {
            char oper;
            cin >> oper;

            if (oper == 'C') {
                int idx, val;
                cin >> idx >> val;

                if (val > 0) update(tree, 1, 0, N - 1, idx - 1, 1);
                else if (val == 0) update(tree, 1, 0, N - 1, idx - 1, 0);
                else update(tree, 1, 0, N - 1, idx - 1, -1);
            }

            else {
                int left, right;
                cin >> left >> right;

                int res = query(tree, 1, 0, N - 1, left - 1, right - 1);

                if (res > 0) cout << '+';
                else if (res == 0) cout << '0';
                else cout << '-';
            }
        }
        cout << '\n';
    }
}
