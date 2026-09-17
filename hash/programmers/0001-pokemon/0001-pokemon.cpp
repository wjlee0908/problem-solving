#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(vector<int> nums) {
  unordered_set<int> pokemons = unordered_set<int>(nums.begin(), nums.end());

  return min({pokemons.size(), nums.size() / 2});
}