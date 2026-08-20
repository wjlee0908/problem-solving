## 문제 링크

- [타겟 넘버](https://school.programmers.co.kr/learn/courses/30/lessons/43165?language=cpp)

## 핵심 아이디어

- 수형도(트리)를 그리며 모든 조합을 검사한다 => DFS
- 스택에 다음 인덱스와 지금까지의 sum을 쌓는다

## Note

- DFS에서 스택에는 현재 값 인덱스와 **누적값**을 pair로 넣는다
