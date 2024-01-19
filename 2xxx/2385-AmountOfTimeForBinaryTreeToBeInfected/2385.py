# Definition for a binary tree node.
from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def convert_to_graph(self, root: Optional[TreeNode]) -> dict[int, List[int]]:
        adjs = {}
        queue = [root]

        while len(queue) > 0:
            u = queue[0]
            queue.pop(0)
            if u.val not in adjs.keys():
                adjs[u.val] = []
            for v in [u.left, u.right]:
                if v is not None:
                    queue.append(v)
                    if v.val not in adjs.keys():
                        adjs[v.val] = []
                    adjs[u.val].append(v.val)
                    adjs[v.val].append(u.val)

        return adjs

    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        adjs = self.convert_to_graph(root)
        distance = {start: 0}
        visited = {}
        
        queue = [start]
        visited[start] = False
        idx = 0
        ans = 0
        
        while idx < len(queue):
            u = queue[idx]
            idx += 1
            for v in adjs[u]:
                if not visited.get(v, False):
                    queue.append(v)
                    visited[v] = True
                    distance[v] = distance[u] + 1
                    ans = max(ans, distance[v])
                    
        return ans