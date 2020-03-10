#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
const int MAX = 100000;

int cnt, dfsN[MAX];
int SN[MAX];
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
            SN[t] = SCC.size();
            if (t == cur) break;
        }

        SCC.push_back(scc);
    }
    return parent;
}

void Reset(){
    SCC.clear();
    while (!S.empty()) S.pop();
    for (int i = 0; i < MAX; i++) adj[i].clear();
    memset(dfsN, 0, sizeof(dfsN));
    memset(finished, false, sizeof(finished));
    memset(SN, 0, sizeof(SN));
    cnt = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--){
        int V, E;
        cin >> V >> E;

        Reset();
        for (int i = 0; i < E; i++){
            int from, to;
            cin >> from >> to;
            adj[from].push_back(to);
        }

        for (int i = 0; i < V; i++){
            if (dfsN[i] == 0) DFS(i);
        }

        int SccInDe[MAX] = { 0 };
        for (int i = 0; i < V; i++){
            for (int j : adj[i]){
                if (SN[i] != SN[j]){
                    SccInDe[SN[j]]++;
                }
            }
        }

        int res = 0;
        int res_idx;
        for (int i = 0; i < SCC.size(); i++){
            if (SccInDe[i] == 0){
                res++;
                res_idx = i;
            }
        }

        if (res == 1){
            sort(SCC[res_idx].begin(), SCC[res_idx].end());
            for (int x : SCC[res_idx]) cout << x << '\n';
        }
        else cout << "Confused" << '\n';
        cout << '\n';
    }
}