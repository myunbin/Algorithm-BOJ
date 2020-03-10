#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 201;
int N, M, S, d[MAX];
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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        cin >> S;
        for (int j = 1; j <= S; j++){
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++){
        memset(visited, false, sizeof(visited));
        if (DFS(i)) ans++;
    }

    cout << ans << endl;
    return 0;
}