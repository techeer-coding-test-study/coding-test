#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> s;
    for(int i = 0; i<choices.size();i++){
        s[survey[i][0]] -= choices[i] - 4;
    }
    
    answer += (s['R'] >= s['T'])? 'R': 'T';
    answer += (s['C'] >= s['F'])? 'C': 'F';
    answer += (s['J'] >= s['M'])? 'J': 'M';
    answer += (s['A'] >= s['N'])? 'A': 'N';
    return answer;
}
