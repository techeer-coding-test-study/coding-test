#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    int index = 0;
    int erased = 0;
    string answer = "";
    
    for(char c: number){
         while(!answer.empty() && erased < k  && answer.back() < c ){
                answer.pop_back();
                erased++;    
             }
        answer.push_back(c);
         }
        
    if(erased < k){
        answer.erase(answer.end()-(k-erased), answer.end());
    }
    
    
        
            
    return answer;
}
