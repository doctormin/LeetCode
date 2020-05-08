# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
import queue
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        x_generation : int      = 0
        y_generation : int      = 0
        x_parent     : TreeNode = None
        y_parent     : TreeNode = None
        x_found      : bool     = False
        y_found      : bool     = False
        q = queue.Queue(0)
        q.put([root, 0, None])
        while(q.empty() != True):
            node = q.get()
            # check is it x or y
            if node[0].val == x:
                x_generation = node[1]
                x_parent     = node[2]
                #print("x_generation = ", x_generation)
                #print("x_parent = ", x_parent.val)
                x_found      = True
            if node[0].val == y:
                y_generation = node[1]
                y_parent     = node[2]
                #print("y_generation = ", y_generation)
                #print("y_parent = ", y_parent.val)
                y_found      = True
            if x_found and y_found:
                #print("find it!")
                return (x_generation == y_generation and x_parent != y_parent)
            if node[0].left != None:
                q.put([node[0].left, node[1]+1, node[0]])
            if node[0].right != None:
                q.put([node[0].right, node[1]+1, node[0]])  
        return False
# e.g.
root = TreeNode(1)
root.left = TreeNode(2)
root.left.left = TreeNode()
root.left.right = TreeNode(4)
root.right = TreeNode(3)
root.right.left = TreeNode()
root.right.right = TreeNode(5)

if __name__ == '__main__':
    s = Solution()
    print(s.isCousins(root, 4, 5))