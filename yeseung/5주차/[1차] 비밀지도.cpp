#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i< n;i++){
        int temp = arr1[i] | arr2[i];
        string temps = "";
        for(int j = n-1;j >= 0; j--){
            if(temp>>j & 1)
                temps += '#';
            else
                temps += ' ';
        }
        answer.push_back(temps);
        }
    return answer;
}
