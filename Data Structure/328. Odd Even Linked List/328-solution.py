# https://leetcode.com/problems/odd-even-linked-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        ptr_odd = head
        odd_head = ptr_odd
        ptr_even = head.next
        even_head = ptr_even
        node = head.next.next
        odd_flag = True
        while not node:
            if odd_flag:
                odd_flag = False
                ptr_odd.next = node
                ptr_odd = ptr_odd.next
            else:
                odd_flag = True
                ptr_even.next = node
                ptr_even= ptr_even.next
            node = node.next
        ptr_odd.next = even_head
        return head
