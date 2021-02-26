#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("boards.txt");ofstream file_out("boards.txt")
#define f first
#define s second
#define double long double
#define db double
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
const int MOD = 987654321;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 3030;
const int MAXR = 2e5 + 10;
vector<pair<pdd, pdd>> pa, pb;
int a, b;

int ccw(pdd p1, pdd p2, pdd p3) {
	db t1 = p1.f * p2.s + p2.f * p3.s + p3.f * p1.s;
	db t2 = p1.s * p2.f + p2.s * p3.f + p3.s * p1.f;
	if (abs(t1 - t2) < 1e-6) return 0;
	return t1>t2 ? 1 : -1;
}

int segint(pdd p1, pdd p2, pdd p3, pdd p4) {
	int r1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int r2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	if (r1 == 0 && r2 == 0) {
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);
		return p3 <= p2 && p1 <= p4;
	}
		
	return r1 <= 0 && r2 <= 0;
}

db dist(pdd p1, pdd p2) {
	db dx = p1.f-p2.f, dy = p1.s-p2.s;
	return sqrt(dx*dx+dy*dy);
}

pdd getc(db m, db n, pdd p) {
	db x = (p.f+p.s*m-n*m)/(m*m+1);
	db y = x*m+n;
	return {x, y};
}

db dper(pdd p, db m, db n) {
	return abs(m*p.f-p.s+n)/sqrt(m*m+1);
}
db f(pdd p1, pdd p2, pdd p3, pdd p4) {
	db ret = (db)INF, m1, n1, m2, n2;
	bool f1, f2; f1 = f2 = false;
	pdd pk1, pk2, pk3, pk4;

	if (p1.f == p2.f) pk3 = {p1.f, p3.s}, pk4 = {p1.f, p4.s}, f1 = true;
	else if (p1.s == p2.s) pk3 = {p3.f, p1.s}, pk4 = {p4.f, p1.s}, f1 = true;
	else {
		m1 = (p2.s-p1.s)/(p2.f-p1.f);
		n1 = -m1*p1.f+p1.s;
	}
	if (p3.f == p4.f) pk1 = {p3.f, p1.s}, pk2 = {p3.f, p2.s}, f2 = true;
	else if (p3.s == p4.s) pk1 = {p1.f, p3.s}, pk2 = {p2.f, p3.s}, f2 = true;
	else {
		m2 = (p4.s-p3.s)/(p4.f-p3.f);
		n2 = -m2*p3.f+p3.s;
	}

	
	if (!f1) pk3 = getc(m1, n1, p3), pk4 = getc(m1, n1, p4);
	if (segint(p3, pk3, p1, p2)) ret = min(ret, dper(p3, m1, n1));
	else ret = min(ret, min(dist(p3, p1), dist(p3, p2)));
		
	if (segint(p4, pk4, p1, p2)) ret = min(ret, dper(p4, m1, n1));
	else ret = min(ret, min(dist(p4, p1), dist(p4, p2)));
	
	
	if(!f2) pk1 = getc(m2, n2, p1), pk2 = getc(m2, n2, p2);
	if (segint(p1, pk1, p3, p4)) ret = min(ret, dper(p1, m2, n2));
	else ret = min(ret, min(dist(p1, p3), dist(p1, p4)));
		
	if (segint(p2, pk2, p3, p4)) ret = min(ret, dper(p2, m2, n2));
	else ret = min(ret, min(dist(p2, p3), dist(p2, p4)));

	return ret;
}
int main() {
	fio();

	cin >> a >> b;
	pa.resize(a), pb.resize(b);
	for (int i = 0; i < a; i++) 
		cin >> pa[i].f.f >> pa[i].f.s >> pa[i].s.f >> pa[i].s.s;
	for (int i = 0; i < b; i++) 
		cin >> pb[i].f.f >> pb[i].f.s >> pb[i].s.f >> pb[i].s.s;
	
	db ans = (db)INF;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			ans = min(ans, f(pa[i].f, pa[i].s, pb[j].f, pb[j].s));
		}
	}

	printf("%.10LF\n", ans);
	return 0;
}

