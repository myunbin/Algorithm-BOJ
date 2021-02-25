int ccw(Point p1, Point p2, Point p3){
	ll t1 = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	ll t2 = p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	
	// t1-t2의 부호를 반환
	if(t1==t2) return 0;
	else return t1<t2 ? -1 : 1; 
}

// abs(t1-t2) 는 p1, p2, p3 가 만드는 평행사변형의 넓이를 나타낸다.
// 반시계: -1, 시계: 1, 한직선: 0
//https://www.acmicpc.net/blog/view/27
