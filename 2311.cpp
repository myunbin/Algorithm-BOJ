#include <iostream>
#include <algorithm>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_V = 2005;
const int INF = (int) 2e9;
int cap[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];
int cost[MAX_V][MAX_V];
vector<int> adj[MAX_V];

void addEgde(int from, int to, int capacity, int time){
    adj[from].push_back(to);
    adj[to].push_back(from);

    cap[from][to] = capacity;
    cost[from][to] = time;
    cost[to][from] = -time;
}

int MCMF(int S, int T){
    int result = 0;

    while (true) {
        int prev[MAX_V], dist[MAX_V];
        bool inQ[MAX_V] = {false};
        queue<int> Q;

        fill(prev, prev + MAX_V, -1);
        fill(dist, dist + MAX_V, INF);

        dist[S] = 0;
        inQ[S] = true;
        Q.push(S);

        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            inQ[cur] = false;

            for (int nxt : adj[cur]) {
                if (dist[nxt] > dist[cur] + cost[cur][nxt]) {
                    if (cap[cur][nxt] - flow[cur][nxt] > 0) {
                        dist[nxt] = dist[cur] + cost[cur][nxt];
                        prev[nxt] = cur;

                        if (!inQ[nxt]) {
                            inQ[nxt] = true;
                            Q.push(nxt);
                        }
                    }
                }
            }
        }

        if (prev[T] == -1) break;

        int curFlow = INF;
        for (int i = T; i != S; i = prev[i]) {
            curFlow = min(curFlow, cap[prev[i]][i] - flow[prev[i]][i]);
        }

        for (int i = T; i != S; i = prev[i]) {
            result += curFlow * cost[prev[i]][i];
            flow[prev[i]][i] += curFlow;
            flow[i][prev[i]] -= curFlow;
        }
    }

    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        addEgde(2 * i - 2, 2 * i - 1, 2, 0);
    }

    for (int i = 0; i < M; i++) {
        int from, to, time;
        cin >> from >> to >> time;

        addEgde(2 * from - 1, 2 * to - 2, 1, time);
        addEgde(2 * to - 1, 2 * from - 2, 1, time);
    }

    cout << MCMF(0, 2 * N - 1) << endl;

    return 0;
}