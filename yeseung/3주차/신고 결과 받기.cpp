#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    unordered_set<string> s(report.begin(),report.end());
    unordered_map<string, int> count;
    
    for(auto i : s){
        stringstream ss(i);
        string a, b;
        ss >> a >> b;
        count[b]++;
    }
    unordered_set<string> black;
    for(auto j : count){
        if(j.second >= k)
            black.insert(j.first);
    }
    
    unordered_map<string, int> mail;
    for(auto i : s){
        stringstream ss(i);
        string a, b;
        ss >> a >> b;
        if(black.count(b))
            mail[a]++;
    }
    
    vector<int> answer;
    for(auto i : id_list){
        answer.push_back(mail[i]);
    }
    
    
    return answer;
}
