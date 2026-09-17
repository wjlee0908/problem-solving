#include <functional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
  // 최소 힙
  priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(),
                                                    scoville.end());

  int count = 0;

  while (pq.size() >= 2 && pq.top() < K) {
    int first = pq.top();
    pq.pop();

    int second = pq.top();
    pq.pop();

    int mixed = first + (second * 2);
    pq.push(mixed);
    count += 1;
  }

  if (pq.top() < K) {
    return -1;
  }

  return count;
}