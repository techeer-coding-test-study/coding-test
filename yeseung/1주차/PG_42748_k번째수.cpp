#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(int index = 0;index<commands.size(); ++index){
        int i = commands[index][0];
        int j = commands[index][1];
        int k = commands[index][2];
        
        vector<int> tmp(array.begin()+i-1, array.begin()+j);
        sort(tmp.begin(),tmp.end());
        
        answer.push_back(tmp[k-1]);
    }
    return answer;
}
