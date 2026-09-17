## 문제 링크

- [K번째수](https://school.programmers.co.kr/learn/courses/30/lessons/42748)

## 핵심 아이디어

- 배열 자르기 + 정렬하기
  - 슬라이싱 + `sort()`
  - 시간복잡도 `O(NlogN)`

## Note

- 배열 슬라이싱
  - `vector<int> sorted(array.begin() + start, array.begin() + end + 1);`
