## 문제 링크

- [네트워크](https://school.programmers.co.kr/learn/courses/30/lessons/43162)

## 핵심 아이디어

- 간선으로 이어진 네트워크 -> 시작 노드가 루트인 일방향 트리로 표현 가능
  - 각 노드를 순회하며 그 노드를 시작으로 트리를 만든다
  - 방문했던 노드는 제외
- 트리 -> DFS로 순회 가능
- 루프 및 중복집계 방지 -> visited 배열

## Note
