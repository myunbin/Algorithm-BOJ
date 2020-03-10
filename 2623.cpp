#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 1001;

int N, M, inDegree[MAX];
vector<int> adj[MAX];

void topoSort(){
    int result[MAX];
    queue<int> Q;

    for (int i = 1; i <= N; i++){
        if (inDegree[i] == 0) Q.push(i);
    }

    for (int i = 1; i <= N; i++){
        if (Q.empty()){
            cout << "0" << endl;
            return;
        }

        int cur = Q.front();
        Q.pop();

        result[i] = cur;
        for (int nxt : adj[cur]){
            if (--inDegree[nxt] == 0){
                Q.push(nxt);
            }
        }
    }

    for (int i = 1; i <= N; i++){
        cout << result[i] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int k, from, to;
        cin >> k;
        if (k == 0) continue;

        cin >> from;
        for (int i = 1; i < k; i++){
            cin >> to;
            inDegree[to]++;
            adj[from].push_back(to);
            from = to;
        }
    }

    topoSort();

    return 0;
}