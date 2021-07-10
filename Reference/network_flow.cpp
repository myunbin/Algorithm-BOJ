const int MAXN = 222;
int n, m, s, t, cap[MAXN][MAXN], flw[MAXN][MAXN];

void network_flow() {
    int ans = 0;
    while (1) {
        int prv[MAXN];
        memset(prv, -1, sizeof(prv));

        bool vst[MAXN] = {0};
        queue<int> q;

        q.push(s);
        vst[s] = 1;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int nxt = 0; nxt < MAXN; nxt++) {
                if (nxt == cur || vst[nxt]) continue;
                if (cap[cur][nxt]-flw[cur][nxt] > 0) {
                    q.push(nxt);
                    vst[nxt] = 1;
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

        ans += f;
    }

    cout << ans << endl;
}
