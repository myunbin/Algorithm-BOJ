#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N = 100;
const int MAX_V = 2 * (MAX_N + 1);
const int S = MAX_V - 2;
const int E = MAX_V - 1;
const int INF = (int)2e9;

int N, M;
int cap[MAX_V][MAX_V];
int cost[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];
vector<int> adj[MAX_V];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = MAX_N; i < MAX_N + N; i++){
        cin >> cap[i][E];
        adj[E].push_back(i);
        adj[i].push_back(E);
    }

    for (int i = 0; i < M; i++){
        cin >> cap[S][i];
        adj[S].push_back(i);
        adj[i].push_back(S);
    }

    for (int i = 0; i < M; i++){
        for (int j = MAX_N; j < MAX_N + N; j++){
            cin >> cap[i][j];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }

    for (int i = 0; i < M; i++){
        for (int j = MAX_N; j < MAX_N + N; j++){
            cin >> cost[i][j];
            cost[j][i] = -cost[i][j];
        }
    }

    int MCMF = 0;
    int MaxFlow = 0;

    while (true){
        int prev[MAX_V], dist[MAX_V];
        bool inQ[MAX_V] = { false };
        queue<int> Q;

        fill(prev, prev + MAX_V, -1);
        fill(dist, dist + MAX_V, INF);

        dist[S] = 0;
        inQ[S] = true;
        Q.push(S);

        while (!Q.empty()){
            int cur = Q.front();
            Q.pop();
            inQ[cur] = false;

            for (int nxt : adj[cur]){
                if (dist[nxt] > dist[cur] + cost[cur][nxt]){
                    if (cap[cur][nxt] - flow[cur][nxt] > 0){
                        dist[nxt] = dist[cur] + cost[cur][nxt];
                        prev[nxt] = cur;

                        if (!inQ[nxt]){
                            inQ[nxt] = true;
                            Q.push(nxt);
                        }
                    }
                }
            }
        }

        if (prev[E] == -1) break;

        int curFlow = INF;
        for (int i = E; i != S; i = prev[i]){
            curFlow = min(curFlow, cap[prev[i]][i] - flow[prev[i]][i]);
        }

        for (int i = E; i != S; i = prev[i]){
            MCMF += curFlow * cost[prev[i]][i];
            flow[prev[i]][i] += curFlow;
            flow[i][prev[i]] -= curFlow;
        }
    }

    for (int i = 0; i < M; i++){
        MaxFlow += flow[S][i];
    }

    cout << MaxFlow << '\n' << MCMF << endl;

    return 0;
}
