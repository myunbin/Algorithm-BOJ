#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 810;
const int INF = (int)2e9;

struct Edge{
    int to, cap, flow;
    Edge *dual;
    Edge(): Edge(-1, 0){}
    Edge(int to1, int c1) : to(to1), cap(c1), flow(0), dual(nullptr){}
    int spare(){ return cap - flow; }
    void addFlow(int f1){
        flow += f1;
        dual -> flow -= f1;
    }
};

vector<Edge*> adj[MAX];

int maxFlow(int start, int end){
    int maxFlow = 0;
    while (true){
        int prev[MAX];
        Edge *path[MAX] = { 0 };
        fill(prev, prev + MAX, -1);
        queue<int> Q;
        Q.push(start);

        while (!Q.empty()){
            int cur = Q.front();
            Q.pop();
            for (Edge *e : adj[cur]){
                int nxt = e -> to;
                if (e -> spare() > 0 && prev[nxt] == -1){
                    Q.push(nxt);
                    prev[nxt] = cur;
                    path[nxt] = e;
                    if (nxt == end) break;
                }
            }
        }
        if (prev[end] == -1) break;

        int flow = INF;
        for (int i = end; i != start; i = prev[i]){
            flow = min(flow, path[i] -> spare());
        }
        for (int i = end; i != start; i = prev[i]){
            path[i] -> addFlow(flow);
        }
        maxFlow += flow;
    }
    return maxFlow;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, P;
    cin >> N >> P;

    for (int i = 0; i < N; i++){
        int from = i * 2, to = from + 1;
        Edge *e1 = new Edge(to, 1), *e2 = new Edge(from, 0);
        e1 -> dual = e2;
        e2 -> dual = e1;

        adj[from].push_back(e1);
        adj[to].push_back(e2);
    }

    for (int i = 0; i < P; i++){
        int from, to;
        cin >> from >> to;
        from--; to--;

        Edge *e1 = new Edge(to * 2, 1), *e2 = new Edge(from * 2 + 1, 0);
        Edge *e3 = new Edge(from * 2, 1), *e4 = new Edge(to * 2 + 1, 0);
        e1 -> dual = e2;
        e2 -> dual = e1;
        
        e3 -> dual = e4;
        e4 -> dual = e3;
        
        adj[from * 2 + 1].push_back(e1);
        adj[to * 2].push_back(e2);

        adj[to * 2 + 1].push_back(e3);
        adj[from * 2].push_back(e4);
    }

    cout << maxFlow(1, 2) << endl;
    return 0;
}