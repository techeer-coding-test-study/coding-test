#include <string>
#include <vector>

using namespace std;
string second(string answer){// 2단계 케이스 전부 적용해서 새 문자열 만들고 리턴
    string a = "";
    for(int i =0;i<answer.length();i++){
        if((answer[i] <= 122 && answer[i] >= 97) || answer[i] == 46 || answer[i] == 45 || answer[i] == 95 || (answer[i] <= 57 && answer[i] >= 48)){
            a.push_back(answer[i]);
        }
    }
    return a;
}

string third(string answer){
    string a = "";
    for(int i =0;i < answer.length();i++){
        if(answer[i] == answer[i+1] && answer[i] == 46){
            continue;
        }
        else{
            a.push_back(answer[i]);
        }
            
    }
    return a;
}

string four(string answer){
    string a = "";
    if(answer.back() == 46){
        answer.pop_back();
    }
    if(answer.front() == 46){
        a.append(answer,1,answer.size());
    }
    if(a != "")
        return a;
    return answer;
}

string five(string ans){
    if(ans == ""){
        return "a";
    }
    else
        return ans;
}

string six(string ans){
    string a = ans;
    while(a.length() >= 16){
        a.pop_back();
    }
    a = four(a);
    return a;
}

string seven(string ans){
    if(ans.size() < 3){
        while(ans.size() < 3){
            ans.push_back(ans.back());
        }
    }
    return ans;
}
string solution(string new_id) {

    string answer = new_id;
    for(int i =0; i<answer.length();i++){ // 대문자 -> 소문자
        if(answer[i] <= 90 && answer[i] >= 65){
            answer[i] += 32;
        }
    }
    answer = second(answer);
    answer = third(answer);
    answer = four(answer);
    answer = five(answer);
    answer = six(answer);
    answer = seven(answer);
    
    return answer;
}