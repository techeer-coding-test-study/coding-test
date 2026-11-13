#include <bits/stdc++.h>

using namespace std;

int solution(int n, int k, vector<int> enemy) {

    int enemy_len = enemy.size();
    priority_queue<int> q;
    for(int i = 0; i<enemy_len;i++){
        n -= enemy[i];
        q.push(enemy[i]);
        if(n < 0){
            if(k > 0){
                n += q.top();
                q.pop();
                k--;
            }
            else
                return i;
        }
    }
    return enemy_len;
}
