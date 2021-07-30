// code from https://aahc.tistory.com/18

struct Fenwick {
    vector<int> fw;
 
    void reset(int n) {
        fw.assign(n+1, 0);
    }
 
    void update(int idx, int val) {
        for (; idx < (int)fw.size(); idx += (idx & -idx)) fw[idx] += val;
    }
 
    //finds [1, r] sum
    int query(int r) { 
        int sum = 0;
        for (; r; r -= (r&(-r))) sum += fw[r];
        return sum;
    }
 
    //finds [l, r] sum
    int query(int l, int r) {
        if(l == 0) return query(r);
        return query(r) - query(l-1);
    }
};


