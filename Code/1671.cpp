#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 105;
int d[MAX];
vector<int> adj[MAX];
bool visited[MAX];
int shark[MAX][3];

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

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++){
        for (int j = 0; j < 3; j++)
            cin >> shark[i][j];
    }

    for (int i = 1; i < N; i++){
        for (int j = i + 1; j <= N; j++){
            if (shark[i][0] >= shark[j][0] && shark[i][1] >= shark[j][1] && shark[i][2] >= shark[j][2]){
                adj[i].push_back(j);
                adj[i + 50].push_back(j);
            }
            else if (shark[i][0] <= shark[j][0] && shark[i][1] <= shark[j][1] && shark[i][2] <= shark[j][2]){
                adj[j].push_back(i);
                adj[j + 50].push_back(i);
            }
        }
    }

    int ans = 0;
    int a[] = {0, 50};
    for (int k = 0; k < 2; k++){
        for (int i = 1 + a[k]; i <= N + a[k]; i++){
            memset(visited, false, sizeof(visited));
            if (DFS(i)) ans++;
        }
    }

    cout << N -  ans << endl;
    return 0;
}
