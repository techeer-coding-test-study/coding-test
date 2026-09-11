#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int a = s.length();
    int top = 0;
    for (int i = 0; i < a; i++) {
        if (s[i] == '(') {
            top++;
        }
        else {
            top--;
            if (top == -1) {
                return false;
            }
        }
            
    }
    if(top != 0){
        return false;
    }
    return true;
}