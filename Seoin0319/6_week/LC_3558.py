from collections import deque

class Solution:
    def assignEdgeWeights(self, edges):
        MOD = 10**9 + 7
        n = len(edges) + 1

        graph = [[] for _ in range(n + 1)]

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        queue = deque([(1, 0)])
        visited = [False] * (n + 1)
        visited[1] = True
        max_depth = 0

        while queue:
            node, depth = queue.popleft()
            max_depth = max(max_depth, depth)

            for nxt in graph[node]:
                if not visited[nxt]:
                    visited[nxt] = True
                    queue.append((nxt, depth + 1))

        return pow(2, max_depth - 1, MOD)