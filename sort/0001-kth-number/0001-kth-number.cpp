#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
  vector<int> answer;

  for (const vector<int>& command : commands) {
    int i = command[0];
    int j = command[1];
    int k = command[2];

    // 배열 슬라이싱
    vector<int> sorted(array.begin() + i - 1, array.begin() + j);

    sort(sorted.begin(), sorted.end());

    answer.push_back(sorted[k - 1]);
  }

  return answer;
}