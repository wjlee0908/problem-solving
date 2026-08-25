## 문제 링크

- [여행경로](https://school.programmers.co.kr/learn/courses/30/lessons/43164)

## 핵심 아이디어

- 선택 case 찾기, 수형도 => DFS
- 먼저 탐색한 게 정답이 아닐 수 있음 => 백트래킹
  - 스택에 현 상태 저장

## Note

- 백트래킹
  - 재귀로 깊이 들어간 후 복구하는 과정 구현하거나
  - 스택에 현 상태 (visited 배열, 누적 경로 등) 저장해서 구현
- vector에 값 추가
  - `path.push_back(current)`
- 스택에 struct 추가
  ```
  State nextState = cur;
  nextState.path.push_back("ABC");
  stk.push(nextState);
  ```
