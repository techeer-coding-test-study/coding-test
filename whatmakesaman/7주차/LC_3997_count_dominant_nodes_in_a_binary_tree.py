# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countDominantNodes(self, root: TreeNode | None) -> int:

       
        self.result=0

        def dfs(node):

            if node is None:
                return 0

            max_left=dfs(node.left)
            max_right=dfs(node.right)

            if node.val>=max_left and node.val>=max_right : 
                self.result+=1

            return max(node.val, max_left, max_right)
        
        dfs(root)
        return self.result

