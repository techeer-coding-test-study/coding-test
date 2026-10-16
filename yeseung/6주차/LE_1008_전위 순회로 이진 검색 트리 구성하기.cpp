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

void createNode(TreeNode* head, int num){
    TreeNode* temp = head;
    while(true){
        if(temp -> val > num){
            if(temp -> left == nullptr){
                temp -> left = new TreeNode(num);
                return;
            }
            else
                temp = temp -> left;
        }
        else{
            if(temp -> right == nullptr){
                temp -> right = new TreeNode(num);
                return;
            }
            else
                temp = temp -> right;
        }
       
    }
}

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* head = new TreeNode(preorder[0]);
        for(int i = 1; i< preorder.size();i++){
            createNode(head, preorder[i]);
        }
        return head;
    }
};
