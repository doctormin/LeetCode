#https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
'''
先进行dfs来用dic划分不同vertical layers， 然后对于每个layer内部进行排序，排序依据是(y, val)
'''
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
import collections
class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        dic = collections.defaultdict(list)
        self.min_x, self.max_x = float("inf"), -float("inf")
        def dfs(root, x, y):    
            self.min_x = min(self.min_x, x)
            self.max_x = max(self.max_x, x)
            dic[x].append((y, root.val))
            if root.left:  dfs(root.left,  x-1, y+1)
            if root.right: dfs(root.right, x+1, y+1)

        dfs(root, 0, 0)
        ans = []
        for i in range(self.min_x, self.max_x + 1):
            ans.append([j for i, j in sorted(dic[i], key=lambda x: (x[0], x[1]))])
        return ans


