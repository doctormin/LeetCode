# https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
'''
 本题要求:给定一个BST的先根遍历结果（已知每个节点的val都唯一）,要求 
 1.构造出这颗树来 
 2.返回根节点
 
 算法思路：
 不断抓取根节点并递归操作：
 建立左子树
 建立右子树

 首先preorder[0]是整棵BST的根节点，那么其右边第一个比它小的值对应的节点就是它的左儿子
 第一个比它大的值对应的节点就是它的右儿子，对这两个点递归调用建树函数即可 
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        if not preorder: return None
        n = len(preorder)
        i = 1
        root = TreeNode(preorder[0])
        if n >= 2:
            while i < n:
                if preorder[i] > root.val: break
                i += 1
            # i 是右儿子
            root.left = self.bstFromPreorder(preorder[1:i])
            root.right = self.bstFromPreorder(preorder[i:])
        return root