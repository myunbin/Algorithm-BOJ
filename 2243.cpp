#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long int lld;
const int Candy_MAX = 1000001;
lld result;
int tree_size;

void update(vector<lld> &tree, int node, int start, int end, int index, int diff) {
    if (index < start || end < index) return;

    tree[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}

lld query(vector<lld> &tree, int node, int start, int end, int k) {
    if (start == end) return start;

    int mid = (start + end) / 2;

    if (tree[node * 2] >= k)
        return query(tree, node * 2, start, mid, k);

    k -= tree[node * 2];

    if (tree[node * 2 + 1] >= k)
        return query(tree, node * 2 + 1, mid + 1, end, k);

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tree_h = (int)ceil(log2(Candy_MAX));
    tree_size = (1 << (tree_h + 1));
    vector<lld> tree(tree_size);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;

        if (A == 1) { // 사탕을 빼는 경우
            int B; // 사탕의 순위
            cin >> B;

            int idx = query(tree, 1, 0, Candy_MAX - 1, B);
            cout << idx << '\n';
            result = 0;

            update(tree, 1, 0, Candy_MAX - 1, idx, -1);
        }
        else {
            int B, C;
            cin >> B >> C;

            update(tree, 1, 0, Candy_MAX - 1, B, C);
        }
    }
    return 0;
}