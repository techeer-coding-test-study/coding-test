#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> number) {
    int count = 0;
    
    sort(number.begin(), number.end());
    
    
    for (int i = 0; i < number.size(); i++) {
        map<int, int> A;
        
        for (int z = i + 1; z < number.size(); z++) {
            A[number[z]]++;
        }
        // O(nlog_n)
        for (int j = i + 1; j < number.size(); j++) {
            A[number[j]]--;
            int a = number[i] + number[j];
            a = -a;
            
            auto it = A.find(a);
            if (it != A.end()) {
                if(number[j] <= it->first){
                    if (it->second > 0 ){
                        count += it->second;
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





*/