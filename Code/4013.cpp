#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 500010;

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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    int cash[MAX];
    bool hasRest[MAX] = { 0 };

    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int from, to;
        cin >> from >> to;
        adj[from - 1].push_back(to - 1);
    }

    for (int i = 0; i < N; i++){
        if (dfsN[i] == 0) DFS(i);
    }

    for (int i = 0; i < N; i++){
        cin >> cash[i];
    }

    //레스토랑
    int start, P;
    cin >> start >> P;
    start--;

    for (int i = 0; i < P; i++){
        int p;
        cin >> p;
        hasRest[p - 1] = true;
    }

    vector<int> sAdj[MAX];
    int sStart;
    int sCash[MAX] = { 0 };
    int sOutde[MAX] = { 0 };
    bool sHasRest[MAX] = { 0 };

    for (int i = 0; i < N; i++){
        int si = SN[i];
        sCash[si] += cash[i];
        if (hasRest[i]) sHasRest[si] = true;
        if (i == start) sStart = si;

        for (int j : adj[i]){
            int sj = SN[j];
            if (si == sj) continue;

            sAdj[si].push_back(sj);
            sOutde[sj]++;
        }
    }

    queue<int> Q;
    int sMax[MAX] = { 0 };
    bool sCal[MAX] = { 0 };
    for (int i = 0; i < SCC.size(); i++){
        sMax[i] = sCash[i];
        if (i == sStart) sCal[i] = true;
        if (sOutde[i] == 0) Q.push(i);
    }

    while (!Q.empty()){
        int cur = Q.front();
        Q.pop();
        for (int nxt : sAdj[cur]){
            if (sCal[cur]){
                sMax[nxt] = max(sMax[nxt], sMax[cur] + sCash[nxt]);
                sCal[nxt] = true;
            }
            if (--sOutde[nxt] == 0) Q.push(nxt);
        }
    }

    int ans = 0;
    for (int i = 0; i < SCC.size(); i++){
        if (sHasRest[i] && sCal[i])
            ans = max(ans, sMax[i]);
    }

    cout << ans << endl;
    return 0;
}
