int mf() {
    int ret = 0;
    while (1) {
        memset(prv, -1, sizeof(prv));
        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int nxt : adj[cur]) {
                if (cap[cur][nxt]-flw[cur][nxt] > 0 && prv[nxt] == -1) {
                    q.push(nxt);
                    prv[nxt] = cur;
                }
            }
        }
        if (prv[t] == -1) break;
        int f = INF;

        for (int i = t; i != s; i = prv[i]) {
            f = min(f, cap[prv[i]][i]-flw[prv[i]][i]);
        }

        for (int i = t; i != s; i = prv[i]) {
            flw[prv[i]][i] += f;
            flw[i][prv[i]] -= f;
        }

        ret += f;
    }
    return ret;
}
