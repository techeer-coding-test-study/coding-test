/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 TreeNode* createNode(vector<int>& nums){
    int max = -1;
    int max_index = 0;
    for(int i = 0; i< nums.size();i++){
        if(nums[i] > max){
            max = nums[i];
            max_index = i;
        }
    }
    TreeNode* temp =  new TreeNode(max);
    if(max_index > 0){
        vector<int> nums_left(nums.begin(), nums.begin()+ max_index);
        temp -> left = createNode(nums_left);
    }
        
    if(max_index < nums.size()-1){
        vector<int> nums_right(nums.begin()+max_index+1, nums.end());
        temp -> right = createNode(nums_right);
    }
    return temp;
 }



class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return createNode(nums);
    }

};
