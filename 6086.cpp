#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 52;
const int INF = (int)2e9;

int N, ans;
int cap[MAX][MAX], flow[MAX][MAX], path[MAX];
vector<int> adj[MAX];

int CtoI(char c){
    if (c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

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

    cin >> N;

    for (int i = 0; i < N; i++){
        char from, to;
        int Capacity;
        cin >> from >> to >> Capacity;
        from = CtoI(from); to = CtoI(to);
        adj[from].push_back(to);
        adj[to].push_back(from);
        cap[from][to] += Capacity;
        cap[to][from] += Capacity;
    }

    maxFlow(CtoI('A'), CtoI('Z'));
    cout << ans << endl;

    return 0;
}