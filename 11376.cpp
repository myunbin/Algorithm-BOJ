#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 2005;
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++){
        int x;
        cin >> x;

        for (int j = 0; j < x; j++){
            int job;
            cin >> job;
            adj[i].push_back(job);
            adj[i + 1000].push_back(job);
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++){
        memset(visited, false, sizeof(visited));
        if (DFS(i)) ans++;
    }

    for (int i = 1 + 1000; i <= N + 1000; i++){
        memset(visited, false, sizeof(visited));
        if (DFS(i)) ans++;
    }

    cout << ans << endl;
    return 0;
}