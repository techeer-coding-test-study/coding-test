/*
기본접근
중복이 될 수 있으므로 unordered_multiset을 활용하여 조회한다.
선수 목록을 1개씩 받아와서 완주목록에서 조회후 있으면 제거, 없을경우 return
*/

#include <string>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_multiset<string> Myset(completion.begin(), completion.end());
    for(int i=0;i<participant.size();i++){
        auto it = Myset.find(participant[i]);
        if (it != Myset.end()) { Myset.erase(it);}
        else
            return participant[i];
    }
}