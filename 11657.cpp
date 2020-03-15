#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX_V = 502;
const int INF = (int)2e9;

int dist[MAX_V], cycle[MAX_V];
bool inQ[MAX_V];
vector<pair<int, int>> adj[MAX_V];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int from, to, val;
        cin >> from >> to >> val;

        adj[from].push_back({to, val});
    }

    fill(dist, dist + MAX_V, INF);

    int start = 1;
    queue<int> Q;
    dist[start] = 0;
    inQ[start] = true;

    Q.push(start);
    cycle[start]++;

    while (!Q.empty()){
        int cur = Q.front();
        Q.pop();

        inQ[cur] = false;
        for (auto &p : adj[cur]){
            int nxt = p.first;
            int cost = p.second;

            if (dist[nxt] > dist[cur] + cost){
                dist[nxt] = dist[cur] + cost;

                if (!inQ[nxt]){
                    cycle[nxt]++;

                    if (cycle[nxt] >= N){
                        cout << "-1" << endl;
                        return 0;
                    }

                    Q.push(nxt);
                    inQ[nxt] = true;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++){
        if (i == start) continue;
        cout << ((dist[i] != INF) ? dist[i] : -1) << '\n';
    }

    return 0;
}