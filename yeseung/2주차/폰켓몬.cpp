#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int lens = nums.size() / 2;
    unordered_set<int> x(nums.begin(),nums.end());
    int typecount = x.size();
    if(lens > typecount)
        return typecount;
    else
        return lens;
}
