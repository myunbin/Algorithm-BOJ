#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
const int MAX = 5001;

int cnt, dfsN[MAX];
int SN[MAX], SCCnum;
vector<int> adj[MAX];
bool finished[MAX];
stack<int> S;
vector<vector<int>> SCC;

int DFS(int cur){
    dfsN[cur] = ++cnt;
    S.push(cur);

    int parent = dfsN[cur];
    for (int &nxt : adj[cur]){
        if (dfsN[nxt] == 0) parent = min(parent, DFS(nxt));
        else if (!finished[nxt]) parent = min(parent, dfsN[nxt]);
    }

    if (parent == dfsN[cur]) {
        vector<int> scc;
        while (true){
            int t = S.top();
            S.pop();
            scc.push_back(t);
            finished[t] = true;
            SN[t] = SCCnum;
            if (t == cur) break;
        }

        SCC.push_back(scc);
        SCCnum++;
    }

    return parent;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true){
        int V, E;
        cin >> V;
        if (V == 0) return 0;
        cin >> E;

        SCC.clear();
        while (!S.empty()) S.pop();
        for (int i = 0; i < V; i++) adj[i].clear();
        memset(dfsN, 0, sizeof(dfsN));
        memset(finished, false, sizeof(finished));
        memset(SN, 0, sizeof(SN));
        cnt = 0; SCCnum = 0;

        for (int i = 0; i < E; i++){
            int from, to;
            cin >> from >> to;
            adj[from - 1].push_back(to - 1);
        }

        for (int i = 0; i < V; i++){
            if (dfsN[i] == 0) DFS(i);
        }

        for (int i = 0; i < V; i++){
            for (int j : adj[i]){
                if (SN[i] != SN[j]){
                    SCC[SN[i]].clear();
                }
            }
        }

        for (int i = 0; i < SCCnum; i++) sort(SCC[i].begin(), SCC[i].end());
        sort(SCC.begin(), SCC.end());

        for (int i = 0; i < SCCnum; i++){
            if (!SCC[i].empty()){
                for (int j : SCC[i]){
                    cout << j + 1 << ' ';
                }
            }
        }
        cout << '\n';
    }
}