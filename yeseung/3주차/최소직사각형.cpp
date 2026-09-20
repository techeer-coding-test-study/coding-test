#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max1 = 0, max2 = 0;
    for(vector<int>& i :sizes){
        int large = max(i[0], i[1]);
        int small = min(i[0], i[1]);
        if(max1 < large)
            max1 = large;
        if(max2 < small)
            max2 = small;
    }
    int answer = max1*max2;
    return answer;
}
