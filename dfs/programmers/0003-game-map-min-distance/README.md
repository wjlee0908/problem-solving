## 문제 링크

- [게임 맵 최단거리](https://school.programmers.co.kr/learn/courses/30/lessons/1844?language=cpp)

## 핵심 아이디어

- N \* M에서 최단거리 구하기 => BFS + visited (loop 방지)

## Note

- segmentation fault -> 배열 인덱스 범위 초과
- 인덱스 범위는 0 ~ n - 1이니 범위 검사도 nx > (n - 1) 형태
- 큐에 값 세 개 이상 저장 -> struct(Element) 정의
- maps - 지나간 칸에 +1을 하면서 distance를 저장하면 visited 배열 생성할 공간을 아끼고 큐에 넣을 값도 pair로 줄일 수 있다.
