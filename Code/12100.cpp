#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> ans;
int N;

void go(int n, int arr[][21]) {
    if (n == 5) return;
	
	int ret[4][21][21] = { 0 };
    int M = -1;

    vector<int> tmp[21];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] != 0)
                tmp[i].push_back(arr[i][j]);
        }
    }
	
    for (int i = 0; i < N; i++) {
		int size = tmp[i].size();
        for (int j = 0; j < size - 1; j++) {
            if (tmp[i][j] == tmp[i][j + 1]) {
                tmp[i][j] += tmp[i][j + 1];
                tmp[i][j + 1] = 0;
            }
        }
    }

    for (int i = 0; i < N; i++) {
		int size = tmp[i].size();
        for (int j = 0, k = 0; j < size; j++) {
            if (tmp[i][j] == 0) continue;
            M = max(M, tmp[i][j]);
            ret[0][i][k++] = tmp[i][j];
        }
    }

    vector<int> tmp2[21];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] != 0) tmp2[i].push_back(arr[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
		int size = tmp2[i].size();		
        for (int j = size - 1; j >= 1; j--) {
            if (tmp2[i][j] == tmp2[i][j - 1]) {
                tmp2[i][j] += tmp2[i][j - 1];
                tmp2[i][j - 1] = 0;
            }
        }
    }
    for (int i = 0; i < N; i++) {
		int size = tmp2[i].size();
        for (int j = size - 1, k = N - 1; j >= 0; j--) {
            if (tmp2[i][j] == 0) continue;
            M = max(M, tmp2[i][j]);
            ret[1][i][k--] = tmp2[i][j];
        }
    }

    vector<int> tmp3[21];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[j][i] != 0) tmp3[i].push_back(arr[j][i]);
        }
    }
    for (int i = 0; i < N; i++) {
		int size = tmp3[i].size();
        for (int j = 0; j < size - 1; j++) {
            if (tmp3[i][j] == tmp3[i][j + 1]) {
                tmp3[i][j] += tmp3[i][j + 1];
                tmp3[i][j + 1] = 0;
            }
        }
    }
    for (int i = 0; i < N; i++) {
		int size = tmp3[i].size();
        for (int j = 0, k = 0; j < size; j++) {
            if (tmp3[i][j] == 0) continue;
            M = max(M, tmp3[i][j]);
            ret[2][k++][i] = tmp3[i][j];
        }
    }

    vector<int> tmp4[21];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[j][i] != 0) tmp4[i].push_back(arr[j][i]);
        }
    }
    for (int i = 0; i < N; i++) {
		int size = tmp4[i].size();
        for (int j = size - 1; j >= 1; j--) {
            if (tmp4[i][j] == tmp4[i][j - 1]) {
                tmp4[i][j] += tmp4[i][j - 1];
                tmp4[i][j - 1] = 0;
            }
        }
    }
    for (int i = 0; i < N; i++) {
		int size = tmp4[i].size();
        for (int j = size - 1, k = N - 1; j >= 0; j--) {
            if (tmp4[i][j] == 0) continue;
            M = max(M, tmp4[i][j]);
            ret[3][k--][i] = tmp4[i][j];
        }
    }
	
	for (int i = 0; i < 4; i++) go(n + 1, ret[i]);
	
    ans.push_back(M);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

	int a[21][21] = { 0 };

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> a[i][j];
    }

    go(0, a);

    int M = -1;
    for (int x : ans) M = max(M, x);

    cout << M << '\n';
    return 0;
}
