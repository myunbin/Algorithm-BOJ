int ccw(Point p1, Point p2, Point p3){
	ll t1 = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	ll t2 = p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	
	// t1-t2의 부호를 반환
	if(t1==t2) return 0;
	else return t1<t2 ? -1 : 1; 
}

//v2
int ccw(pii p1, pii p2, pii p3) {
	int t1 = p1.f * p2.s + p2.f * p3.s + p3.f * p1.s;
	int t2 = p1.s * p2.f + p2.s * p3.f + p3.s * p1.f;
	return t1==t2 ? 0 : (t1-t2)/abs(t1-t2);
}

// segment intersect 세 점이 한 직선에 있는 경우가 있는 경우

int segment_intersect(Point p1, Point p2, Point p3, Point p4){
	int r1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int r2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	if (r1 == 0 && r2 == 0) {
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);
		
		return p3 <= p2 && p1 <= p4;
	}
		
	return r1 <= 0 && r2 <= 0;
}


// abs(t1-t2) 는 p1, p2, p3 가 만드는 평행사변형의 넓이를 나타낸다.
// 반시계: -1, 시계: 1, 한직선: 0
//https://www.acmicpc.net/blog/view/27
