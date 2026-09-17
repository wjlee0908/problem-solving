#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
  unordered_set<int> lengths;
  unordered_set<string> prefixes;

  sort(phone_book.begin(), phone_book.end());

  for (const string& phone : phone_book) {
    for (int l : lengths) {
      string prefix = phone.substr(0, l);

      if (prefixes.find(prefix) != prefixes.end()) {
        return false;
      }
    }

    lengths.insert(phone.length());
    prefixes.insert(phone);
  }

  return true;
}