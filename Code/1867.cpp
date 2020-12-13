#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 501;

int N, K;
vector<int> adj[MAX];
int A[MAX], B[MAX];
bool visited[MAX];

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
    cin >> N >> K;
    for (int i = 0; i < K; i++){
        int from, to;
        cin >> from >> to;

        adj[from].push_back(to);
    }
    cout << BiMatch() << endl;
    return 0;
}
