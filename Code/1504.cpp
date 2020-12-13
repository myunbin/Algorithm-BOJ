#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
int N, E;
int mustVertex_1, mustVertex_2;
int OneToV1, OneToV2, V1ToN, V2ToN, V1ToV2;
vector<pair<int, int>> adj[20002];
int dist[20002];
const int INT_MAX_ = 2000000000;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int startNode) {

    for (int i = 1; i <= N; i++) {
        dist[i] = INT_MAX_;
    }
    dist[startNode] = 0;

    pq.push(make_pair(0, startNode));
    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dist[now] < cost) continue;
        for (pair<int, int> next : adj[now]) {
            if (dist[next.second] > next.first + cost) {
                pq.push(make_pair(next.first + cost, next.second));
                dist[next.second] = next.first + cost;
            }
        }
    }

    return;
}

int main() {
    scanf("%d %d", &N, &E);

    int from, to, weight;
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &from, &to, &weight);
        adj[from].push_back(pair<int, int>(weight, to));
        adj[to].push_back(pair<int, int>(weight, from));
    }
    scanf("%d %d", &mustVertex_1, &mustVertex_2);

    dijkstra(1);

    OneToV1 = dist[mustVertex_1];
    OneToV2 = dist[mustVertex_2];
    if (OneToV1 >= INT_MAX_ && OneToV2 >= INT_MAX_) {
        cout << -1 << endl;
        return 0;
    }

    dijkstra(N);

    V1ToN = dist[mustVertex_1];
    V2ToN = dist[mustVertex_2];

    if (V1ToN >= INT_MAX_ && V2ToN >= INT_MAX_) {
        cout << -1 << endl;
        return 0;
    }

    dijkstra(mustVertex_1);

    V1ToV2 = dist[mustVertex_2];

    if (V1ToV2 >= INT_MAX_) {
        cout << -1 << endl;
        return 0;
    }

    int root1 = -1;
    int root2 = -1;
    if (!(OneToV1 >= INT_MAX_ || V1ToV2 >= INT_MAX_ || V2ToN >= INT_MAX_)) {
        root1 = OneToV1 + V1ToV2 + V2ToN;
    }
    if (!(OneToV2 >= INT_MAX_ || V1ToV2 >= INT_MAX_ || V1ToN >= INT_MAX_)) {
        root2 = OneToV2 + V1ToV2 + V1ToN;
    }

    if (root1 == -1 && root2 == -1) {
        cout << -1 << endl;
    }
    else {
        cout << min(root1, root2) << endl;
    }


    return 0;
}
