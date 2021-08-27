struct fwt {
    // 1-indexed!
    vector<int> tr;
    void rst(int n) {
        tr.assign(n+1, 0);
    }
    void upd(int i, int v) {
        for (; i < tr.size(); i += (i&-i)) tr[i] += v;
    }
    int qry(int r) { //[1,r]
        int sum = 0;
        for (; r; r -= (r&(-r))) sum += tr[r];
        return sum;
    }
    int qry(int l, int r) { //[l, r]
        if(l == 0) return qry(r);
        return qry(r) - qry(l-1);
    }
};
