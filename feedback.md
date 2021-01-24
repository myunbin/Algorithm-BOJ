## 문제를 풀면서 막혔던 점, 공부해야할 점들을 적는 곳입니다.

- <20531 인간관계> components의 수를 union-find로 세고, Stirling(+Bell) number는 재밌어 보이니까 한번 봐두자.
- <16566 카드게임> segment tree로 이미 사용한 원소들의 index를 관리할 수 있는 방법을 고민해보자.
- <2820 자동차 공장> lazy propagation을 사용하는 방법 정확하게 알아두고, dfs로 tree 새로 numbering 하는 방법을 통해 segment tree 구성이 가능하다는 점을 생각하자.
- cycle을 탐색하는 방법들 
  - dfs : graph의 모든 정점을 에지의 방향에 따라 순회하면서 백에지(back dege)가 있으면 cycle이 있다고 판단한다.
  - https://wogud6792.tistory.com/71 를 참고하자.
  - union-find : 더 편하지만 self-loop이 있으면 안되고, 무방향 graph에서 유용하게 쓰일 수 있음. (9466번 풀면서 몸으로 알았다.)
  - 위상정렬을 이용해도 쉽게 찾을 수 있다. queue를 빠져나오고도 indegree가 0인 원소가 존재한다면 걔는 cycle에 포함되는 애라는 것까지 알 수 있음. + directed graph 에서만 사용이 가능함. 
- <17163 가희의 수열놀이> segment tree를 응용하는 문제의 기본 같은 느낌. 일단 어떻게 풀지를 열심히 고민을 해보다가, 마지막에 "시간 안에 돌려면 세그트리를 써야겠네" 이런 느낌?
- <3830 교수님은 기다리지 않는다> **아직 못품** union-find를 변형해서 구현하는 방법, 루트를 정해놓고 dist를 계산하는 방법의 구현을 한번 배워보자.
---
### 21/01/03 전입 후 100솔!
---

- **USACO 문제처럼 사고력, 응용력이 주가 되는 문제들에 취약함.**
- segment tree 응용 https://stonejjun.tistory.com/83 참고해서 seg-tree 응용하는 방법 좀 익혀보기.
- fenwick tree 코드 이해했으니까 외워서 쓰도록하고, fenwick으로 lazy하는 방법도 나중을 위해 알아두기.
- <2261 가장 가까운 두 점> 이거 sweeping + set 제대로 이해하고 분할정복으로 푸는 방법도 이해하기.
  https://github.com/myunbin/algorithm-BOJ/blob/master/Code/2261.cpp
- <2449 전구>를 보고 다음 두 문제와의 유사성을 떠올리지 못했음. <1970 건배>, <3012 올바른 괄호 문자열>의 문제들에서 범위 내에서 가능한 범위를 쪼개서 확인하는 그런 느낌을 기억해두자. (시간복잡도는 보통 O(N^3)이 나오게 된다.)
- USACO silver 수준에서 prefix sum이랑 sweeping이 꽤 높은 빈도로 출제되는 것 같다. 둘 다 마스터하도록하자.
- plane sweeping 아직 많이 어려운거 같다. 3392, 2185 등 풀어보면서 연습하자. https://codedoc.tistory.com/421
