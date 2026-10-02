#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    vector<string> num = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int index;
    for(int i = 0; i< num.size(); i++){
        while((index = s.find(num[i])) != string::npos){
            s.replace(index, num[i].size(),to_string(i));
        }
    }
    int answer = stoi(s);
    return answer;
}
