#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N = 100; // MAX N, M
const int MAX_V = 2 * (MAX_N + 1); // MAX Vertex amount
const int S = MAX_V - 2; // num of Source
const int E = MAX_V - 1; // num of Sink
const int INF = (int) 2e9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 정점 번호 : 0 ~ MAX_N : 서점, MAX_N ~ MAX_N + MAX_N : 사람
    int N, M;
    int cap[MAX_V][MAX_V] = { 0 };
    int cost[MAX_V][MAX_V] = { 0 };
    int flow[MAX_V][MAX_V] = { 0 };
    vector<int> adj[MAX_V];

    cin >> N >> M;
    // 사람 정점 -> 싱크 , 비용 0, 간선의 capacity 는 살 수 있는 최대 책의 수
    for (int i = MAX_N; i < MAX_N + N; i++){
        cin >> cap[i][E];
        adj[i].push_back(E);
        adj[E].push_back(i);
    }
    // 소스 -> 서점 , 소스에서 서점의 비용 0, 간선의 capacity 는 사갈 수 있는 최대 책의 수
    for (int i = 0; i < M; i++){
        cin >> cap[S][i];
        adj[S].push_back(i);
        adj[i].push_back(S);
    }
    // 서점i -> 사람j 사이의 간선 추가 , 비용 cost[i][j], 간선의 capacity 는 무한대(순방향)
    for (int i = 0; i < M; i++){
        for (int j = MAX_N; j < MAX_N + N; j++){
            cin >> cost[i][j];
            cost[j][i] = -cost[i][j]; // 역방향 간선의 비용은 순방향의 음수
            cap[i][j] = INF; // 순방향 간선만 용량이 1 이상
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }

    int result = 0;
    while (true){
        int prev[MAX_V], dist[MAX_V];
        bool inQ[MAX_V] = { 0 };
        queue<int> Q;

        fill(prev, prev + MAX_V, -1);
        fill(dist, dist + MAX_V, INF);

        dist[S] = 0;
        inQ[S] = true;
        Q.push(S);

        while (!Q.empty()){
            // 큐에서 꺼냄
            int cur = Q.front();
            Q.pop();
            inQ[cur] = false;

            for (int nxt : adj[cur]){
                // 최단경로를 찾는 중, cap 과 flow 도 같이 고려해주면서 흘려야함
                if (cap[cur][nxt] - flow[cur][nxt] > 0 && dist[nxt] > dist[cur] + cost[cur][nxt]){
                    dist[nxt] = dist[cur] + cost[cur][nxt];
                    prev[nxt] = cur;
                    // 큐에 들어있지 않다면 추가해줌
                    if (!inQ[nxt]){
                        Q.push(nxt);
                        inQ[nxt] = true;
                    }
                }
            }
        }
        // 더 이상 흘릴 유량이 없다면 탈출함
        if (prev[E] == -1) break;

        // 경로 상에서 가장 잔여가 작은 간선을 찾아 최대 흘릴 수 있는 flow 를 찾음
        int curFlow = INF;
        for (int i = E; i != S; i = prev[i]){
            curFlow = min(curFlow, cap[prev[i]][i] - flow[prev[i]][i]);
        }

        // 경로 상의 모든 간선에 curFlow 만큼의 유량을 흘림, 역방향까지 고려해주면서
        for (int i = E; i != S; i = prev[i]){
            // 정답 = 책의 권수 (= 흘리는 유량) * 배송비 (= 간선의 cost[prev[i]][i])
            result += curFlow * cost[prev[i]][i];
            flow[prev[i]][i] += curFlow;
            flow[i][prev[i]] -= curFlow;
        }
    }

    cout << result << endl;
    return 0;
}