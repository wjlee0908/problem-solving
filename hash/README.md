# Hash

- `unordered_set<T>`: Hash Set. 중복 X 집합. python set과 동일
  - ` s.insert(10)`
  - `if(s.find(15) != s.end()) cout << "15 in s\n";`
- `unordered_multiset<T>`: 중복 O 집합
  - `.erase(value)` 할 때 중복값 모두 삭제되니 유의
  - `.erase(ms.find(value))`
- `unordered_map<T1, T2>`: Hash Table;
  - `m["hi"] = 123;`
