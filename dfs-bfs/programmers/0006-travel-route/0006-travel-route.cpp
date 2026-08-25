#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int FROM = 0;
const int TO = 1;

struct State {
    string airport;
    vector<string> path;
    vector<bool> used;
};

// 정렬용 비교함수
bool compare(const vector<string> &a, const vector<string> &b) {
    return a[TO] > b[TO];
}

vector<string> solution(vector<vector<string>> tickets) {
    // tickets 도착지 알파벳 역순 정렬
    // 스택에 마지막에 담아야 먼저 탐색하기 때문
    sort(tickets.begin(), tickets.end(), compare);
    
    stack<State> stk;
    
    stk.push({ "ICN", {"ICN"}, vector<bool>(tickets.size(), false) });
    
    // DFS
    while(!stk.empty()) {
        State cur = stk.top();
        stk.pop();

        if(cur.path.size() >= tickets.size() + 1) {
            return cur.path;
        }
        
        for(int i = 0; i < tickets.size(); i++) {
            if(tickets[i][FROM] == cur.airport && !cur.used[i]) {
                State nextState = cur;
                
                nextState.airport = tickets[i][TO];
                nextState.path.push_back(tickets[i][TO]);
                nextState.used[i] = true;
                
                stk.push(nextState);
            }
        }
    }
    
    return {};
}