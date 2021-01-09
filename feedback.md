## 문제를 풀면서 막혔던 점, 공부해야할 점들을 적는 곳입니다.
- 이거 문제들 내 코드랑 링크 걸 수 있나?

- <20531 인간관계> components의 수를 union-find로 세고, Stirling(+Bell) number는 재밌어 보이니까 한번 봐두자.
- <16566 카드게임> segment tree로 이미 사용한 원소들의 index를 관리할 수 있는 방법을 고민해보자.
- <2820 자동차 공장> lazy propagation을 사용하는 방법 정확하게 알아두고, dfs로 tree 새로 numbering 하는 방법을 통해 segment tree 구성이 가능하다는 점을 생각하자.
- cycle을 탐색하는 두 가지 방법 
  - dfs : graph의 모든 정점을 에지의 방향에 따라 순회하면서 백에지(back dege)가 있으면 cycle이 있다고 판단한다.
  - https://wogud6792.tistory.com/71 를 참고하자.
  - union-find : 더 편하지만 self-loop이 있으면 안되고, 무방향 graph에서 유용하게 쓰일 수 있음. (9466번 풀면서 몸으로 알았다.)
- <17163 가희의 수열놀이> segment tree를 응용하는 문제의 기본 같은 느낌인데, 이런 식으로 segment tree가 자료구조적으로 쓰이는 경우들을 잘알아두자.
