#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
const int MAX = 301;

int N, M;
int map[MAX][MAX];
vector<int> adj[MAX * MAX];
int A[MAX * MAX], B[MAX * MAX];
bool visited[MAX * MAX];
int col[MAX][MAX];
int row[MAX][MAX];

void Numbering(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            col[i][j] = i + 1;
        }
    }

    for (int j = 0; j < M; j++){
        for (int i = 0; i < N; i++){
            row[i][j] = j + 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0){
                adj[row[i][j]].push_back(col[i][j]);
            }
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

    for (int i = 1; i <= M; i++){
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
    int K;
    cin >> N >> M >> K;

    for (int i = 0; i < K; i++){
        int x, y;
        cin >> x >> y;
        map[x - 1][y - 1] = 1;
    }

    Numbering();

    cout << BiMatch() << endl;
    return 0;
}