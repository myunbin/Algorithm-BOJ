#include <iostream>
#include <algorithm>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_V = 2005;
const int Clone = 1000;
const int INF = (int)2e9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true){
        int V, E;
        cin >> V >> E;
        if (cin.eof()) return 0;

        int cap[MAX_V][MAX_V] = { 0 };
        int flow[MAX_V][MAX_V] = { 0 };
        int cost[MAX_V][MAX_V] = { 0 };
        vector<int> adj[MAX_V];

        for (int i = 1; i <= V; i++){
            int from = i;
            int to = i + Clone;

            cap[from][to] = 1;

            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        for (int i = 0; i < E; i++){
            int from, to, bomb;
            cin >> from >> to >> bomb;

            cap[from + Clone][to] = 1;

            adj[from + Clone].push_back(to);
            adj[to].push_back(from + Clone);
            cost[from + Clone][to] = bomb;
            cost[to][from + Clone] = -bomb;

            adj[to + Clone].push_back(from);
            adj[from].push_back(to + Clone);
        }

        int S = Clone + 1, T = V;
        int result = 0;

        //MCMF
        for (int k = 0; k < 2; k++){
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

            if (prev[T] == -1) break;

            int curFlow = INF;
            for (int i = T; i != S; i = prev[i]){
                curFlow = min(curFlow, cap[prev[i]][i] - flow[prev[i]][i]);
            }

            for (int i = T; i != S; i = prev[i]){
                result += curFlow * cost[prev[i]][i];
                flow[prev[i]][i] += curFlow;
                flow[i][prev[i]] -= curFlow;
            }
        }

        cout << result << endl;
    }
}