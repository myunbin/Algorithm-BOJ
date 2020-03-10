#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 1005;
int d[MAX];
vector<int> adj[MAX];
bool visited[MAX];

bool DFS(int cur){
    for (int nxt : adj[cur]){
        if (visited[nxt]) continue;
        visited[nxt] = true;

        if (d[nxt] == 0 || DFS(d[nxt])){
            d[nxt] = cur;
            return true;
        }
    }
    return false;
}

void reset(){
    memset(d, 0, sizeof(d));
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < MAX; i++){
        adj[i].clear();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    scanf("%d", &T);

    while (T--){
        int N, M;
        scanf("%d %d", &N, &M);

        for (int i = 1; i <= M; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            for (int j = a; j <= b; j++){
                adj[i].push_back(j);
            }
        }

        int ans = 0;
        for (int i = 1; i <= M; i++){
            memset(visited, false, sizeof(visited));
            if (DFS(i)) ans++;
        }

        printf("%d\n", ans);
        reset();
    }
    return 0;
}