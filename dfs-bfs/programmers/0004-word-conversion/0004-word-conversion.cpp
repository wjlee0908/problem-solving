#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    vector<bool> visited = vector<bool>(words.size(), false);
    
    // word, count
    queue<pair<string, int>> q;
    q.push({begin, 0});
    
    // BFS
    while(!q.empty()) {
        pair<string, int> current = q.front();
        q.pop();
        
        string currentWord = current.first;
        int count = current.second;
        
        // 변경 가능하면 push
        for (int i = 0; i < words.size(); i++) {
            int diffCount = 0;
            
            for (int j = 0; j < words[i].length(); j++) {
                if (currentWord[j] != words[i][j]) {
                   diffCount += 1;
                }
            }
            
            if (!visited[i] && diffCount == 1) {
                if (words[i] == target) {
                    return count + 1;
                }
                
                q.push({words[i], count + 1});
                visited[i] = true;
            }
        }
    }
    
    return 0;
}