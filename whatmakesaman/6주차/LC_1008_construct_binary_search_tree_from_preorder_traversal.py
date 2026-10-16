# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, preorder: list[int]) -> TreeNode | None:

            if not preorder:
                return None
            root=TreeNode(preorder[0])
            left=[x for x in preorder[1:] if x < preorder[0]]
            right=[x for x in preorder[1:] if x > preorder[0]]
            root.left=self.bstFromPreorder(left)
            root.right=self.bstFromPreorder(right)
            return root
             


            

        