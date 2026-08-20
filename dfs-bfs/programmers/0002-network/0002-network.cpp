#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n, vector<vector<int>> computers) {    
    int count = 0;
    vector<bool> visited(n, false);
    
    // (idx)
    stack<int> st;
    
    for(int i = 0; i < n; i++) {
        // root 순회
        if(visited[i]) continue;
        count += 1;
        
        st.push(i);
        
        // dfs
        while(!st.empty()) {
            int cur = st.top();
            st.pop();

            for(int j = 0; j < n; j++) {
                if (j == cur) continue;
                
                if (computers[cur][j] == 1 && !visited[j]) {
                    st.push(j);
                    visited[j] = true;
                }
            }
        }
    }
    
    return count;
}