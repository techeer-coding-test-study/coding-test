class Solution:
    def assignEdgeWeights(self, edges: List[List[int]]) -> int:
        

        n=len(edges)+1
        graph=[[] for _ in range(n+1)]

        for u,v in edges:
            graph[u].append(v)
            graph[v].append(u)

        depth=[-1]*(n+1)
        depth[1]=0
        q=deque([1])
        max_depth=0
        while q:
            node=q.popleft()
            max_depth=max(max_depth,depth[node])
            for nxt in graph[node]:
                if depth[nxt]==-1:
                    depth[nxt]=depth[node]+1
                    q.append(nxt)
        return pow(2, max_depth - 1, 10**9 + 7)