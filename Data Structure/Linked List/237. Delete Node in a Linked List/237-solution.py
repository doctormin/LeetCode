# Definition for singly-linked list.
'''
    此题的特殊之处在于没有给NODE之前的节点，所以我们只能采取特殊方法：
    node.val = node.next.val
    node.next  = node.next.next
'''
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val  = node.next.val
        node.next = node.next.next