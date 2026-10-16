/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        vector<int> s;
        while(temp != nullptr){
            s.push_back(temp->val);
            temp = temp->next;
        }
        int max = 0;
        for(int i = 0; i < s.size();i++){
            int sum = s[i] + s[s.size()-1-i];
            if(sum > max)
            max = sum;
        }
        return max;
    }
};
