#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
const int MAX = 101;

int N;
string map[MAX];
vector<int> adj[MAX * MAX];
int A[MAX * MAX], B[MAX * MAX];
bool visited[MAX * MAX];
int col[MAX][MAX];
int row[MAX][MAX];
int cnt;

void Numbering(){
    bool check;
    int Ccnt = 1;
    int Rcnt = 1;

    for (int i = 0; i < N; i++) {
        check = false;

        for (int j = 0; j < N; j++) {
            if (map[i][j] == '.') {
                col[i][j] = Ccnt;
                check = true;
            }
            else {
                if (check) {
                    Ccnt++;
                    check = false;
                }
            }
        }

        if (check) Ccnt++;
    }

    for (int j = 0; j < N; j++) {
        check = false;

        for (int i = 0; i < N; i++) {
            if (map[i][j] == '.') {
                row[i][j] = Rcnt;
                check = true;
            }
            else {
                if (check) {
                    Rcnt++;
                    check = false;
                }
            }
        }

        if (check) Rcnt++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'X') continue;

            adj[row[i][j]].push_back(col[i][j]);
            cnt = max(cnt, row[i][j]);
        }
    }
}
bool DFS(int cur) {
    visited[cur] = true;
    for (int nxt : adj[cur]){
        if (B[nxt] == -1 || (!visited[B[nxt]] && DFS(B[nxt]))){
            A[cur] = nxt;
            B[nxt] = cur;
            return true;
        }
    }
    return false;
}

int BiMatch(){
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    int ans = 0;
    N = cnt;

    for (int i = 1; i <= N; i++){
        if (A[i] == -1){
            memset(visited, false, sizeof(visited));
            if (DFS(i)) ans++;
        }
    }

    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> map[i];
    Numbering();

    cout << BiMatch() << endl;
    return 0;
}
