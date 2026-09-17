#include <stack>
#include <string>

using namespace std;

bool solution(string s) {
  stack<char> stk;

  for (char cur : s) {
    switch (cur) {
      case '(':
        stk.push(cur);
        break;
      case ')':
        if (stk.empty()) {
          return false;
        }

        stk.pop();
        break;
    }
  }

  return stk.size() == 0;
}