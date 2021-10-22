struct segtr{
    //0-indexed!
    vector<ll> tr, a;
    int n;
    void rst(int sz) {
        n = sz;
        tr.resize((n+1)<<2);
        a.resize(n+1);
    }
    void init(int nd, int le, int ri) {
        if (le==ri) {
            tr[nd] = a[le];
            return;
        }
        int md = le+ri>>1;
        init(nd<<1, le, md), init(nd<<1|1, md+1, ri);
        tr[nd] = tr[nd<<1]+tr[nd<<1|1];
    }
    void upd(int nd, int le, int ri, int i, ll v) {
        if (i<le || ri<i) return;
        if (le==ri) {
            tr[nd] = v;
            return;
        }
        int md = le+ri>>1;
        upd(nd<<1, le, md, i, v), upd(nd<<1|1, md+1, ri, i, v);
        tr[nd] = tr[nd<<1]+tr[nd<<1|1];
    }
    void upd(int i, ll v) {
        upd(1, 0, n-1, i, v);
    }
    ll qry(int nd, int le, int ri, int ql, int qr) {
        if (qr<le || ri<ql) return 0;
        if (ql<=le && ri<=qr) return tr[nd];
        int md = le+ri>>1;
        return qry(nd<<1, le, md, ql, qr)+qry(nd<<1|1, md+1, ri, ql, qr);
    }
    ll qry(int le, int ri) {
        return qry(1, 0, n-1, le, ri);
    }
};
