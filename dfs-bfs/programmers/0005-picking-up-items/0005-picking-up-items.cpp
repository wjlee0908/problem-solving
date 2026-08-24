#include <string>
#include <vector>
#include <queue>

// #include <iostream>

using namespace std;

struct Element {
    int x;
    int y;
    int distance;
};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    const int MAX = 50;
    const int SCALE = 2;
    
    int board[MAX * 2 + 1][MAX * 2 + 1] = {0};
    
    // 보드 그리기
    for (int i=0; i < rectangle.size(); i++) {
        int lx = rectangle[i][0] * SCALE;
        int ly = rectangle[i][1] * SCALE;
        
        int rx = rectangle[i][2] * SCALE;
        int ry = rectangle[i][3] * SCALE;
        
        // line 그리기
        for (int jx=lx; jx<=rx; jx++) {
            board[jx][ly] = 1;
            board[jx][ry] = 1;
        }
        
        for (int jy=ly; jy<=ry; jy++) {
            board[lx][jy] = 1;
            board[rx][jy] = 1;
        }
    }
    
    for (int i=0; i < rectangle.size(); i++) {
        int lx = rectangle[i][0] * SCALE;
        int ly = rectangle[i][1] * SCALE;
        
        int rx = rectangle[i][2] * SCALE;
        int ry = rectangle[i][3] * SCALE;
        
        // 내부 0으로 채우기
        for (int jx = lx + 1; jx < rx; jx++) {
            for (int jy = ly + 1; jy < ry; jy++) {
                board[jx][jy] = 0;
            }
        }
    }

    // (test) 보드 출력
//     for (int i = 0; i < 20; i++) {
//         for (int j = 0; j < 20; j++) {
//             if (i == characterX * SCALE && j == characterY * SCALE) {
//                 cout << 'S';
//                 continue;
//             }
            
//             if (i == itemX * SCALE && j == itemY * SCALE) {
//                 cout << 'E';
//                 continue;
//             }
            
//             cout << board[i][j];
//         }
//         cout << '\n';
//     }
    
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, -1, 0, 1};
    
    // BFS
    queue<Element> q;
    bool visited[MAX * SCALE + 1][MAX * SCALE + 1] = {false};

    
    q.push({characterX * SCALE, characterY * SCALE, 0});
    visited[characterX * SCALE][characterY * SCALE] = true;
    
    while(!q.empty()) {
        Element cur = q.front();
        q.pop();
        
        // cout << cur.x << "," << cur.y << endl;
        
        int dirCount = cur.distance == 0 ? -1 : 0;

        queue<pair<int, int>> dirQueue;
        
        for (int i=0; i<4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if ( nx < 0 || nx > MAX * SCALE || ny < 0 || ny > MAX * SCALE ) {
                continue;
            }
            if (board[nx][ny] != 1) continue;
            if (visited[nx][ny]) continue;
            
            visited[nx][ny] = true;
            
            int nextDistance = cur.distance + 1;
            
            if(nx == itemX * SCALE && ny == itemY * SCALE) {
                return nextDistance / SCALE;
            }
            
            q.push({nx, ny, nextDistance});
        }
    }
    
    return 0;
}