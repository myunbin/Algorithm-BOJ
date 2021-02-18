## Feedback
- **USACO, KOI, COCI 등 Olympiad 문제들 많이 풀어보기 - 주당 silver 1셋 정도**

### Graph

- <20531 인간관계> **components의 수를 union-find로 세고**, Stirling(+Bell) number는 재밌어 보이니까 한번 봐두자.
- cycle을 탐색하는 방법들 
  - dfs : graph의 모든 정점을 에지의 방향에 따라 순회하면서 백에지(back dege)가 있으면 cycle이 있다고 판단한다.
  - https://wogud6792.tistory.com/71 를 참고하자.
  - union-find : 더 편하지만 self-loop이 있으면 안되고, 무방향 graph에서 유용하게 쓰일 수 있음. (9466번 풀면서 몸으로 알았다.)
  - 위상정렬을 이용해도 쉽게 찾을 수 있다. queue를 빠져나오고도 indegree가 0인 원소가 존재한다면 걔는 cycle에 포함되는 애라는 것까지 알 수 있음. + directed graph 에서만 사용이 가능함. 

### Segment tree

- <17163 가희의 수열놀이> segment tree 응용. 스택을 써야한다는 발상, minRangeQuery, 수의 제한 등
- <9345 DVD> [l, r] 상에 l~r까지의 원소가 포함되어있어야한다는 것은 l<=k<=r 은 min(k) = l, max(k) = r 이라는 거
- <화성지도>와 같이 sweeping + segment tree는 단골.
- segment tree 응용 https://stonejjun.tistory.com/83 참고해서 seg-tree 응용하는 방법 좀 익혀보기.
  https://github.com/myunbin/algorithm-BOJ/blob/master/Code/2261.cpp
- <springborads>, <최대 증가 직사각형 집합> 같이 segment tree + dp 같은 느낌도 잘 기억해두자. sweeping 시발
  
### Sweeping

- plane sweeping 아직 많이 어려운거 같다. 3392, 2185 등 풀어보면서 연습하자. https://codedoc.tistory.com/421
- <2261 가장 가까운 두 점> 이거 sweeping + set 제대로 이해하고 분할정복으로 푸는 방법도 이해하기.

### DP

- 낯선 점화식을 도출하는거 연습하기.
- <2449 전구>, <1970 건배>, <3012 올바른 괄호 문자열> - i ~ j 에서 분할정복의 느낌으로 i ~ k, k+1 ~ j로 쪼개는 느낌
- <7812 중앙트리> tree dp 할 때 많이 느낀거 변화량에 집중해야할때도 있음.

### 기타
- sort할때 lambda 써서 편하게 처리할 수 있다. 문법이니까 알아두면 유용할 듯 https://hwan-shell.tistory.com/8
