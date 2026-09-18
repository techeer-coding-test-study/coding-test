#include <string>
#include <vector>

using namespace std;

// n: 목표 가운데 칸(2, 5, 8, 11), num: 현재 손가락 위치
int getDistance(int target, int cur) {
    // 1. 이미 같은 위치에 있는 경우
    if (target == cur) return 0;

    int dist = 0;

    // 2. 손가락이 가운데열 인 경우:
    if (cur == 2 || cur == 5 || cur == 8 || cur == 11) {
        while (cur != target) {
            if (cur < target) {
                cur += 3;
            } else {
                cur -= 3; 
            }
            dist++;
        }
        return dist;
    }

    // 3. 손가락이 좌우 열(1,3열)에 있는 경우:
    dist = 1;
    int aligned = cur;


    if (cur == 1 || cur == 4 || cur == 7 || cur == 10) {
        aligned = cur + 1;
    } else {
        aligned = cur - 1;
    }

    while (aligned != target) {
        if (aligned < target) {
            aligned += 3;
        } else {
            aligned -= 3;
        }
        dist++;
    }

    return dist;
}

string solution(vector<int> numbers, string hand) {
    string ans = "";
    vector<int> location = {10, 12}; // 10 = *, 12 = #

    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];

        if (num == 1 || num == 4 || num == 7) {
            ans += "L";
            location[0] = num;
        }
        else if (num == 3 || num == 6 || num == 9) {
            ans += "R";
            location[1] = num;
        }
        else { // 2, 5, 8, 0 (가운데 열)
            if (num == 0) {
                num = 11;
            }

            int a = getDistance(num, location[0]); // 왼손 거리
            int b = getDistance(num, location[1]); // 오른손 거리

            if (a > b) {
                ans += "R";
                location[1] = num;
            }
            else if (a < b) {
                ans += "L";
                location[0] = num;
            }
            else {
                if (hand == "left") {
                    ans += "L";
                    location[0] = num;
                } else {
                    ans += "R";
                    location[1] = num;
                }
            }
        }
    }
    return ans;
}

//시간복잡도 O(N)