#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
  int maxW = 0;
  int maxH = 0;

  for (const vector<int>& card : sizes) {
    // width: 두 변 중 긴 걸로 통일
    maxW = max(maxW, max(card[0], card[1]));

    // height: 두 변 중 짧은 걸로 통일
    maxH = max(maxH, min(card[0], card[1]));
  }

  return maxW * maxH;
}