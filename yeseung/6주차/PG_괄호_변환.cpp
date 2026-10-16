#include <bits/stdc++.h>

using namespace std;

string func1(string& s){
    
    if(s.empty())
        return "";
    
    int left_count = 0;
    int right_count = 0;
    int index = 0;
    bool u_correct = true;
    
    
    do{
        if(s[index++] == '(')
            left_count++;
        else
            right_count++;    
        
        if(right_count>left_count)
            u_correct = false;
    }
    while(left_count != right_count);
    
    
    string u = s.substr(0, index);
    string v = s.substr(index);
    
    if(u_correct){
        return u + func1(v);
        
    }
    else{
        string result = "(";
        result += func1(v);
        result += ")";
        
        for(int i = 1; i < index - 1; i++){
            if(u[i] == '(')
                result += ')';
            else
                result += '(';
        }
        
        
        return  result;
    }

    
    
}
string solution(string p) {
    string answer = func1(p);
    return answer;
}
