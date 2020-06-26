#https://leetcode.com/problems/sum-root-to-leaf-numbers/
# Definition for a binary tree node.
import copy

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if root == None:
            return 0
        Q = []
        Q.append([root, [root.val]])
        ans = 0
        while Q != []:
            node = Q.pop()
            val  = node[1]
            ver  = node[0]
            if ver.left != None:
                tmp = copy.deepcopy(val)
                tmp.append(ver.left.val)
                Q.append([ver.left, tmp])
            if ver.right != None:
                tmp = copy.deepcopy(val)
                tmp.append(ver.right.val)
                Q.append([ver.right, tmp])
            if ver.left == None and ver.right == None:
                val = list(map(str, val))
                ans += int(''.join(val))
        return ans
        