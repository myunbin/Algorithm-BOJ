struct segmenttree{
	vector<ll> a, lz;
	segmenttree(int _sz) : a(_sz * 4 + 10), lz(_sz * 4 + 10) {}
	
	void push(int nd, int s, int e){ 
		a[nd] += (e-s+1) * lz[nd];
		if(s != e){
			lz[nd<<1] += lz[nd];
			lz[nd<<1|1] += lz[nd];
		}
		lz[nd] = 0;
	}
	
	void update(int nd, int s, int e, int l, int r, ll v){
		push(nd, s, e);
		if(e<l || r<s) return;
		if(l<=s && e<=r){
			lz[nd] += v;
			push(nd, s, e);
			return;
		}
		int m = s + e >> 1;
		update(nd<<1,s,m,l,r,v);
		update(nd<<1|1,m+1,e,l,r,v);
		a[nd] = a[nd<<1] + a[nd<<1|1];
	}
	
	ll query(int nd, int s, int e, int l, int r){
		push(nd, s, e);
		if(e<l || r<s) return;
		if(l<=s && e<=r) return a[nd];
		int m = s + e >> 1;
		return query(nd<<1,s,m,l,r) + query(nd<<1|1,m+1,e,l,r);
	}
}
