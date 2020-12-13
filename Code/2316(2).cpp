#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 810;
const int INF = (int)2e9;

int N, M, ans;
int cap[MAX][MAX], flow[MAX][MAX];
int path[MAX];
vector<int> adj[MAX];

void maxFlow(int start, int end){
    while (true){
        memset(path, -1, sizeof(path));
        queue<int> Q;
        Q.push(start);

        while (!Q.empty()){
            int cur = Q.front();
            Q.pop();

            for (int nxt : adj[cur]){
                if (cap[cur][nxt] - flow[cur][nxt] > 0 && path[nxt] == -1){
                    Q.push(nxt);
                    path[nxt] = cur;

                    if (nxt == end) break;
                }
            }
        }

        if (path[end] == -1) return;
        int Flow = INF;

        for (int i = end; i != start; i = path[i]){
            Flow = min(Flow, cap[path[i]][i] - flow[path[i]][i]);
        }

        for (int i = end; i != start; i = path[i]){
            flow[path[i]][i] += Flow;
            flow[i][path[i]] -= Flow;
        }

        ans += Flow;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++){
        int from = i * 2, to = from + 1;
        adj[from].push_back(to);
        adj[to].push_back(from);
        cap[from][to] = 1;
    }

    for (int i = 0; i < M; i++){
        int from, to;
        cin >> from >> to;
        from--; to--;
        adj[from * 2 + 1].push_back(to * 2);
        adj[to * 2].push_back(from * 2 + 1);
        adj[to * 2 + 1].push_back(from * 2);
        adj[from * 2].push_back(to * 2 + 1);

        cap[from * 2 + 1][to * 2] = 1;
        cap[to * 2 + 1][from * 2] = 1;
    }

    maxFlow(0 * 2 + 1, 1 * 2);
    cout << ans << endl;

    return 0;
}
