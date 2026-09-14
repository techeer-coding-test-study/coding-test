#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

// 키패드 번호를 4x3 행렬의 (행, 열) 좌표로 변환하는 함수
pair<int, int> getPos(int num) {
    // 0은 11로 치환하여 맨 아래 가운데 칸 (3, 1)로 매핑
    if (num == 0) num = 11;
    
    // 1번부터 순서대로 번호를 매겼을 때 0-based 인덱스 기준:
    // row: (num - 1) / 3, col: (num - 1) % 3
    // 10 = '*', 11 = '0', 12 = '#'
    return {(num - 1) / 3, (num - 1) % 3};
}

// 두 위치 사이의 맨해튼 거리: |r1 - r2| + |c1 - c2|
int getDistance(int from, int to) {
    pair<int, int> p1 = getPos(from);
    pair<int, int> p2 = getPos(to);
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

string solution(vector<int> numbers, string hand) {
    string ans = "";
    int leftPos = 10;  // '*' 초기 위치 (3, 0)
    int rightPos = 12; // '#' 초기 위치 (3, 2)

    for (int num : numbers) {
        // 1. 왼손 전용 키패드
        if (num == 1 || num == 4 || num == 7) {
            ans += "L";
            leftPos = num;
        }
        // 2. 오른손 전용 키패드
        else if (num == 3 || num == 6 || num == 9) {
            ans += "R";
            rightPos = num;
        }
        // 3. 가운데 키패드 (2, 5, 8, 0)
        else {
            int dLeft = getDistance(leftPos, num);
            int dRight = getDistance(rightPos, num);

            if (dLeft < dRight) {
                ans += "L";
                leftPos = num;
            }
            else if (dRight < dLeft) {
                ans += "R";
                rightPos = num;
            }
            else { // 두 거리가 같을 때 주 손잡이 우선
                if (hand == "right") {
                    ans += "R";
                    rightPos = num;
                } else {
                    ans += "L";
                    leftPos = num;
                }
            }
        }
    }

    return ans;
}
//시간 복잡도 O(N)