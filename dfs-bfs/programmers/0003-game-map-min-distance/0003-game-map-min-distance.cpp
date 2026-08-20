#include <vector>
#include <queue>

using namespace std;

struct Element {
    int x;
    int y;
    int distance;
};

int solution(vector<vector<int> > maps)
{
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    
    int n = maps.size();
    int m = maps[0].size();
    
    queue<Element> q;
    vector<vector<bool>> visited = vector(n, vector(m, false));
    
    q.push({0, 0, 1});
    visited[0][0] = true;
    
    // BFS
    while(!q.empty()) {
        Element cur = q.front();
        q.pop();
        
        int x = cur.x;
        int y = cur.y;
        int distance = cur.distance;
                
        if (x == n - 1 && y == m - 1) {
            return distance;
        }
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nDistance = distance + 1;
            
            if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if (maps[nx][ny] != 1) continue;
            if (visited[nx][ny]) continue;
            
            visited[nx][ny] = true;
            q.push({nx, ny, nDistance});
        }
    }
    
    return -1;
}