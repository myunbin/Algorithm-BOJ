#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int MAX_V = 900;
const int S = MAX_V - 2;
const int T = MAX_V - 1;
const int WORK = 400;
const int INF = (int) 2e9;

vector<int> adj[MAX_V];
int cap[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];
int cost[MAX_V][MAX_V];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cap[S][i] = 1;

        adj[S].push_back(i);
        adj[i].push_back(S);
    }

    for (int i = 1; i <= M; i++) {
        cap[i + WORK][T] = 1;

        adj[i + WORK].push_back(T);
        adj[T].push_back(i + WORK);
    }

    for (int i = 1; i <= N; i++) {
        int wNum;
        cin >> wNum;

        for (int j = 0; j < wNum; j++) {
            int workNo, c;
            cin >> workNo >> c;

            adj[i].push_back(workNo + WORK);
            adj[workNo + WORK].push_back(i);

            cost[i][workNo + WORK] = c;
            cost[workNo + WORK][i] = -c;

            cap[i][workNo + WORK] = 1;
        }
    }

    int result = 0;
    int cnt = 0;

    while (true) {
        int prev[MAX_V], dist[MAX_V];
        bool inQ[MAX_V] = { 0 };

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

            for (int &nxt : adj[cur]) {
                if (cap[cur][nxt] - flow[cur][nxt] > 0) {
                    if (dist[nxt] > dist[cur] + cost[cur][nxt]) {
                        dist[nxt] = dist[cur] + cost[cur][nxt];
                        prev[nxt] = cur;

                        if (!inQ[nxt]) {
                            Q.push(nxt);
                            inQ[nxt] = true;
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

        for (int i = T; i != S; i = prev[i]){
            result += curFlow * cost[prev[i]][i];
            flow[prev[i]][i] += curFlow;
            flow[i][prev[i]] -= curFlow;
        }

        cnt++;
    }

    cout << cnt << '\n' << result << endl;
    return 0;
}
