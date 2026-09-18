#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(int N, int number) {
  if (N == number) return 1;

  // dp[i]: N을 i번 사용해서 만들 수 있는 수 집합
  vector<unordered_set<int>> dp(8 + 1);

  for (int i = 1; i <= 8; i++) {
    // 1. N을 i번 이어붙인 수 생성 (5, 55, 555)
    int continuousNum = 0;
    for (int j = 0; j < i; j++) {
      continuousNum = continuousNum * 10 + N;
    }
    dp[i].insert(continuousNum);

    // 2. 사칙연산 조합
    // k개 집합 : i-k개 집합
    for (int k = 1; k < i; k++) {
      for (int a : dp[k]) {
        for (int b : dp[i - k]) {
          dp[i].insert(a + b);
          dp[i].insert(a - b);
          dp[i].insert(a * b);
          if (b != 0) {
            dp[i].insert(a / b);
          }
        }
      }
    }

    // 목표 숫자 포함되어 있으면 반환
    if (dp[i].count(number)) {
      return i;
    }
  }

  return -1;
}