#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> number) {
    int count = 0;
    
    //일단 정렬
    sort(number.begin(), number.end());
    
    
    for (int i = 0; i < number.size(); i++) {// 문제에서 준 횟수 만큼 반복
        map<int, int> A; // key - value 쌍으로 저장 숫자-개수
        
        for (int z = i + 1; z < number.size(); z++) {
            A[number[z]]++;
        }
        // O(nlog_n)

        for (int j = i + 1; j < number.size(); j++) {
            A[number[j]]--; // number[j]는 현재 선택되었으므로 1개 제외
            int target = number[i] + number[j];
            target = -target;
            // 확정된 숫자 찾기
            
            auto it = A.find(target);
            if (it != A.end()) { // target이 map안에 있을경우
                if(number[j] <= it->first){ // 이 전에 고르지 않았던 수 일경우
                    /*
                    number를 정렬하였으므로 number[j]가 it->first보다 클 경우 it->first는 이전에
                    사용된 경우의 수 이다. 그러므로 중복해서 세는걸 방지하기위해 사용
                    */
                    if (it->second > 0 ){ // 개수가 1개 이상 있을때
                        count += it->second; // 카운트를 올린다.
                    }
                }              
            }
        }
        //O(nlog_n)
    }
    // O(n*nlogn)
    return count;
}

/*
기본 골자
숫자 2개를 고르면 나머지 1개가 확정이기 때문에 확정된 숫자가 있는지를 조회한다.
이때 map을 사용할 경우 시간복잡도가 O(1)이기 때문에 시간 복잡도 O(n^2)을 목표로한다.

실제 나온 결과 O(N^2logN)
이유 map을 사용할 경우 시간복잡도가 logN이기 때문 
*/

/*
LLM이 짜준 올바른 코드

#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> number) {
    int count = 0;
    int n = number.size();
    
    // 첫 번째 숫자 고정 (i)
    for (int i = 0; i < n - 2; i++) {
        // i 이후에 등장하는 숫자들의 빈도수를 기록할 해시 맵
        unordered_map<int, int> seen;
        
        // 두 번째 숫자(j)를 순회
        for (int j = i + 1; j < n; j++) {
            // 세 숫자의 합이 0이 되기 위해 필요한 세 번째 숫자
            int target = -(number[i] + number[j]);
            
            // 1. 필요한 숫자가 j 이전에 등장했는지 O(1)로 확인
            if (seen.find(target) != seen.end()) {
                count += seen[target];
            }
            
            // 2. 현재 j의 숫자를 맵에 등록 (다음 j 입장에서 과거의 원소가 됨)
            seen[number[j]]++;
        }
    }
    
    return count;
}


*/