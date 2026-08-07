#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    const int MAX_N = 200;
    
    int count = 0;
    int visited[MAX_N] = {false};
    
    // (idx)
    stack<int> st;
    
    // root 순회
    for(int i = 0; i < n; i++) {
        if(visited[i]) continue;
        count += 1;
        
        st.push(i);
        
        // 연결된 노드 dfs
        while(!st.empty()) {
            int cur = st.top();
            st.pop();

            visited[cur] = true;
            
            for(int j = 0; j < n; j++) {
                if (j == cur) continue;
                
                if (computers[cur][j] == 1 && !visited[j]) {
                    st.push(j);
                }
            }
        }
    }
    
    return count;
}