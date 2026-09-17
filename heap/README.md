# Heap

## 시간 복잡도

- 우선순위 가장 높은 원소 탐색: O(1)
- 원소 추가: O(logN)
- 우선순위 가장 높은 원소 제거: O(logN)

## 예시 코드

```
#include <queue> // priority_queue
#include <functional>   // greater

// 최대 힙. 기본값
priority_queue<int> pq_max(
    arr.begin(), arr.end()
);

// 최소 힙 => greater
priority_queue<int, vector<int>, greater<int>> pq_min(
    arr.begin(), arr.end()
);
```
