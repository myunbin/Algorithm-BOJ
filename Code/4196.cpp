#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
const int MAX = 100010;

int cnt, dfsN[MAX];
int SN[MAX], SCCnum = 1;
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

    int T;
    cin >> T;

    while (T--){
        int V, E;
        cin >> V >> E;


        for (int i = 1; i <= V; i++) adj[i].clear();
        for (int i = 0; i < E; i++){
            int from, to;
            cin >> from >> to;
            adj[from].push_back(to);
        }

        memset(dfsN, 0, sizeof(dfsN));
        memset(finished, false, sizeof(finished));
        memset(SN, 0, sizeof(SN));
        cnt = 0; SCCnum = 0;

        for (int i = 1; i <= V; i++){
            if (dfsN[i] == 0) DFS(i);
        }

        int SccInDeg[MAX] = { 0 };
        for (int i = 1; i <= V; i++){
            for (int j : adj[i]){
                if (SN[i] != SN[j]){
                    SccInDeg[SN[j]]++;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < SCCnum; i++){
            if (SccInDeg[i] == 0) ans++;
        }

        cout << ans << '\n';
    }
    return 0;
}
