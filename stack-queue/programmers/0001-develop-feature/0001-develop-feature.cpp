#include <cmath>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  queue<int> q;
  vector<int> deploy;

  // 1. 각 작업의 필요 일수를 큐에 삽입
  for (int i = 0; i < progresses.size(); i++) {
    int remain = 100 - progresses[i];
    int days = ceil((double)remain / speeds[i]);
    q.push(days);
  }

  // 2. 현재 작업보다 필요 일수 작은 작업 함께 배포
  while (!q.empty()) {
    int current = q.front();
    q.pop();

    int count = 1;

    while (!q.empty() && q.front() <= current) {
      q.pop();
      count += 1;
    }

    deploy.push_back(count);
  }

  return deploy;
}