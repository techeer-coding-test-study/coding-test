class Solution:
    def countDominantNodes(self, root):
        def dfs(node):
            # 반환값: (현재 서브트리의 최댓값, dominant 노드 수)
            if not node:
                return float("-inf"), 0

            left_max, left_count = dfs(node.left)
            right_max, right_count = dfs(node.right)

            subtree_max = max(node.val, left_max, right_max)

            # 내 값이 내 서브트리 최댓값과 같으면 dominant
            is_dominant = 1 if node.val == subtree_max else 0

            count = left_count + right_count + is_dominant

            return subtree_max, count

        return dfs(root)[1]