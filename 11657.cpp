#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 1000000000;
struct Edge {
    int from;
    int to;
    int cost;
};

int dist[501];
int N, M;
int main(){
    int T;
    scanf("%d %d", &N, &M);
    vector<Edge> a(M);

    for (int i = 0; i < M; i++){
        scanf("%d %d %d", &a[i].from, &a[i].to, &a[i].cost);
    }
    fill(dist, dist + N + 1, INF);
    bool minusCycle = false;
    dist[1] = 0;

    for (int i = 1; i <= N; i++){
        for (int j = 0; j < M; j++){
            int from = a[j].from;
            int to = a[j].to;
            int cost = a[j].cost;

            if (dist[from] != INF && dist[to] > dist[from] + cost){
                dist[to] = dist[from] + cost;
                if (i == N){
                    minusCycle = true;
                }
            }
        }
    }

    if (minusCycle){
        puts("-1");
        return 0;
    }

    for (int i = 2; i <= N; i++){
        if (dist[i] == INF) dist[i] = -1;
        printf("%d\n", dist[i]);
    }
    return 0;
}