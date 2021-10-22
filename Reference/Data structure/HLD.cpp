const int MAXN = 1010101;
// this case, tree size 10^5
// to modify, you need to modify size of tr 
struct Seg{
    int tr[1 << 18];
    int sz = 1 << 17;

    void upd(int x, int v){
        x |= sz; tr[x] = v;
        while(x >>= 1){
            tr[x] = max(tr[x<<1],tr[x<<1|1]);
        }
    }

    int qry(int l, int r){
        if (l > r) return -INF;
        l |= sz, r |= sz;
        int ret = 0;
        while(l <= r){
            if(l & 1) ret = max(ret, tr[l++]);
            if(~r & 1) ret = max(ret, tr[r--]);
            l >>= 1, r >>= 1;
        }
        return ret;
    }
} seg;

int sz[MAXN], dep[MAXN], par[MAXN], inn[MAXN], out[MAXN], top[MAXN];
vector<int> adj[MAXN], g[MAXN];
void dfs(int cur, int prv) {
    for (int nxt : adj[cur]) {
        if (nxt == prv) continue;
        g[cur].pb(nxt);
        dfs(nxt, cur);
    }
}
void dfs1(int cur) {
    sz[cur] = 1;
    for (int &nxt : g[cur]) {
        dep[nxt] = dep[cur]+1;
        par[nxt] = cur;
        dfs1(nxt);
        sz[cur] += sz[nxt];
        if (sz[nxt] > sz[g[cur][0]]) swap(nxt, g[cur][0]);
    }
}

int vst = 0;
void dfs2(int cur) {
    inn[cur] = ++vst;
    for (int nxt : g[cur]) {
        top[nxt] = nxt==g[cur][0]?top[cur]:nxt;
        dfs2(nxt);
    }
    out[cur] = vst;
}

//vector<pii> ed;
//update
void upd(int x, int y) {
    seg.upd(inn[x], y);
    // enable below and vector<pii>ed if range query based on edge.
//    auto [u, v] = ed[x];
//    if (dep[u] > dep[v]) swap(u, v);
//    seg.upd(inn[v], y);
}

//query [a, b]
//returns sum of [a, b] (node)
int qry(int a, int b) {
    int ret = 0;
    while (top[a] != top[b]) {
        if (dep[top[a]] < dep[top[b]]) swap(a, b);
        ret = max(ret, seg.qry(inn[top[a]], inn[a]));
        a = par[top[a]];
    }

    if (dep[a] > dep[b]) swap(a, b);
    //if range query of edges, fix below code (inn[a]->inn[a]+1) 
    ret = max(ret, seg.qry(inn[a], inn[b]));
    return ret;
}
