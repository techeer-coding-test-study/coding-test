#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int answer = 0;
    int margin;
    
    int front = 0;
    int last = people.size()-1;
    
    while(front<=last){
        answer++;
        margin = limit - people[last];
        last--;
        if(margin>=people[front])
            front++;
    }
    return answer;
}
