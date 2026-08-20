#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> numbers, int target) {
    int count = 0;
    
    stack<pair<int, int>> st;
    
    st.push({0,0});
    
    while(!st.empty()) {
        pair<int, int> current = st.top();
        st.pop();
        
        int idx = current.first;
        int sum = current.second;
        
        if (idx == numbers.size()) {
            if (sum == target) {
                count += 1;
            }
            continue;
        }
        
        st.push({idx + 1, sum + numbers[idx]});
        st.push({idx + 1, sum - numbers[idx]});
    }
    
    return count;
}