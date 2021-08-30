//https://justicehui.github.io/hard-algorithm/2020/03/24/effective-mcmf/
const int MAXN = 555; // max num of vertex
struct MCMF{
    int s, t; //source, sink
    struct Edge{ int v, c, d, dual; };
    vector<Edge> g[MAXN];
    void addEdge(int s, int e, int c, int d){ //start, end, capacity, cost
        g[s].push_back({e, c, d, (int)g[e].size()});
        g[e].push_back({s, 0, -d, (int)g[s].size()-1});
    }

    int dst[MAXN], inq[MAXN];
    bool spfa(){
        memset(dst, 0x3f, sizeof dst);
        memset(inq, 0, sizeof inq);
        queue<int> q; q.push(s); inq[s] = 1; dst[s] = 0;
        while(q.size()){
            int now = q.front(); q.pop(); inq[now] = 0;
            for(auto i : g[now]){
                if(i.c && dst[i.v] > dst[now] + i.d){
                    dst[i.v] = dst[now] + i.d;
                    if(!inq[i.v]) inq[i.v] = 1, q.push(i.v);
                }
            }
        }
        return dst[t] < 1e9;
    }

    int chk[MAXN], work[MAXN];
    bool update(){ //update shortest path DAG in O(V+E)
        int mn = 1e9;
        for(int i=0; i<MAXN; i++){
            if(!chk[i]) continue;
            for(auto j : g[i]){
                if(j.c && !chk[j.v]) mn = min(mn, dst[i] + j.d - dst[j.v]);
            }
        }
        if(mn >= 1e9) return 0;
        for(int i=0; i<MAXN; i++){
            if(!chk[i]) dst[i] += mn;
        }
        return 1;
    }

    int dfs(int now, int fl){
        chk[now] = 1;
        if(now == t) return fl;
        for(; work[now] < g[now].size(); work[now]++){
            auto &i = g[now][work[now]];
            if(!chk[i.v] && dst[i.v] == dst[now] + i.d && i.c){
                int ret = dfs(i.v, min(fl, i.c));
                if(ret){
                    i.c -= ret; g[i.v][i.dual].c += ret;
                    return ret;
                }
            }
        }
        return 0;
    }
    pii run(int _s, int _t){ //{cost, flow}
        s = _s, t = _t;
        int cst = 0, fl = 0;
        spfa();
        do{
            memset(chk, 0, sizeof chk);
            memset(work, 0, sizeof work);
            int now = 0;
            while(now = dfs(s, 1e9)){
                cst += dst[t] * now;
                fl += now;
                memset(chk, 0, sizeof chk);
            }
        }while(update());
        return pii(cst, fl);
    }
};
