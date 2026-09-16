#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 1번부터 n번까지 인덱스 편의 및 양 끝 경계 처리를 위해 크기 n + 2 할당
    vector<int> student(n + 2, 1);

    for (int l : lost) student[l]--;
    for (int r : reserve) student[r]++;

    for (int i = 1; i <= n; i++) {
        if (student[i] == 0) {
            if (student[i - 1] == 2) {
                student[i - 1]--;
                student[i]++;
            } else if (student[i + 1] == 2) {
                student[i + 1]--;
                student[i]++;
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (student[i] >= 1) answer++;
    }

    return answer;
}