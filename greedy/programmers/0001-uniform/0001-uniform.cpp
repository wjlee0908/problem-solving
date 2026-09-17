#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
  /** 학생별 체육복 수 */
  vector<int> students = vector<int>(n + 1, 1);

  for (int l : lost) {
    students[l] -= 1;
  }

  for (int r : reserve) {
    students[r] += 1;
  }

  for (int i = 1; i < students.size(); i++) {
    if (students[i] > 0) {
      continue;
    }

    if (students[i - 1] > 1) {
      students[i - 1] -= 1;
      students[i] += 1;
      continue;
    }

    if (i + 1 > n) {
      continue;
    }

    if (students[i + 1] > 1) {
      students[i + 1] -= 1;
      students[i] += 1;
    }
  }

  int count = 0;

  for (int i = 1; i < students.size(); i++) {
    if (students[i] > 0) {
      count += 1;
    }
  }

  return count;
}