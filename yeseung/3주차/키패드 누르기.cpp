#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> numbers, string hand) {
    pair<int,int> s[10];
    for(int i = 0;i<3;i++){
        for(int j = 0; j < 3; j++){
            s[3*i+j+1] = {i,j};
        }
    }
    s[0] = {3,1};
    pair<int,int> left = {3,0};
    pair<int,int> right = {3,2};
    string answer = "";
    for(int i : numbers){
        if(i == 1 || i == 4 || i == 7){
            left = s[i];
            answer.push_back('L');
        }
        else if(i == 3 || i == 6 || i == 9){
            right = s[i];
            answer.push_back('R');
        }
        else if(i == 2 || i == 5 || i == 8 || i == 0){
            int r_dis = abs(right.first-s[i].first) + abs(right.second - s[i].second);
            int l_dis = abs(left.first-s[i].first) + abs(left.second - s[i].second);
            
            if(r_dis < l_dis){
                right = s[i];
                answer.push_back('R');
            }            
            else if(r_dis > l_dis){
                left = s[i];
                answer.push_back('L');
            }
            else{
                if(hand == "right"){
                    right = s[i];
                    answer.push_back('R');
                }
                else{
                    left = s[i];
                    answer.push_back('L');
                }
            }
        }
    }

    return answer;
}
