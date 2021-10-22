struct fwt {
    // 1-indexed!
    vector<int> tr;
    void rst(int n) {
        tr.assign(n+1, 0);
    }
    void upd(int i, int v) {
        for (; i < tr.size(); i += (i&-i)) tr[i] += v;
    }
    ll qry(int r) { //[1,r]
        ll sum = 0;
        for (; r; r -= (r&(-r))) sum += 1LL*tr[r];
        return sum;
    }
    ll qry(int l, int r) { //[l, r]
        if(l == 0) return qry(r);
        return qry(r) - qry(l-1);
    }

    // find kth value
    // size of a tree should be 1<<ceil(log2(size))
    // let kth value be X, then kth(k) returns X+1 
    int kth(int k){
        int idx=0;
        int lg = 32-__builtin_clz((int)tr.size())-1;
        for(int i=lg;i>=0;i--){
            if(idx+(1<<i) <= (1<<lg)-1 && tr[idx+(1<<i)] < k){
                k-=tr[idx+(1<<i)];
                idx=idx+(1<<i);
            }
        }
        if(!k) return idx;
        return idx+1;
    }
};
