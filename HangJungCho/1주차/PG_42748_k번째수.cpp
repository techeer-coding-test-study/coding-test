#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i =0;i<commands.size();i++){
        int start = commands[i][0];
        int end = commands[i][1];
        int ans = commands[i][2];
        
        vector<int> A;
        for(int j = start-1;j<=end-1;j++){
            A.push_back(array[j]);
        }
        sort(A.begin(),A.end());
        answer.push_back(A[ans-1]);
    }
    return answer;
}